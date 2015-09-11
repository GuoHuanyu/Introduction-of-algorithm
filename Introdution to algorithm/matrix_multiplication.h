
#include<iostream>
#include<vector>
class Matrix 
{

public:
	std::vector<int>* matrix;
	int rows, cols;
	Matrix(){}
	Matrix(int row, int col){
		matrix = new std::vector<int>[row];
		rows = row;
		cols = col;
	}
	~Matrix(){ 
		delete[]matrix; 
	}
	Matrix(const Matrix& M)
	{
		rows = M.rows;
		cols = M.cols;
		matrix = new std::vector<int>[M.rows];
		for (int i = 0; i < M.rows; i++)
		for (int j = 0; j < M.cols; j++)
			matrix[i].push_back(M.matrix[i][j]);
	}
	friend const Matrix operator+(const Matrix& Ma, const Matrix& Mb)//使用成员函数重载加号运算符
	{
		Matrix	M(Ma.rows, Mb.cols );
		for (int i = 0; i < Ma.rows; i++)
		for (int j = 0; j < Mb.cols; j++)
			M.matrix[i].push_back( Ma.matrix[i][j] + Mb.matrix[i][j]);
		return M;
	}
	friend const  Matrix operator-(const Matrix& Ma, const Matrix& Mb)//使用成员函数重载加号运算符
	{
		Matrix	M(Ma.rows, Mb.cols);
		for (int i = 0; i < Ma.rows; i++)
		for (int j = 0; j < Mb.cols; j++)
			M.matrix[i].push_back( Ma.matrix[i][j] - Mb.matrix[i][j]);
		return M;
	}
	friend const Matrix operator*(const Matrix &Ma, const Matrix &Mb)//使用成员函数重载加号运算符
	{
		if (Ma.rows >= 2 && Mb.rows >= 2)
		{
			Matrix temp = (Mb.A1() - Mb.A3());
			Matrix P1 = Ma.A0()*(Mb.A1() - Mb.A3());//P1=a*(f-h)
			Matrix P2 = (Ma.A0() + Ma.A1())*Mb.A3();//P2=(a+b)*h;
			Matrix P3 = (Ma.A2() + Ma.A3())*Mb.A0();//p3=(c+d)*e;
			Matrix P4 = Ma.A3()*(Mb.A3() - Mb.A0());//p4=d*(g-e);
			Matrix P5 = (Ma.A0() + Ma.A3())*(Mb.A0() + Mb.A3());//p5=(a+d)*(e+h);
			Matrix P6 = (Ma.A1() - Ma.A3())*(Mb.A2() + Mb.A3());//p6=(b-d)*(g+h);
			Matrix P7 = (Ma.A0() - Ma.A2())*(Mb.A0() + Mb.A1());//p7=(a-c)*(e+f);
			Matrix r = P5 + P4 - P2 + P6;
			Matrix s = P1 + P2;
			Matrix t = P3 + P4;
			Matrix u = P5 + P1 - P3 - P7;
			return mergeMatrix(r, s, t, u);
		}
		else
		{
			Matrix	M(Ma.rows, Mb.cols);
			for (int i = 0; i <Ma.rows; i++)
			{
				for (int j = 0; j < Mb.cols; j++)
				{
					M.matrix[i].push_back (0);
				}
			}
			for (int i = 0; i < Ma.rows; i++)
			{
				for (int j = 0; j < Mb.cols; j++)
				{
					for (int k = 0; k <Ma.cols; k++)
						M.matrix[i][j] += Ma.matrix[i][k] * Mb.matrix[k][j];
				}
			}
			return M;
		}
	}
	Matrix A0()const
	{
		Matrix	M(rows / 2, cols / 2);
		for (int i = 0; i < rows / 2;i++)
		for (int j = 0; j < cols / 2; j++)
			M.matrix[i].push_back(matrix[i][j]);
		return M;
	}
	Matrix A1()const
	{
		Matrix	M(rows / 2, cols / 2);
		for (int i = 0; i < rows / 2; i++)
		for (int j = cols / 2; j < cols; j++)
			M.matrix[i].push_back(matrix[i][j]);
		return M;
	}
	Matrix A2()const
	{
		Matrix	M(rows / 2, cols / 2);
		for (int i = rows / 2; i < rows ; i++)
		for (int j = 0; j < cols / 2; j++)
			M.matrix[i - rows / 2].push_back(matrix[i][j]);
		return M;
	}
	Matrix A3()const
	{
		Matrix	M(rows / 2, cols / 2);
		for (int i = rows / 2; i < rows; i++)
		for (int j = cols / 2; j < cols; j++)
			M.matrix[i-rows / 2].push_back(matrix[i][j]);
		return M;
	}
	static Matrix mergeMatrix(Matrix& A0, Matrix& A1, Matrix& A2, Matrix& A3)
	{
		Matrix M(A0.rows * 2, A0.rows * 2);
		for (int i = 0; i < A0.rows ; i++)
		for (int j = 0; j < A0.cols; j++)
		{
			M.matrix[i].push_back( A0.matrix[i][j]);
			M.matrix[i + A0.rows].push_back(A2.matrix[i][j]);

		}
		for (int i = 0; i < A0.rows; i++)
		for (int j = 0; j < A0.cols; j++)
		{

			M.matrix[i].push_back(A1.matrix[i][j]);
			M.matrix[i + A0.rows].push_back(A3.matrix[i][j]);

		}
		return M;
	}
	int InitOfMatrix(std::vector<int>* M)
	{
		for (auto i = 0; i < rows; i++)
		{
			for (auto j = 0; j < cols; j++)
				matrix[i].push_back (M[i][j]);
		}
		return 0;
	}

