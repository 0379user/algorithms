#include "Algo.h"


namespace sort
{
	 
	int bouble(int* arr, int size){
		CodeTimer T("bouble sort");
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
		CodeTimer T("bouble plus sort");
		int tmp;
		int counter = 0;

		 for (int i = 0; i < size - 1; i++)
			{
				counter++;
				if (arr[i] > arr[i + 1])
				{
					tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
					--i;
				}
			}
	
	return counter;
	}

	int merge_sort(int* arr, int size)
	{
		CodeTimer T("merge sort");
		return 0;
	}





}