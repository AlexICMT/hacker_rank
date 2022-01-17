/*
 * 				abstract_classes_polymorphism.cpp
 *				/hacker_rank/src/abstract_classes_polymorphism.cpp
 *
 *  Created on: 17 янв. 2022 г.
 *      Author: alexicmt
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

// The work place begins

class LRUCache: public Cache
{

public:
	LRUCache(int cap): cp(cap) {}
	virtual int get(int key) {return mp[key];}
	virtual void set(int key, int value)
	{
		mp[key]->prev->value = mp[key]->value;


		for(int i = 0; i < cp; i++)
			if(mp[i]->value == mp[key]->value)
			{
				mp[i]->prev->value = mp[i]->value;
				if((i+1) != cp)
				{
					mp[i+1]->prev->value = mp[i+1]->value;
					mp[i+1]->value = mp[i]->value;
				}
			}
		mp[key]->value = value;

		if(key >=0 && key < (cp-1))
			mp[key+1]
		mp[key]->prev->value = mp[key]->value;
		mp[key]->value = value;
	}
};

// The work place ends

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}


