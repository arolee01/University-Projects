#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <stdexcept>
#include <string>

/*
 * Klasa wyj¹tku u¿ytkownika
 * @param msg Komunikat o b³êdzie
 */
class MyException : public std::runtime_error {
public:
    MyException(const std::string& msg) : std::runtime_error(msg) {}
};

#endif
