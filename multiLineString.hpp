#pragma once
#include <string>
#include <cstdarg>

namespace multilineString{

    static std::string _mult(size_t argc, ...){
        std::string strung = "";

        va_list arg;
        va_start(arg, argc);

        for(size_t i = 1; i < argc; i++){
            strung += va_arg(arg, const char*);
            strung += '\n';
        }
        strung += va_arg(arg, const char*);

        va_end(arg);
        return strung;
    }

    template<typename ...ARGS>
    static std::string concat(ARGS&&...args){
        return _mult(sizeof...(args), args...);
    }

};


