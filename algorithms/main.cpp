#include <iostream>
#include "Algo.h"
#include <vector>

#include <thread>
#include <chrono>
#include <random>
#include <future>

/*
future tasks
1) Алгоритмы сортировки: пузырьком+, слиянием и quicksort.  ...пирамидальная
2) Последовательность Фибоначчи ...
3) Алгоритм нахождения факториала ...
4) Алгоритмы поиска: линейный и бинарный ...
5) Алгоритм переворота строки
6) Паттерны
7) Многопоточка
*/
#define SIZE_ARR 1000000


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



void dinamic_fib(int value)
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



typedef struct virtual_machine 
{
	uint8_t stack[128];
	uint16_t size;
}vm_t;
//template<typename T>
typedef struct node
{
	 int data;
	 node* next;
}node_t;
 
node_t* make_node(size_t size)
{
	node_t* nd = new node_t[size];
	node_t* ret = nd;
	for (int i = 0; i < size; i++)
	{
		nd[i].data = i;
		nd[i].next = &nd[i + 1];
	}
	nd[size - 1].next = nullptr;
	return ret;
}

void free_node(node_t* node)
{
	delete[] node;
}
void print_node(node_t* node)
{
	node_t* begin = node;
	while(begin!=nullptr)
	{ 
		std::cout << begin->data << " ";
		begin = begin->next;
	}
}

void test_node() {
	auto nd = make_node(10);
	print_node(nd);
	free_node(nd);
}

void test_digits()
{
	uint16_t* x;
	uint32_t r = 1500;
	std::string  result;
	x = (uint16_t*)&r;
	x++;
	for (int i = 0; i < 2; i++)
	{
		result += std::to_string(*x);
		x--;
	}

	std::cout << r << "\n" << result;
}

//pattern
class Singl 
{
public:
	Singl(const Singl& other) = default;
	Singl operator = (const Singl& other) {};
	
	static Singl* get_instance()
	{
		if (! (instance == nullptr))
		{
			instance = new Singl;
		}
	}
private:
	static Singl* instance;
	Singl(){}

};
Singl* Singl::instance = nullptr;

//




//thread

int somefunct(char c)
{
	std::default_random_engine dre(c);
	std::uniform_int_distribution<int> id(10, 1000);

	for (auto i = 0; i < 10; ++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
		std::cout.put(c).flush();
	}
	return c;
}

int fun1()
{
	return somefunct('+');
}
int fun2()
{
	return somefunct('0');
}

void test_threads()
{
	std::cout << "start treads \n";
	std::future<int> result1(std::async(fun1));
	int  result2=fun2();
	int result = result1.get() + result2;
	std::cout << "ended treads \n";
}


//

void test(int (*fun)(int* arr, int size))
{
	std::cout << "\n";
	CodeTimer t("test sort");
	int* i = new int[SIZE_ARR]();
	//show_arr(i, SIZE_ARR);
	rand_feel(i);
	//show_arr(i, SIZE_ARR);
	std::cout << fun(i, SIZE_ARR);
	//show_arr(i, SIZE_ARR);
	std::cout << "\n";
}
void test()
{
	std::cout << "\n";
	CodeTimer t("redix sort");
	int* i = new int[SIZE_ARR]();
	//show_arr(i, SIZE_ARR);
	rand_feel(i);
	//show_arr(i, SIZE_ARR);
	std::cout << sort::radix(i, SIZE_ARR);
	//show_arr(i, SIZE_ARR);
	std::cout << "\n";
}

int main()
{
//	test(sort::bouble);
//	test(sort::bouble_plus);
//	test(sort::choose);
	test(sort::count_sort_map);
	test(sort::count_sort_without_map);
//	test(sort::merge);
	test();
	
//	test_threads();



	return 0;
}