#pragma once
#include "Sort.h"
#include <limits>

Sort::Sort()
{

}

Sort::~Sort()
{
}
int Sort::insert_sort(int* array, int size)
{
	int key = -1;
	for (int j = 1; j < size; j++)
	{
		key = array[j];
		int i = j - 1;
		while (array[i]>key)
		{
			array[i + 1] = array[i];
			i--;
			if (i < 0)
				break;
		}
		array[i + 1] = key;
	}
	return 0;
}
int Sort::merge_sort(int* array, int left, int right)
{

	if (left < right)
	{
		int mid = (right + left) / 2;
		merge_sort(array, left, mid);
		merge_sort(array, mid + 1, right);
		merge(array, left, mid, right); //把left到right的元素排序好
	}
	return 0;
}
int Sort::merge(int* a, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1 + 1];//add a +∞ number
	int* R = new int[n2 + 1];//add a +∞ number
	for (int i = 0; i < n1; i++)
	{
		L[i] = a[left + i ];
	}
	for (int i = 0; i < n2; i++)
	{
		R[i] = a[mid + i+1];
	}
	L[n1] = std::numeric_limits<int>::max();
	R[n2] = std::numeric_limits<int>::max();
	int i = 0;
	int j = 0;
	for (int k = left; k <= right; k++)
	{
		if (L[i] <= R[j])
			a[k] = L[i++];
		else
			a[k] = R[j++];
	}
	return 0;
}