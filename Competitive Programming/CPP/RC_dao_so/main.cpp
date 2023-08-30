#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

long int n; string s, ps = "";

void dao(int l)
{
    if (l > 0)
    {
        dao(l-1);
    }
    ps = s[l] + ps;
}

int main()
{
    system("cls");
    cout << "N: ";
    cin >> n;
    cout << "So dao cua N la: ";
    ostringstream num2str;
    num2str << n;
    s = num2str.str();
    dao(s.length()-1);
    cout << ps;
    cout << endl;
    system("pause");
    return 0;
}
