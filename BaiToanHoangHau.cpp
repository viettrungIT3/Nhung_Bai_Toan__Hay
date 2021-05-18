#include <bits/stdc++.h>
using namespace std;

/*
    Bài toán: Đếm số lượng giá trị "Hoàng Hậu" trên một ma trận. Một phần tử đc gọi
    là "Hoàng Hậu" khí nó lớn nhất trên hàng, tên cột và 2 đg chéo chính đia qua nó.
*/

bool checkColum(int a[][10], int n, int num, int pos)
{
	for (int i = 0; i < n; i++)
		if (a[i][pos] > num)
			return false;
	return true;
}

bool checkDgCheo(int a[][10], int n, int m, int num, int posi, int posj)
{
	int i;
	int j;
	// chạy về góc phần tư thứ 2
	i = posi;
	j = posj;
	while (i >= 0 && j >= 0)
	{
		if (a[i][j] > num)
			return false;
		i--;
		j--;
	}
	// chạy về góc phần tư thứ 3
	i = posi;
	j = posj;
	while (i < n && j >= 0)
	{
		if (a[i][j] > num)
			return false;
		i++;
		j--;
	}
	// chạy về góc phần tư thứ 4
	i = posi;
	j = posj;
	while (i < n && j < m)
	{
		if (a[i][j] > num)
			return false;
		i++;
		j++;
	}
	// chạy về góc phần tư thứ 1
	i = posi;
	j = posj;
	while (i >= 0 && j < n)
	{
		if (a[i][j] > num)
			return false;
		i--;
		j++;
	}
	return true;
}

void FindQueen(int a[][10], int n, int m)
{
	int count = 0;
		cout << "\nso can tim: ";
	for (int i = 0; i < n; i++)
	{
		int max = a[i][0];
		for (int j = 0; j < m; j++)
		{
			if (max < a[i][j])
				max = a[i][j];
		}
		for (int j = 0; j < m; j++)
			if (max == a[i][j])
				if (checkColum(a, n, max, j))
					if (checkDgCheo(a, n, m, max, i, j))
					{
						cout << a[i][j] << " ";
						count++;
					}
	}
	cout << "\nDem = " << count;
}

int main(int argc, char const *argv[])
{
	int a[10][10] = {{1, 2, 3, 4},
					 {2, 1, 5, 3},
					 {3, 2, 3, 3}};
	int n = 3, m = 4;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	FindQueen(a, n, m);
	return 0;
}
