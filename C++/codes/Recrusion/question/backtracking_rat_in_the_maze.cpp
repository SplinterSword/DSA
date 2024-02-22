#include <iostream>
using namespace std;

bool issafe(int** arr[], int x, int y, int n)
{
    if (x < n and y < n)
    {
        if (arr[x][y] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool ratinthemaze(int** arr[], int x, int y, int** solarr[], int n)
{

    if (x == n - 1 and y == n - 1)
    {
        solarr[x][y] == 1;
        return true;
    }

    if (issafe(arr, x, y, n))
    {
        solarr[x][y] == 1;
        if (ratinthemaze(arr, x + 1, y, solarr, n))
        {
            return true;
        }
        else if (ratinthemaze(arr, x, y + 1, solarr, n))
        {
            return true;
        }
        solarr[x][y] == 0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int** arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int** solarr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solarr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solarr[i][j] = 0;
        }
    }

    if (ratinthemaze(arr, 0, 0, solarr, n))
    { 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solarr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}