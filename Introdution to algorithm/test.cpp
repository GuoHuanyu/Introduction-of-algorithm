#include<iostream>
#include<random>
#include<ctime>
#include"Sort.h"
#include"Graphl.h"
#include"matrix_multiplication.h"
#define N 20
int display(Graphl &gra);
int* randomArray(int Size);
int test_graphl();
int test_sort();
int test_matrix();
int main()
{
	//test_graphl();
	//test_sort();
	//test_matrix();
	return 0;
}
int display(Graphl &gra)
{
	for (int i = 1; i <gra.n(); i++)
	{
		int vertex;
		vertex = gra.first(i);
		std::cout << vertex << " ";
		while (1)
		{
			vertex = gra.next(i, vertex);
			if (vertex != gra.n())
				std::cout << vertex << " ";
			else
			{
				std::cout << std::endl;
				break;
			}
		}
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
int test_graphl()
{
	int num = 7;
	Graphl gral(num);
	gral.setEdge(1, 6, 1); gral.setEdge(2, 1, 1); gral.setEdge(3, 1, 1); gral.setEdge(3, 4, 1); gral.setEdge(3, 5, 1);
	gral.setEdge(4, 3, 1); gral.setEdge(4, 1, 1); gral.setEdge(5, 3, 1); gral.setEdge(6, 1, 1); gral.setEdge(6, 4, 1);
	display(gral);
	std::cout << "**********************" << std::endl;
	gral.setEdge(4, 3, 5);
	gral.setEdge(1, 6, 2);
	gral.setEdge(1, 3, 1);
	display(gral);
	std::cout << "**********************" << std::endl;
	gral.delEdge(1, 2);
	gral.delEdge(1, 3);
	gral.delEdge(1, 6);
	display(gral);
	return 0;
}
int test_sort()
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
	Sort::merge_sort(array, 0, N - 1);
	std::cout << "after mergesort" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << array[i] << " ";
		if ((i + 1) % 10 == 0)
			std::cout << std::endl;
	}
	return 0;
}
int test_matrix()
{
	Matrix Ma(2, 2);
	Matrix Mb(2, 2);
	int rows = 2;
	int cols = 2;
	std::vector<int>* a;
	a = new std::vector<int>[rows];
	a[0].push_back (1);
	a[0].push_back(1);
	a[1].push_back  (1); 
	a[1].push_back(0);
	Ma.InitOfMatrix(a);
	Mb.InitOfMatrix(a);
	Ma.display();
	Matrix Mc=Ma * Mb;
	Mc.display();
	return 0;
}