	int display()
	{
		for (auto i = 0; i < rows; i++)
		{
			for (auto j = 0; j < cols; j++)
				std::cout << matrix[i][j] << " ";
			std::cout << std::endl;
		}
		return 0;
	}
	/*
	static Matrix standmultipli(Matrix& Ma, Matrix& Mb)
	{
		Matrix Mc(Ma.rows, Mb.cols);
		for (int i = 0; i < Ma.rows; i++)
		{
			for (int j = 0; j < Mb.cols; j++)
			{
				Mc.matrix[i][j] = 0;
			}
		}
		for (int i = 0; i < Ma.rows; i++)
		{
			for (int j = 0; j < Mb.cols; j++)
			{
				for (int k = 0; k < Ma.cols; k++)
					Mc.matrix[i][j] += Ma.matrix[i][k] * Mb.matrix[k][j];
			}
		}
		return Mc;
	}
	//Strassen矩阵乘法要求ｎ是２的幂 
	//所需的8次乘法降低为7次，将计算时间从O(nE3)降低为O(nE2.81)
	static Matrix Strassenmultipli(Matrix& Ma, Matrix& Mb)
	{
		if (Ma.rows >= 2 && Mb.rows >= 2)
		{

			Matrix P1 = Ma.A0()*(Mb.A1() - Mb.A3());//P1=a*(f-h)
			Matrix P2 = (Ma.A0() + Ma.A1())*Mb.A3();//P2=(a+b)*h;
			Matrix P3 = (Ma.A2() + Ma.A3())*Mb.A0();//p3=(c+d)*e;
			Matrix P4 = Ma.A3()*(Mb.A3() - Mb.A0());//p4=d*(g-e);
			Matrix P5 = (Ma.A0() + Ma.A3())*(Mb.A0() + Mb.A3());//p5=(a+d)*(e+h);
			Matrix P6 = (Ma.A1() - Ma.A3())*(Mb.A2() + Mb.A3());//p6=(b-d)*(g+h);
			Matrix P7 = (Ma.A0() - Ma.A2())*(Mb.A0() + Mb.A1());//p7=(a-c)*(e+f);
			Matrix r = P5 + P4 - P2 + P6;
			Matrix s = P1 + P2;
			Matrix t = P3 + P4;
			Matrix u = P5 + P1 - P3 - P7;
			return mergeMatrix(r, s, t, u);
		}
		else
			return standmultipli(Ma, Mb);
	}*/
};