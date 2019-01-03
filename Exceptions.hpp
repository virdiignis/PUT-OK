//
// Created by prance on 27.12.18.
//

#ifndef OK_EXCEPTIONS_HPP
#define OK_EXCEPTIONS_HPP

#include <exception>

class NotReadyException : std::exception{};
class SecondBeforeFirstException : std::exception{};


#endif //OK_EXCEPTIONS_HPP
