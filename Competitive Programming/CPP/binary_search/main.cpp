#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>

using namespace std;

int n, k; array<int, 10000> a;

void khoitao()
{
    cout << "Nhap n la so phan tu cua mang: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = rand() % 10 + 1;
        cout << a[i] << "\t";
    }
    cout << endl;
}

void sort(int t, int s)
{
    int i = t; int j = s; int g = a[(t+s)/2];
    while (i < j)
    {
        while (a[i] < g) i++;
        while (a[j] > g) j--;
        if (i <= j)
        {
            int tg = a[i];
            a[i] = a[j];
            a[j] = tg;
            i++; j--;
        }
    }
    if (i < s) sort(i, s);
    if (j > t) sort (t, j);
}

void bisearch(int t, int s)
{
    if (a[t] = k)
        cout << "Vi tri cua k la: " << t << endl;
        else
        if (a[s] = k)
            cout << "Vi tri cua k la: " << s << endl;
            else
            {
                if (t != s)
                {
                    int g = (t+s)/2;
                    if (k < a[g])
                    bisearch(t, g);
                    else
                    if (k > a[g])
                    bisearch(g, s);
                }
            }

}

int main()
{
    system("cls");
    srand(time(0));
    khoitao();
    sort(1, n);
    cout << "Mang sau khi sap xep: " << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << "\t";
    cout << endl;
    cout << "Nhap k la phan tu can tim: ";
    cin >> k;
    bisearch(1, n);
    system("pause");
    return 0;
}
