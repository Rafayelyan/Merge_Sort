#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void mergeSort(int* arr, int length);
void divideArray(int* arr, int n);
void mergeTwoParts(int* arr, int length, int singleArrayLength, int startIndex);
void swap(int& a, int& b);

int main()
{
	srand(time(0));
	int n;
	cout << "n: "; cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}

	/*for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]: ";
		cin >> arr[i];
	}*/

	divideArray(arr, n);
	mergeSort(arr, n);
	
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;



	delete[] arr;
	return 0;
}

void mergeSort(int *arr,int length)
{
	int step = 2;
	while (step <= length)
	{
		for (int i = 0; i < length; i += step * 2)
		{
			mergeTwoParts(arr, length, step, i);
		}
		step *= 2;
	}
	
}

void divideArray(int* arr, int n)
{
	int divider = 2, firstLength, endLength, counter = 0;
	firstLength = n / divider;
	endLength = n - firstLength;
	int index = 0;
	while (counter < firstLength)
	{
		if (arr[index] > arr[index + 1])
		{
			swap(arr[index], arr[index + 1]);
		}
		index += divider;
		++counter;
	}
}

void mergeTwoParts(int* arr, int length, int singleArrayLength, int startIndex)
{
	int firstPointer, secondPointer, twoArrayesSize;
	if (length - startIndex - 2 * singleArrayLength > 0)
		twoArrayesSize = 2 * singleArrayLength;
	else
		twoArrayesSize = length  - startIndex;
	int firstArrayLength, secondArrayLength;
	if (twoArrayesSize <= singleArrayLength)
	{
		firstArrayLength = twoArrayesSize;
		secondArrayLength = 0;
	}
	else
	{
		firstArrayLength = singleArrayLength;
		secondArrayLength = twoArrayesSize - singleArrayLength;
		firstPointer = startIndex;
		secondPointer = startIndex + singleArrayLength;
		int firstCounter = 0, secondCouter = 0;
		int* temp = new int[twoArrayesSize];
		int temp_counter = -1;
		while (firstCounter != firstArrayLength && secondCouter != secondArrayLength)
		{
			if (arr[firstPointer] <= arr[secondPointer])
			{
				temp[++temp_counter] = arr[firstPointer];
				++firstPointer;
				++firstCounter;
			}
			else {
				temp[++temp_counter] = arr[secondPointer];
				++secondPointer;
				++secondCouter;
			}
		}
		while (firstCounter < firstArrayLength)
		{
			temp[++temp_counter] = arr[firstPointer];
			++firstPointer;
			++firstCounter;
		}
		while (secondCouter < secondArrayLength)
		{
			temp[++temp_counter] = arr[secondPointer];
			++secondPointer;
			++secondCouter;
		}
		for (int i = startIndex, j = 0; i < startIndex + twoArrayesSize; i++, j++)
		{
			arr[i] = temp[j];
		}
		delete[] temp;
	}
}

void swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}