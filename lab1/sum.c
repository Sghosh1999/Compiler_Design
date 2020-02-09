#include <bits/stdc++.h>
using namespace std;

int dat(int data, int a[], int i, int n)
{
    if (data != 0 && i >= n)
        return 0;
    else if (data < 0)
        return 0;
    else if (data == 0)
        return 1;
    else
    {
        return dat(data - a[i], a, i + 1, n) + dat(data, a, i + 1, n);
    }
}

int main()
{
    int a[5];
    int b;
    for (int i = 0; i < 5; i++)
        cin >> a[i];
    cin >> b;
    cout << dat(b, a, 0, 5) << endl;
    return 0;
}