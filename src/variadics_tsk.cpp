/*
 * 				variadics_tsk.cpp
 *				/hacker_rank/src/variadics_tsk.cpp
 *
 *  Created on: 21 янв. 2022 г.
 *      Author: alexicmt
 */

#include <iostream>
using namespace std;


// Enter your code for reversed_binary_value<bool...>()
template<bool N, bool... S> int reversed_binary_value()
{
	//bool&& rv = N;

	cout << N;
	return sizeof... (S);
}


template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);

    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	//std::cout << (z+64*y==x);
  	}
};

int no_main_7()
//int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
  	return 0;
}
