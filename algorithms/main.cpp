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
#define SIZE_ARR 10


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

void test_template()
{
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	show_arr(vec, vec.size());
	std::cout << "find 10 " << search::line_search(vec.begin(), 
		vec.end(),  10);
}

int result;
int recursion_sum(int* arr, int tail)
{
	if (tail == 0)
	{
		return arr[tail];
	}
	return result += recursion_sum(arr, tail-1);

}

int i=0;
int fib(int val)
{
	if (val > 3)
	{
		int res = 2;
		int i = 3;
		while (i != val)
		{
			res += res;
		}


	}

}

int main()
{
	int arr[] = { 1,2,3,4,5 };
	int i = (sizeof(arr) / sizeof(int));
	int j = 0;
	j=recursion_sum(arr, i);
	std::cout << j;
	//test();

	return 0;
}