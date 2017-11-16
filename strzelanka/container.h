#pragma once
#include <cassert>

template<typename T>class container
{
private:
	T **tab;
	int capacity;
	int amount;

public:
	container() : amount(0), capacity(1000)
	{
		tab = new T*[capacity];
		for (int i = 0; i < capacity; i++)
		{
			tab[i] = NULL;
		}
	}

	void add(T object)
	{
		for (int i = 0; tab[i] != NULL || i < capacity; i++)
		{
			if (tab[i] == NULL)
			{
				tab[i] = new T(object);
				amount++;
				break;
			}
		}

	}
	void remove(int id)
	{
		for (int i = 0; i < capacity || tab[i] == NULL; i++)
		{
			if (tab[i] != NULL && *tab[i] == id)
			{
				delete tab[i];
				tab[i] = NULL;
				amount--;
			}	
		}
	}
	bool is_empty()
	{
		if (amount == 0)return true;
	}

	class iterator
	{
	private:
		int index;
		container &conten;
	public:
		iterator(container &_conten): conten(_conten), index(0) {}
		iterator(container &_conten, bool b): conten(_conten), index(_conten.capacity) {}
		
		T* operator ++()
		{
			assert(index < conten.capacity);
			return conten.tab[++index];
		}
		T* operator ++(int)
		{
			assert(index < conten.capacity);
			return conten.tab[index++];
		}
		T* operator --()
		{
			assert(index > 0);
			return conten.tab[--index];
		}
		T* operator --(int)
		{
			assert(index > 0);
			return conten.tab[index--];
		}
		T* operator*()
		{
			return conten.tab[index];
		}
		bool operator!=(iterator i)
		{
			return (index != i.index);
		}

	};
};

