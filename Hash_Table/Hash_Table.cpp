// Hash_Table.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

template <typename K, typename V>

class HNode
{
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
{
	//int slot; if my arrays are going to be a set size i dont even need this
	array<generic_type>*table;

	HashTable()
	{
		table = nullptr;
	}
	/*HashTable(int init_S)
	{
		slot = init_S;
		table = nullptr;
	}*/
	HashTable(array<generic_type> init_T)
	{
		table =array<generic_type>[3] init_T;//is this how i would initialize a new array since i want the array to have a fixed size of indexes? 
	}
	

	int HashAlg(K init_K)
	{
		int hash = init_K.length % 3; 
		return hash;
	}
public:
	void HInsert(K init_K)
	{
		if (init_K != NULL)
		{
			table[HashAlg(init_K)]->push_back(init_K);// is this even remotely correct? 
		}
		else { cout << "You cannot insert an empty Key!!!" << endl; }
	}

};


int main()
{
	HNode<string, int >*N1;
	N1->key = "Rob";
}


