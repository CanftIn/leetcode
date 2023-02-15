#include <iostream>
#include <vector>

using namespace std;

//The main code is from
//https://github.com/haoel/leetcode/blob/master/algorithms/cpp/rotateImage/rotateImage.cpp#L32

/*
int** rotate(int** a)
{
	int** m;
	for (int j = 2, int z = 2; j >= 0, z >= 0; --j, --z)
	{
		m[z][j] = a[z][z];
	}
	return m;
}
*/

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int a = 0;
	int b = n - 1;
	while (a<b) {
		for (int i = 0; i<(b - a); ++i) {
			swap(matrix[a][a + i], matrix[a + i][b]);
			swap(matrix[a][a + i], matrix[b][b - i]);
			swap(matrix[a][a + i], matrix[b - i][a]);
		}
		++a;
		--b;
	}
}

void printMatrix(vector<vector<int> > &matrix)
{
	for (int i = 0; i<matrix.size(); i++) {
		for (int j = 0; j< matrix[i].size(); j++) {
			printf("%3d ", matrix[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

/*
int main()
{
	int** a;
	
	a = new int *[3];            
	for (int i = 0; i<3; i++)
	{
		a[i] = new int[3];
	}

//	a =
//	{
//		{1, 2, 3},
//		{4, 5, 6},
//		{7, 8, 9}
//	};

	a[0][0] = 1;
	a[0][1] = 2;
	a[0][2] = 3;
	a[1][0] = 4;
	a[1][1] = 5;
	a[1][2] = 6;
	a[2][0] = 7;
	a[2][1] = 8;
	a[2][2] = 9;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	int **m = rotate(a);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
*/

int main(int argc, char** argv)
{
	int n = 2;
	if (argc>1) {
		n = atoi(argv[1]);
	}
	vector< vector<int> > matrix;
	for (int i = 1; i <= n; i++) {
		vector<int> v;
		for (int j = 1; j <= n; j++) {
			v.push_back((i - 1)*n + j);
		}
		matrix.push_back(v);
	}

	printMatrix(matrix);
	rotate(matrix);
	printMatrix(matrix);

	return 0;
}