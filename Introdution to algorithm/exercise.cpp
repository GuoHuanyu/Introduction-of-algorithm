#include<iostream>
#include<random>
#include<ctime>
#include"Sort.h"
#define N 20
int* randomArray(int);
/*
STL sort #include<algorithm>
time:n*lgn
1.partion
2.stable_partition
3.nth_element
4.partial_sort
5.sort
6.stable_sort
*/
int main()
{
	int* array = randomArray(N);
	if (array == NULL)
		return 0;
	std::cout.width(8);
	std::cout.setf(std::ios::left);
	std::cout << "before insertsort" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << array[i] << " ";
		if ((i + 1) % 10 == 0)
			std::cout << std::endl;
	}
	Sort::insert_sort(array, N);
	std::cout << "after insertsort" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << array[i] << " ";
		if ((i + 1) % 10 == 0)
			std::cout << std::endl;
	}

	array = randomArray(N);
	std::cout << "before mergesort" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << array[i] << " ";
		if ((i + 1) % 10 == 0)
			std::cout << std::endl;
	}
	Sort::merge_sort(array, 0, N-1);
	std::cout << "after mergesort" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << array[i] << " ";
		if ((i + 1) % 10 == 0)
			std::cout << std::endl;
	}
	return 0;


}
int* randomArray(int Size)
{
	if (Size == 0)
		return NULL;
	else
	{
		int* a = new int[Size];
		std::uniform_int_distribution<unsigned>u(0, 100);
		static std::default_random_engine e(time(NULL)); //static保证随机下去 而不是每次取随机数第一个值
		for (int i = 0; i < Size; i++)
			a[i] = u(e);
		return a;
	}
}