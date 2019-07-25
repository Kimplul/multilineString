#pragma once

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void concat(char* buf, size_t num ...){
    va_list arg;
    va_start(arg, num);
    for(size_t i = 1; i < num; i++){
        strcat(buf, va_arg(arg, const char*));
        strcat(buf, "\n");
    }
    strcat(buf, va_arg(arg, const char*));
    va_end(arg);

}
