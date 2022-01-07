#pragma once
#include "CodeTimer.h"


namespace sort
{
	int bouble(int* arr, int size);

	int bouble_plus(int* arr, int size);

	int merge(int* arr, int size);
	//
	int quick(int* arr, int low, int hight);
	int partition(int* arr, int low, int hight);
	void swap(int * l, int * r);
	//
	///helps functions
	int find_smallest(int* arr, int size);
	void pop(int* & arr, size_t size, int index_delete);

	//helps functions

	int selection_sort(int* & arr, int size);
}

namespace search
{
	int binary_search(int* arr, int size, int value);

	template<typename T,typename T1, typename con>
	T binary_search(con arr, T size, T1 val)
	{
		T low = 0;
		T hight = size - 1;
		T mid = 0;
		while (low <= hight)
		{
			mid = (low + hight) / 2;
			if (arr[mid] == val)
			{
				return mid;
			}
			if (arr[mid] > val)
			{
				hight = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		return size;
	}

	template<typename IT, typename T>
	T line_search(IT beg, IT end, T val)
	{
		T count=0;
		while (beg != end)
		{
			if(*beg==val)
			{
				return count;
			}
			count++;
			beg++;
		}
	}


}