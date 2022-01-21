/*
 * 				variadics.cpp
 *				/hacker_rank/src/variadics.cpp
 *
 *  Created on: 20 янв. 2022 г.
 *      Author: alexicmt
 */

#include <iostream>
#include <variant>
#include <tuple>
//using namespace std;

template <typename T>
double sum(T t)
{
	std::cout << __PRETTY_FUNCTION__ << "\n";
	return t;
}

template <typename T, typename... Rest>
double sum(T t, Rest... rest)
{
	std::cout << __PRETTY_FUNCTION__ << "\n";
	return t + sum(rest...);
}

template <typename T>
T square(T t) {return t*t;}

template <typename T>
double power_sum(T t) {return t;}

template <typename T, typename... Rest>
double power_sum(T t, Rest... rest)
{
	return t + power_sum(square(rest)...);
}

//int n_main_6

int main()
{
	std::cout << sum(1, 2, 3, 8, 7);
    return 0;
}


