#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "Timer.h"

using namespace std;

// Task 1
template<typename t>
void Swap(t* x, t* y)
{
	t temp  = *x;
	*x = *y;
	*y = temp;
}

template<typename P>
void SortPointers(vector<P*> &ptr)
{
	sort(ptr.begin(), ptr.end(), [](const auto& ptr1, const auto& ptr2)
		{
			return *ptr1 < *ptr2;
		});
}


void delvec(vector<int*>& ptr) // Данный метод нашел в интернете. Хотел чтобы каждый раз задавались новые рандомные числа, но не совсем понимаю как очистить значения вектора.
{
	for (int i(0); i < ptr.size(); i++)
		delete [] ptr[i];
	ptr.clear();
	ptr.shrink_to_fit();

}


// ----Task 3 -----

const string_view vowels
{ "AEIOUYaeiouy" };

void method1(const string_view& s)
{
	Timer timer("Method 1");
	size_t count = count_if(s.begin(), s.end(), [&](const auto& c)
		{
			return vowels.find(c) != string::npos;
		});
	cout << count << endl;
	timer.print();
}

void method2(const string_view& s)
{
	Timer timer("Method2");
	size_t count = count_if(s.begin(), s.end(), [&](const auto& c)
		{
			for (size_t i = 0; i < vowels.size(); ++i)
			{
				if (vowels[i] == c)
					return true;
			}
			return false;
		});
	cout << count << endl;
	timer.print();
}

void method3(const string_view& s)
{
	size_t count = 0;
	Timer timer("Method 3");
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (vowels.find(s[i]) != string::npos)
		{
			++count;
		}
	}
	cout << count << endl;
	timer.print();
}

void method4(const string_view& s)
{
	size_t count = 0;
	Timer timer("Method 4");
	for (size_t i = 0; i < s.size(); ++i)
	{
		for (size_t j = 0; j < vowels.size(); ++j)
		{
			if (vowels[j] == s[i])
				++count;
		}
	}
	cout << count << endl;
	timer.print();
}




int main()
{
	{
		//Проверка дз 1
	int a = 1;
	int b = 2;

	int* x = new int (a);
	int* y = new int(b);

	cout << x << endl << y << endl;

	Swap(&x, &y);

	cout << x << endl << y << endl;

	delete x;
	delete y;
	}

	{
		//Проверка дз 2. Не понятно как очистить рандомные значения вектора. Каждый раз выходят одни и те же числа.
		int length = 10;
		vector<int*> ptr;

		for (int i = 0; i < length; ++i)
		{
			int* a = new int;
			*a = rand() % 1000;
			ptr.push_back(a);
		}
		

		for (int i = 0; i < length; ++i)
		{
			cout << *ptr[i] << ' ';
		}

		cout << endl;

		SortPointers(ptr);

		for (int i = 0; i < length; ++i)
		{
			cout << *ptr[i] << ' ';
		}

		delvec(ptr); 

		cout << endl;
	}

	{
		// Проверка дз 3.
		ifstream file("W&P.txt");
		file.seekg(0, ios::end);
		size_t size = file.tellg();
		file.seekg(0);
		string s(size, ' ');
		file.read(&s[0], size);

		cout << "\n Try to count vowels in the book\n";

		method1(s);
		method2(s);
		method3(s);
		method4(s);
	}

}