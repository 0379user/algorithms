#include <iostream>
#include "Algo.h"
#include <vector>
/*
future tasks
1) ��������� ����������: ���������+, �������� � quicksort.  ...�������������
2) ������������������ ��������� ...
3) �������� ���������� ���������� ...
4) ��������� ������: �������� � �������� ...
5) �������� ���������� ������
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
	int* arr = new int[SIZE_ARR];
	rand_feel(arr);
	show_arr(arr, SIZE_ARR);
	int i = sort::quick(arr, 0, SIZE_ARR-1);
	//int i = sort::bouble(arr, SIZE_ARR);
	show_arr(arr, SIZE_ARR);
	std::cout << "\n" << i;
	return 0;
}