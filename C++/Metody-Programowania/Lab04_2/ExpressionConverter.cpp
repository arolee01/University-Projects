#include "ExpressionConverter.h"
#include "Stack.h"
#include <cctype>

using namespace std;

string ExpressionConverter::removeSpaces(const string& expr) {
    string result;
    for (char c : expr) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}

bool ExpressionConverter::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
        c == '^' || c == '=' || c == '<' || c == '>' || c == '~';
}

bool ExpressionConverter::isOperand(char c) const {
    return isalnum(c);
}

int ExpressionConverter::getPriority(char oper) const {
    switch (oper) {
    case '=': return 0;
    case '<': case '>': return 1;
    case '+': case '-': return 2;
    case '*': case '/': case '%': return 3;
    case '^': return 4;
    case '~': return 5;
    default: return -1;
    }
}

bool ExpressionConverter::validateInfix(const string& expr) const {
    if (expr.empty()) {
        return false;
    }

    int bracketCount = 0;
    for (char c : expr) {
        if (c == '(') {
            bracketCount++;
        }
        else if (c == ')') {
            bracketCount--;
            if (bracketCount < 0) {
                return false;
            }
        }
    }

    return bracketCount == 0;
}

bool ExpressionConverter::validateONP(const string& expr) const {
    if (expr.empty()) {
        return false;
    }

    int operandCount = 0;

    for (char c : expr) {
        if (isOperand(c)) {
            operandCount++;
        }
        else if (isOperator(c)) {
            if (c == '~') {
                if (operandCount < 1) return false;
            }
            else {
                if (operandCount < 2) return false;
                operandCount--;
            }
        }
        else {
            return false;
        }
    }

    return operandCount == 1;
}

string ExpressionConverter::infixToONP(const string& infix) {
    string cleanInfix = removeSpaces(infix);

    if (!validateInfix(cleanInfix)) {
        return "error";
    }

    Stack stack;
    string result;

    for (size_t i = 0; i < cleanInfix.length(); i++) {
        char c = cleanInfix[i];

        if (isOperand(c)) {
            result += c;
        }
        else if (c == '(') {
            stack.push(string(1, c));
        }
        else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != "(") {
                result += stack.pop();
            }
            if (!stack.isEmpty()) {
                stack.pop();
            }
        }
        else if (isOperator(c)) {
            if (c == '-' && (i == 0 || cleanInfix[i - 1] == '(' || isOperator(cleanInfix[i - 1]))) {
                stack.push("~");
            }
            else {
                while (!stack.isEmpty() && stack.peek() != "(" &&
                    getPriority(stack.peek()[0]) >= getPriority(c)) {
                    result += stack.pop();
                }
                stack.push(string(1, c));
            }
        }
    }

    while (!stack.isEmpty()) {
        string op = stack.pop();
        if (op == "(") {
            return "error";
        }
        result += op;
    }

    return result;
}

string ExpressionConverter::ONPToInfix(const string& onp) {
    string cleanONP = removeSpaces(onp);

    if (!validateONP(cleanONP)) {
        return "error";
    }

    Stack stack;

    for (char c : cleanONP) {
        if (isOperand(c)) {
            stack.push(string(1, c));
        }
        else if (isOperator(c)) {
            if (c == '~') {
                if (stack.isEmpty()) return "error";

                string operand = stack.pop();

                stack.push("(~" + operand + ")");
            }
            else {
                if (stack.isEmpty()) return "error";
                string right = stack.pop();
                if (stack.isEmpty()) return "error";
                string left = stack.pop();

                stack.push("(" + left + c + right + ")");
            }
        }
        else {
            return "error";
        }
    }

    if (stack.isEmpty()) return "error";

    string result = stack.pop();

    if (!stack.isEmpty()) return "error";

    return result;
}