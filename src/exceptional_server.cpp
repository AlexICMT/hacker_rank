/*
 * 				exceptional_server.cpp
 *				/hacker_rank/src/exceptional_server.cpp
 *
 *  Created on: 14 янв. 2022 г.
 *      Author: alexicmt
 */

#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;
long long A, B;

class Server {
private:
	static int load;

public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}

		cout <<"before allocating of v" << '\n';

		vector<int> v(A, 0);

		for (int number : v)
		cout <<"v[]" <<  number << '\n';

		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);

		cout <<"ans" <<  ans << '\n';
		cout <<"result" <<  (real + A - B*ans) << '\n';

		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int no_main_2() {
	int T; cin >> T;
	while(T--) {
		//long long A, B;
		cin >> A >> B;

		/* Enter your code here. */
		try
		{
			if ((T+1) < 1 || (T+1) > 1000)
				return -2;
			if (cin.fail())
				throw -1;
			 cout << Server::compute(A,B) << endl;
		}
		catch (invalid_argument& a)
		{
			cout << "Exception: " << a.what() << '\n';
		}
		catch (int& a)
		{
			cout << "Exception: " << a << '\n';
		}
		catch (bad_alloc& a)
		{
			cout << "Not enough memory" << '\n';
		}
		catch (const exception& a)
		{
			cout << "Exception: " << a.what() << '\n';
			//cout << "Other Exception." << '\n';
		}
		catch (...)
		{
			cout << "Other Exception." << '\n';
		}

	}
	cout <<"A=" << A << '\n';
	cout <<"B=" << B << '\n';

	cout << Server::getLoad() << endl;
	return 0;
}


