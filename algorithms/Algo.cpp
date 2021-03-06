#include "Algo.h"
#include <map>
#include <iostream>

namespace sort
{
	int result = 0;
	int bouble(int* arr, int size){
		std::cout << "bouble\n";
		//CodeTimer T("bouble sort"); 0.0236658 - 1014
		bool sorted = false;
		int tmp;
		int counter = 0;
		while (!sorted) {
			sorted = true;
			for (int i = 0; i < size-1; i++)
			{
				counter++;
				if (arr[i] > arr[i + 1])
				{
					tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
					sorted = false;
				}
			}
		}
		return counter;
}

	int bouble_plus(int* arr, int size)
	{
		std::cout << "bouble_plus\n";
		//CodeTimer T("bouble plus sort");//0.167414 - 5601
		int tmp;
		int counter = 0;
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < size - 1; i++)
			{
				counter++;
				if (arr[i] > arr[i + 1])
				{
					tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
					i--;
					sorted = false;
				}
			}
		}
	
	return counter;
	}

	int choose(int* arr, int size)
	{
		std::cout << "choose\n";
		int counter = 0;
		for (int pos = 0; pos < size - 1; pos++)
		{
			for (int i = pos; i < size; i++)
			{
				counter++;
				if (arr[i] < arr[pos])
				{
					int tmp = arr[i];
					arr[i] = arr[pos];
					arr[pos] = tmp;
				}

			}
	}
		return counter;
	}

	int merge(int* arr, int size)
	{
		std::cout << "merge\n";
		int counter = 0;
		//CodeTimer T("merge sort");
		int* tmp = new int[size];
		int mid = (size % 2 == 1) ? (size/2)+1 : (size/2) ;
		int step;
		int h=1;
		while (h < size)
		{
			step = h;
			int i = 0;
			int j = mid;
			int k = 0;
			while (step <= mid)
			{
				while ((i < step) && (j < size) && (j < (mid + step)))
				{
					if (arr[i] < arr[j])
					{
						tmp[k] = arr[i];
						i++; k++;
						counter++;
					}
					else
					{
						tmp[k] = arr[j];
						j++; k++;
						counter++;
					}
				}
				while (i < step)
				{
					tmp[k] = arr[i];
					i++; k++;
					counter++;
				}
				while ((j < (mid + step)) && (j < size))
				{
					tmp[k] = arr[j];
					j++; k++;
					counter++;
				}
				step += h;
				counter++;
			}
			h *= 2;
			for (i = 0; i < size; i++)
			{
				arr[i] = tmp[i];
				counter++;
			}
			counter++;
		}
		return counter;
	}

	void swap(int* l, int* r)
	{
		int t = *l;
		*l = *r;
		*r = t;
	}

	int partition(int* arr, int low, int high)
	{
		int pivot = arr[high];
		int i = low - 1;
		for (int j = low; j < high; j++)
		{
			if (arr[j] <= pivot)
			{
				i++;
				swap(&arr[i], &arr[j]);
			}
		}
		swap(&arr[i + 1], &arr[high]);
		return i + 1;
	}

	int quick(int* arr, int low, int high) 
	{

		result++;
		if (low < high)
		{
			int pi = partition(arr, low, high);
			quick(arr, low, pi - 1);
			quick(arr, pi + 1, high);
		}
		return result;
	}

	int find_smallest(int* arr, int size)
	{
		int temp = arr[0];
		int index = 0;
		for (int i = 1; i < size; i++)
		{
			if (temp>arr[i])
			{
				temp = arr[i];
				index = i;
			}
		}
		return index;
	}
	void pop(int* & arr, size_t size, int index_delete)
	{
		int* n_arr = new int[(size - 1)];
		for (int i = 0, j=0; i < size; i++, j++)
		{
			if (i == index_delete)
			{
				++i;
			}
			n_arr[j] = arr[i];
		}
		int* t = arr;
		arr = n_arr;
		delete[] t;
	}
	int selection_sort(int* & arr, int size)
	{
		std::cout << "selection_sort\n";
		int counter = 0;
		int* tmp = new int[size];
		int new_size = size;
		int in = 0;
		while (size)
		{
			counter++;
			int smallest = find_smallest(arr, new_size);
			tmp[in] = arr[smallest];
			pop(arr, new_size, smallest); new_size--; size--; in++;
		}
		int* t = arr;
		arr = tmp;
	    delete[] t;
		return counter;
	}
	int count_sort_map(int* arr, int size)
	{
		std::cout << "count_sort_map\n";
		int counter = 0;
		std::map<int,int> s;
		
		for (int i = 0; i < size; i++)
		{
			++ s[arr[i]];
		}
		int pos = 0;
		for (auto& el : s)
		{
			for (int j = 0; j < el.second; j++)
			{
				arr[pos] = el.first;
				pos++;
				counter++;
			}
		}
		return counter;
	}
	int count_sort_without_map(int* arr, int size)
	{
		int counter = 0;
		std::cout << "count_sort_without_map\n";
		int c[10] = { 0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < size; i++)
		{
			++c[arr[i]];
		}
		int pos = 0;
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < c[j]; i++)
			{
				arr[pos] = c[j];
				pos++;
				counter++;
			}
		}


		return counter;
	}

	int radix(int* arr, int size)
	{
		int counter = 0;

		int* a0 = new int[size];
		int* a1 = new int[size];
		
		
		for (int redix = 0; redix<32; redix++ )
		{
			int a0_size = 0;
			int a1_size = 0;
			for (int i = 0; i < size; i++)
			{
				counter++;
				if ((arr[i] & (1 << redix)) == 0)
				{
					a0[a0_size++] = arr[i];
				}
				else
				{
					a1[a1_size++] = arr[i];
				}
			}
			for (int i = 0; i < a0_size; i++)
			{
				counter++;
				arr[i] = a0[i];
			}
			for (int i = 0; i < a1_size; i++)
			{
				counter++;
				arr[a0_size + i] = a1[i];
			}

		}
		return counter;
		delete[] a0;
		delete[] a1;
	}
}



namespace search
{
	int binary_search(int * arr, int size, int val)
	{
		int low = 0;
		int high = size - 1;
		int mid = 0;
		while(low<=high)
		{
			mid = (low+high) / 2;
			if (arr[mid] == val)
			{
				return mid;
			}
			else if (arr[mid] > val)
			{
				high = mid-1;
			}else
			{
				low = mid+1;
			}
		}
		return -1;
	}

}