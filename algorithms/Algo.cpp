#include "Algo.h"


namespace sort
{
	//template<typename T>
	int bouble(int* arr, int size){
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






}