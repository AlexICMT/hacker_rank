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
//public:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function
   virtual void print_map(std::string_view, const std::map<int, Node*>&) = 0;
   public:
   map<int,Node*>* p_mp = &mp;
};

// The work place begins
/*
template<typename K, typename V>
map<V, K> inverse_map(map<K, V> &m)
{
    map<V, K> inv;
    for_each(m.begin(), m.end(), [&inv] (const pair<K, V> &p) { inv.insert(make_pair(p.second, p.first)); });
    return inv;
}
*/



class LRUCache: public Cache
{
Node *ptr = nullptr;
map<int, Node*>::iterator it, it_2;
vector <map<int, Node*>::iterator> it_3;
public:
	LRUCache(int cap) {cp = cap;}
	virtual void set(int key, int value)
	{
		auto search = mp.find(key);
		if ((search == mp.end()) && (static_cast<int>(mp.size()) < cp))
		{
			ptr = new Node(key, value);
			it = mp.insert(make_pair(key, ptr)).first;
			it_3.push_back(it);
		}
		else
		{
			auto search = mp.find(key);
			if(search == mp.end())
			{
				mp.erase(it_3[0]);
				for (int i = 0; i < cp; i++)
					if(i != (cp - 1))
						it_3[i] = it_3[i+1];
				it_3[cp - 1] = mp.insert(make_pair(key, ptr)).first;
			}
			else
			{
				for (int i = 0; 9 < cp; i++)
					if(it_3[i] == search)
						;
			}

		}
	}
	virtual int get(int key)
	{
		if(mp.count(key) > 0)
			return mp[key]->value;
		else
			return -1;
	}
	virtual void print_map(std::string_view comment, const std::map<int, Node*>& m)
	{
		cout << comment;
	    for (const auto& [key, value] : m) {
	        std::cout << key << " = " << value->value << "; ";
	    }
	    std::cout << '\n';
	    cout << "Map size: " << mp.size() << '\n';
	}
};

/*
 * set() - Set/insert the value of the key, if present, otherwise add the key as the most recently used key.
 * If the cache has reached its capacity, it should replace the least recently used key with a new key.
 * get() - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 */

// The work place ends

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;;
      if(command == "get")
      {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set")
      {
         int key, value;
         cin >> key >> value;
         l.set(key, value);
      }
      if(command == "print_map")
      {
    	  l.print_map("Actual map: ", *l.p_mp);
      }
   }
   return 0;
}

/*
 		for(int i = 1; i <= cp; i++)
			mp[i]->prev->value = mp[i]->value;
		int event{};
		for(int i = 1; i <= cp; i++)
			if(mp[i] == value)
			{
				for(int j = 1; j <= i; j++)
				{
					if(j > 1)
						mp[j]->next->value = mp[j-1]->value;
					mp[1]->next->value = value;
				}
				event++;
				break;
			}
		if(event)
			event = 0;
		else
		{
			for(int i = 1; i <= cp; i++)
			{
				if(i > 1)
					mp[i]->next->value = mp[i-1]->value;
				mp[1]->next->value = value;
			}
		}
		for(int i = 1; i <= cp; i++)
			mp[i]->value = mp[i]->next->value;
 */
