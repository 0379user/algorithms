#include <iostream>
#include "Algo.h"
#include <vector>
/*
future tasks
1) Алгоритмы сортировки: пузырьком+, слиянием и quicksort.  ...пирамидальная
2) Последовательность Фибоначчи ...
3) Алгоритм нахождения факториала ...
4) Алгоритмы поиска: линейный и бинарный ...
5) Алгоритм переворота строки
*/
#define SIZE_ARR 40


void rand_feel(int * arr)
{
	for (int i = 0; i < SIZE_ARR; i++)
	{
		arr[i] = rand() % 10;
	}
}
template<class T, class T1>
void show_arr(T arr, T1 size= SIZE_ARR)
{
	std::cout << "\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void test()
{
	CodeTimer t("test function");
	int* i = new int[SIZE_ARR]();
	show_arr(i, SIZE_ARR);
	rand_feel(i);
	show_arr(i, SIZE_ARR);
	std::cout << sort::selection_sort(i, SIZE_ARR);
	show_arr(i, SIZE_ARR);
	//std::cout << "find 7 " << search::binary_search(i, SIZE_ARR, 7)<<" ";
	//std::cout << sort::bouble_plus(i, SIZE_ARR);
	//show_arr(i);
	//std::cout << sort::merge(i, SIZE_ARR);
	//show_arr(i);
}

void dinamic_fib(size_t value)
{
	if (value == 1)
	{
		std::cout << "0";
		return;
	}
	if (value == 2)
	{
		std::cout << "1";
		return;
	}
	if (value == 3)
	{
		std::cout << "1";
		return;
	}
	int* fib = new int[value];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < value; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	for (int j = 0; j < value; j++)
	{
		std::cout << " position " << j + 1 << " value " << fib[j]<<"\n";
	}
	delete[] fib;
}




 

int main()
{
	
	uint8_t x = 0;
	uint16_t t = 65535;
	x = t;
	std::cout << int(x);
	return 0;
}