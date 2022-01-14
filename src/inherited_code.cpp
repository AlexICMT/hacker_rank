/*
 * 				inherited_code.cpp
 *				/hacker_rank/src/inherited_code.cpp
 *
 *  Created on: 14 янв. 2022 г.
 *      Author: alexicmt
 */


#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */

class BadLengthException
{
	int m_length;
public:
	BadLengthException(int length) : m_length(length) {}
	inline int what() {return m_length;}
};

/* The constant part of code*/
bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}
/*
int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
*/
