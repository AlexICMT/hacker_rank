/*
 * 				variadics_tsk.cpp
 *				/hacker_rank/src/variadics_tsk.cpp
 *
 *  Created on: 21 янв. 2022 г.
 *      Author: alexicmt
 */


#include <iostream>
#include <vector>
using namespace std;

// base case
void doPrint(std::ostream& out) {}

template <typename T>
void doPrint(std::ostream& out, T t)
{
    out << ' ' << t;
}

template <typename T, typename U, typename... Args>
void doPrint(std::ostream& out, T t, U u, Args... args)
{
    out << ' ' << t << ',';
    doPrint(out, u, args...);
}

vector<bool>v {};
int counter {}, result {};

template<bool t>
int reversed_binary_value()
{

	std::cout << __PRETTY_FUNCTION__ << "\n";
	return t;
}

template<typename T>
int reversed_binary_value(T t)
{
	std::cout << __PRETTY_FUNCTION__ << "\n";
	return t;
}

template<typename T, typename... Rest>
int reversed_binary_value(T t, Rest... rest)
{
	std::cout << __PRETTY_FUNCTION__ << "\n";
	return ((t << 1) + reversed_binary_value(rest...));
}

template<bool N, bool... S> int reversed_binary_value()
{
	//bool&& rv = N;
	int size = sizeof...(S);
	std::cout << "size= " << size << "\n";
	//if(!(static_cast<int>(v.size()) == 0))

	v.push_back(N);
	std::cout << __PRETTY_FUNCTION__ << "\n";
	//return ((N<<(counter - 1)) + reversed_binary_value(S...));
	result += N << (counter);
	counter++;
	return N + reversed_binary_value(S...);
}

template <int n, bool... digits>
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
  		std::cout << __PRETTY_FUNCTION__ << "\n";
  		int z = reversed_binary_value<digits...>();
    	cout << z << endl;
    	std::cout << (z+64*y==x);
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
        std::cout << "v = { ";
        for (int n : v) {
            std::cout << n << ", ";
        }
        std::cout << "}; \n";
  	}
  	cout << v.size();
  	cout << counter;
  	cout << result;
  	return 0;
}

