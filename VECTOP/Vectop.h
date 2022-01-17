
#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

class Vector
{
	int size = 0;
	int capacity = 10;
	int* myvector;
void EnsureCapacity(int size1)
{
	if (size1 > capacity)
	{
		capacity = 2 * size;
	    int* myvector1 = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			myvector1[i] = myvector[i];
		}
		delete[] myvector;
		myvector = myvector1;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);
		cout << "MORE Capacity!\n";
		SetConsoleTextAttribute(h, 7);
	}
	else 
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);
		cout << "NORMAl Capacity!\n";
		SetConsoleTextAttribute(h, 7);
	}
}
public:
	Vector() : Vector(10)
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 9);
		cout << "C-TOR WITHOUT PARAMS!\n";
		SetConsoleTextAttribute(h, 7);
	}

	Vector(int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		myvector = new int[capacity];
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 9);
		cout << "C-TOR WITH PARAMS!\n";
		SetConsoleTextAttribute(h, 7);
	}
	Vector(const Vector& original)
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 9);
		cout << "COPY C-TOR\n";
		SetConsoleTextAttribute(h, 7);
		capacity = original.capacity;
		size = original.size;
		for (int i = 0; i < size; i++)
		{
			myvector[i] = original.myvector[i];
		}
	}
	int GetSize() const
	{
		return size;
	}
	int GetCapacity() const
	{
		return capacity;
	}
	bool IsEmpty() const
	{
		return size == 0;
	}

	void Print() const
	{
		if (IsEmpty())
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 14);
			cout << "Vector is empty.\n";
			SetConsoleTextAttribute(h, 7);
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				cout << myvector[i] << " ";
			}
			cout << endl;
		}
	}
	~Vector()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 9);
		cout << "DESTRUCTOR!\n";
		SetConsoleTextAttribute(h, 7);
		if (myvector != nullptr) delete[] myvector;
	}
	void  RandomFill() 
	{
		size = capacity;
		for (int i = 0; i < capacity; i++)
		{
			myvector[i] = (rand() % 100 );
		}	
	}
	void Shuffle() 
	{
		random_shuffle(myvector, myvector + size);
	}
	void Reverse()
	{
		reverse(myvector, myvector + size);
	}
	void SortAsc()
	{
		sort(myvector, myvector + size);
	}
	void SortDesc()
	{
		sort(myvector, myvector + size);
		Reverse();
	}
	void ClearZero()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);
		cout << "ALL ZERO! : ";
		SetConsoleTextAttribute(h, 7);
		
		for (int i = 0; i < size; i++)
		{
			myvector[i] = 0;
		}
		//size = 0;
	}
	void Clear()
	{
       size = 0;
	}
	void PushBack(int value)
	{
		EnsureCapacity(size + 1); // проверка, хватит ли места для нового элемента - делайте сами ;)
		myvector[size++] = value;
	}
	void PushFront(int value)
	{
	    EnsureCapacity(size + 1);
		for (int i = size; i > 0; i--)
		{
			myvector[i] = myvector[i - 1];
		}
		myvector[0] = value;
		size++;
	}
	void Insert(int index,int value)
	{
		if (index > size)
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 14);
			cout << "SORRY, BUT NO THIS INDEX\n";
			SetConsoleTextAttribute(h, 7);
		}
		else {
			EnsureCapacity(size + 1);
			for (int i = size; i > index - 1; i--)
			{
				myvector[i] = myvector[i-1];
			}
			myvector[index - 1] = value;
			size++;
		}
	}
	void RemoveAt(int index, int value)
	{
		if (index > size)
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 14);
			cout << "SORRY, BUT NO THIS INDEX\n";
			SetConsoleTextAttribute(h, 7);
		}
		else 
		{
			for (int i = index; i < size; i++)
			{
				myvector[i-1] = myvector[i];
			}
			size--;
		}
	}
	void PopBack()
	{
		size--;
	}

	void PopFront()
	{
		for (int i = 0; i < size; i++)
		{
			myvector[i] = myvector[i+1];
		}
		size--;
	}

	void Remove(int value)
	{
		for (int i = 0; i < size; i++)
		{

			if (myvector[i] == value) RemoveAt(i+1, value);
		}
	}

	int GetElementAt(int index) const
	{
		if (index > size)
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 14);
			cout << "SORRY, BUT NO THIS INDEX\n";
			SetConsoleTextAttribute(h, 7);
		}
		else
		{
			int val = myvector[index];
			return val;
		}
	}
	int IndexOf(int value)
	{
		for (int i = 0; i < size; i++)
		{
			if (myvector[i] == value) return i;
		}
		return -1;
	}
	int LastIndexOf(int value)
	{
		for (int i = size; i > 0; i--)
		{
			if (myvector[i] == value) return i;
		}
		return -1;
	}
	///////////////////////////////////ПЕРЕГРУЗКИ ОПЕРАТОРОВ

	Vector operator = (const Vector& right)
	{
		capacity = right.capacity;
		size = right.size;
		for (int i = 0; i < size; i++)
		{
			myvector[i] = right.myvector[i];
		}

		return 0;
	}
	bool operator == (const Vector& right)
	{
		if (size != right.size)
		{
			return false;
		}
		for (int i = 0; i < right.size; i++) {
			if (myvector[i] != right.myvector[i])
			{
				return false;
			}
		}		
		return true;
	}
	friend ostream& operator << (ostream& output, const Vector& vec)
	{
		for (int i = 0; i < vec.size; i++) 
		{
			output << vec.myvector[i]<<" ";
		}
		return output;
	}
	friend istream& operator >> (istream& input, Vector& vec)
	{

		for (int i = 0; i <= vec.size; i++)
		{
			input >> vec.myvector[i];
		}

		return input;
	}
	int  operator[] (int index)
	{
		if (index < 0 || index > size)
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 4);
			cout << "big index for this vector" << endl;
			SetConsoleTextAttribute(h, 7);
		}
		return myvector[index];
	}
};