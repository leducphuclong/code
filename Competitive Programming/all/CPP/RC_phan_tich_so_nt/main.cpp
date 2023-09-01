#include <iostream>
#include <fstream>
#include <array>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

fstream f1,f2; int n;  array<long int, 10000> a; string result = "";
int d = 2;

void laydulieu()
{
    f1.open("RC_phan_tich_so_nt.inp", ios:: in);
    f1 >> n;
    f1.close();
}

bool check4prime(int n)
{
    if (n < 2) return false;
        for (int i = 2; i <= round(sqrt(n)); i++)
        if (n % i == 0) return false;
    return true;
}

void put_out()
{
    f2 << result <<  endl;
}


void dissociation(int t)
{
    for (int run = d; run <= n ; run++)
    {
        if (n == t)
        {
            put_out();
            return;
        }
        if ((t + run) > n)
        {
            return;
        }
        else
            if (check4prime(run))
            {
                string ch = to_string(run);
                result = result + ch + " ";
                d = run;
                while (!check4prime(d)) d++;
                dissociation(t+run);
                result.erase(result.length() - ch.length() - 1 , ch.length() + 1);
            }
    }
}

void xuli()
{
    f2.open("RC_phan_tich_so_nt.out", ios:: out);
    dissociation(0);
    f2.close();
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
