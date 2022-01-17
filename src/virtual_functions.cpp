/*
 * 				virtual_functions.cpp
 *				/hacker_rank/src/virtual_functions.cpp
 *
 *  Created on: 17 янв. 2022 г.
 *      Author: alexicmt
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// work place begin

static uint16_t e_cur_id[2]{};
class Person
{
protected:
	uint16_t p_age;
	string p_name;
public:
	//static uint16_t cur_id[2]{};
	virtual void getdata() = 0;
	virtual void putdata() = 0;
};

class Professor: public Person
{
private:
	uint16_t publications;
	uint16_t cur_id;
public:
	Professor() {++e_cur_id[0]; cur_id = e_cur_id[0];}
	virtual void getdata() {
		cin >> p_name >> p_age >> publications; }
	virtual void putdata() {
		cout << p_name << " " << p_age << " " << publications << " " << cur_id << endl; }
};

class Student: public Person
{
private:
	uint16_t marks[6];
	uint16_t cur_id;
	uint16_t _sum{};
	uint16_t sum() {for (int i:marks) _sum += i; return _sum;}
public:
	Student() {++e_cur_id[1]; cur_id = e_cur_id[1];}
	virtual void getdata() {
	cin >> p_name >> p_age >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5]; }
	virtual void putdata() {
	cout << p_name << " " << p_age << " " << sum() << " " << cur_id << endl; }
};

// work place end


int no_main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}


