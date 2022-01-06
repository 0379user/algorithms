#include <iostream>
#include "Algo.h"

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
void show_arr(int * arr)
{
	std::cout << "\n";
	for (int i = 0; i < SIZE_ARR; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void test()
{
	CodeTimer t("test function");
	int* i = new int[SIZE_ARR]();
		show_arr(i);
	rand_feel(i);
		show_arr(i);
	//std::cout << sort::bouble(i, SIZE_ARR);
	//	show_arr(i);
	//std::cout << sort::bouble_plus(i, SIZE_ARR);
	//show_arr(i);
	
	std::cout << sort::merge(i, SIZE_ARR);
	show_arr(i);
}

int main()
{
	test();

	return 0;
}