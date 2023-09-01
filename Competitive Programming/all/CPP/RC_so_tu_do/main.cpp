#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

struct ar
{
    int a[10000];
    int l = 0;
};

int n, k, isyn, irs = 0;;  fstream f1, f2; bool pick[10000] = {0};
int ak[10000] = {0}; ar syn[10000]; int ori[10000] = {0};   string result[10000] = {""};

void laydulieu()
{
    f1.open("RC_so_tu_do.inp", ios:: in);
    f1 >> n;
    //cout << n << endl;
    f1.close();
}

void put_out()
{
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++)
            for ( int l = 1; l <= k; l++)
                if ((ak[i] + ak[j]) == ak[l])
                {
                        return;
                }
    isyn++;
    for (int u = 1; u <= k; u++)
    {
        syn[isyn].a[u] = ak[u];
       // cout << ak[u] << "\t";
    }
    //cout << endl;
    syn[isyn].l = k;
}

void go(int run)
{
    if (run > n)
        put_out();
    else
        {
//            for (int i)
            if (!pick[run])
            {
                k++;
                ak[k] = run;
                pick[run] = 1;
            }
            go(run+1);
            k--;    pick[run] = 0;
            go(run+1);
        }
}

bool ch4ar(ar x)
{
    for (int i = 1; i <= x.l; i++)
        if (ori[x.a[i]] == 1)   return 0;
    return 1;
}

void show_out()
{
    f2.open("RC_so_tu_do.out", ios:: out);
    f2 << irs << endl;
    for (int i = 1; i <= irs; i++)
        f2 << result[i] << endl;
    f2.close();
}

void synthetic()
{
    while (n > 0)
    {
        int lmax = 0;   int lcmax = 0;
        for (int i = 1; i <= isyn; i++)
            if ((syn[i].l > lmax) && (ch4ar(syn[i])))
            {
                lmax = syn[i].l;
                lcmax = i;
            }
        for (int i = 1; i <= isyn; i++)
            if (i == lcmax)
            {
                irs++;
                for (int j = 1; j <= syn[i].l; j++)
                {
                    ori[syn[i].a[j]] = 1;
                    string chap = to_string(syn[i].a[j]);
                    result[irs] = result[irs] + chap + "\t";
                }
                n = n - syn[i].l;
                break;
            }
    }
    show_out();
}

void xuli()
{
    go(1);
    synthetic();
}

int main()
{
    system("cls");
    laydulieu();
    xuli();
    cout << "Chuong trinh da chay xong!" << endl;
    system("pause");
    return 0;
}
