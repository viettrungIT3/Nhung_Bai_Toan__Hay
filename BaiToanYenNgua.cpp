#include <bits/stdc++.h>
using namespace std;

/*
    Bài toán: Đếm số lượng giá trị "Yên Ngựa" trên một ma trận. Một phần tử đc gọi
    là "Yên Ngựa" khí nó lớn nhất trên hàng, nhỏ nhất trên cột.
*/

bool checkColum(int a[][10], int n, int num, int pos)
{
    for (int i = 0; i < n; i++)
        if (a[i][pos] < num)
            return false;
    return true;
}

void FindHorse(int a[][10], int n, int m)
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
                {
                    cout << a[i][j] << " ";
                    count++;
                }
    }
    cout << "\nDem = " << count;
}

int main(int argc, char const *argv[])
{
    int a[10][10] = {{1, 2, 4, 5},
                     {2, 1, 5, 3},
                     {1, 2, 4, 3}};
    int n = 3, m = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    FindHorse(a, n, m);
    return 0;
}
