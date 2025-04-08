#ifndef EXPRESSION_CONVERTER_H
#define EXPRESSION_CONVERTER_H

#include <string>

/*
 * @brief Klasa do konwersji wyra¿eñ miêdzy notacj¹ infiksow¹ i ONP
 * @details Implementuje metody konwersji miêdzy notacj¹ infiksow¹ i ONP
 */
class ExpressionConverter {
private:
    /*
     * @brief Usuwa niepotrzebne spacje z wyra¿enia
     * @param expr Wyra¿enie do oczyszczenia
     * @return Oczyszczone wyra¿enie
     */
    std::string removeSpaces(const std::string& expr);

    /*
     * @brief Sprawdza czy znak jest operatorem
     * @param c Znak do sprawdzenia
     * @return true jeœli znak jest operatorem, false w przeciwnym przypadku
     */
    bool isOperator(char c) const;

    /*
     * @brief Sprawdza czy znak jest operandem (argumentem)
     * @param c Znak do sprawdzenia
     * @return true jeœli znak jest operandem, false w przeciwnym przypadku
     */
    bool isOperand(char c) const;

    /*
     * @brief Zwraca priorytet operatora
     * @param oper Operator
     * @return Priorytet operatora
     */
    int getPriority(char oper) const;

    /*
     * @brief Sprawdza poprawnoœæ wyra¿enia infiksowego
     * @param expr Wyra¿enie do sprawdzenia
     * @return true jeœli wyra¿enie jest poprawne, false w przeciwnym przypadku
     */
    bool validateInfix(const std::string& expr) const;

    /*
     * @brief Sprawdza poprawnoœæ wyra¿enia ONP
     * @param expr Wyra¿enie do sprawdzenia
     * @return true jeœli wyra¿enie jest poprawne, false w przeciwnym przypadku
     */
    bool validateONP(const std::string& expr) const;

public:
    /*
     * @brief Konwertuje wyra¿enie z notacji infiksowej do ONP
     * @param infix Wyra¿enie w notacji infiksowej
     * @return Wyra¿enie w notacji ONP lub "error" jeœli wyra¿enie jest niepoprawne
     */
    std::string infixToONP(const std::string& infix);

    /*
     * @brief Konwertuje wyra¿enie z notacji ONP do infiksowej
     * @param onp Wyra¿enie w notacji ONP
     * @return Wyra¿enie w notacji infiksowej lub "error" jeœli wyra¿enie jest niepoprawne
     */
    std::string ONPToInfix(const std::string& onp);
};

#endif