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
#include <vector>
#include <list>
#include <map>
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

template<typename T> bool pair_comparer(T a, T b) { return a == b; }

template<typename T> bool pair_comparer(T a) { return false; }

template<typename T, typename... Args>
bool pair_comparer(T a, T b, Args... args)
{
	std::cout << __PRETTY_FUNCTION__ << "\n";
	return a == b && pair_comparer(args...);
}

//The instant of the prime tuple.
template<class... Ts> struct tuple {};

template<class T, class... Ts>
struct tuple<T, Ts...> : tuple<Ts...>
{
	tuple(T t, Ts... ts) : tuple<Ts...>(ts...), tail(t) {std::cout << __PRETTY_FUNCTION__ << "\n";}
	T tail;
};

template<size_t, class> struct elem_type_holder;

template<class T, class... Ts>
struct elem_type_holder<0, tuple<T, Ts...>>
{
	typedef T type;
};

template<size_t k, class T, class... Ts>
struct elem_type_holder<k, tuple<T, Ts...>>
{
	typedef typename elem_type_holder<k - 1, tuple<Ts...>>::type type;
};

template <size_t k, class... Ts>
typename std::enable_if<
    k == 0, typename elem_type_holder<0, tuple<Ts...>>::type&>::type
get(tuple<Ts...>& t) {
  return t.tail;
}

template <size_t k, class T, class... Ts>
typename std::enable_if<
    k != 0, typename elem_type_holder<k, tuple<T, Ts...>>::type&>::type
get(tuple<T, Ts...>& t) {
  tuple<Ts...>& base = t;
  return get<k - 1>(base);
}

template <template <typename, typename> class ContainerType,
          typename ValueType,
          typename AllocType>
void print_container(const ContainerType<ValueType, AllocType>& c) {
  for (const auto& v : c) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
}

template <template <typename, typename...> class ContainerType,
          typename ValueType, typename... Args>
void print_container(const ContainerType<ValueType, Args...>& c) {
  for (const auto& v : c) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p) {
  out << "[" << p.first << ", " << p.second << "]";
  return out;
}

int n_main_6()

//int main()
{
	std::map<std::string, int> msi{{"foo", 42}, {"bar", 81}, {"bazzo", 4}};
	print_container(msi);

	std::vector<double> vd{3.14, 8.1, 3.2, 1.0};
	print_container(vd);

	std::list<int> li{1, 2, 3, 5};
	print_container(li);

	tuple<double, uint64_t, const char*> t1(12.2, 42, "big");
	std::cout << "0th elem is " << get<0>(t1) << "\n";
	std::cout << "1th elem is " << get<1>(t1) << "\n";
	std::cout << "2th elem is " << get<2>(t1) << "\n";

	get<1>(t1) = 103;
	std::cout << "1th elem is " << get<1>(t1) << "\n";

	std::cout << pair_comparer (1.5, 1.5, 2, 2, 6, 6, 7) << std::endl;
	std::cout << sum(1, 2, 3, 8, 7);
    return 0;
}


