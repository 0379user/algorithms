#include "Algo.h"


namespace sort
{
	 
	int bouble(int* arr, int size){
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
		//CodeTimer T("bouble plus sort");//0.167414 - 5601
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
					i=-1;

				}
			}
	
	return counter;
	}

	int merge(int* arr, int size)
	{
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

	int quick(int* arr, int size) 
	{
		return 0;
	}



}