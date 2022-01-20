/*
 * 				variadics.cpp
 *				/hacker_rank/src/variadics.cpp
 *
 *  Created on: 20 янв. 2022 г.
 *      Author: alexicmt
 */

#include <iostream>

void tprintf(const char* format) // base function
{
    std::cout << format;
}

template<typename T, typename... Targs>
void tprintf(const char* format, T value, Targs... Fargs) // recursive variadic function
{
    for (; *format != '\0'; format++)
    {
        if (*format == '%')
        {
            std::cout << value;
            tprintf(format + 1, Fargs...); // recursive call
            return;
        }
        std::cout << *format;
    }
}

int main()
{
    tprintf("% world% %\n", "Hello", '!', 123);
}


