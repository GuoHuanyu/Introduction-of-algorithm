#pragma once
#include<iostream>
class Sort
{
public:
	Sort();
	~Sort();
	static int insert_sort(int*, int);
	static int merge_sort(int*, int,int);
private:
	static int merge(int*, int, int, int);
};

