// Hash_Table.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#define TABLE_SIZE = 3

using namespace std;

template <typename K, typename V>
class HNode
{
public:
	K key;
	V value;

	HNode()
	{
		K key = NULL;
		V value = NULL;
	}
	HNode(typename K init_K)
	{
		K key = init_K;
		V value = NULL;
	}
	HNode(typename K init_K, typename V init_V)
	{
		key = init_K;
		value = init_V;
	}
	K GetKey()
	{
		return key;
	}
	V GetValue()
	{
		return value;
	}
};

template <typename generic_type>
class HashTable
{private:
	//int slot; if my vectors are going to be a set size i dont even need this
	vector<generic_type>*table;

public:
	HashTable()
	{
		table = nullptr;
	}
	/*HashTable(int init_S)
	{
		slot = init_S;
		table = nullptr;
	}*/

	HashTable(vector<generic_type> init_T)
	{
		table =vector<generic_type>init_T(TABLE_SIZE);//is this how i would initialize a new vecrtor since i want the vector to have a fixed size of indexes? 
	}
	

	int HashAlg(<typename K> init_K)//this code wont compile because it doesnt like the <> in the ()
	{								//but if i get rid of them then init_K is no longer recognized in the functions 
		int hash = init_K.length % 3; 
		return hash;
	}

	 void HInsert(<typename K> init_K)
	{
		if (init_K != NULL)
		{
			table[HashAlg(init_K)]=init_K;// is this correct? or should i use the vector method insert, like this vector.insert(HashAlg(init_K), init_K)
		}
		else { cout << "You cannot insert an empty Key!!!" << endl; }
	}

	void Display()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			cout << table[i] << "\n" << endl;
		}
	}
};


int main()
{
	HNode<string, int> N1("Rob", 3);
	HashTable<vector<string>>* HT1;
	HT1->HInsert(N1.key);
	HT1->Display();
	
}


