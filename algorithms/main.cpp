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
	std::cout << sort::bouble(i, SIZE_ARR);
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




int main()
{
	test();
	
	return 0;
}