#include <windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <array>


using namespace std;

fstream f1, f2;

void setsize(int x)
{
    HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX() ;
    font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(cons,0,font);
    font->dwFontSize.X = 8*x;
    font->dwFontSize.Y = 16*x;
    //font->FontWeight = 22;
    //font->FontFamily = FF_DECORATIVE;
    SetCurrentConsoleFontEx(cons,0,font);
}

void openf()
{
    f1.open("F:/danh_sach.inp", ios:: in);
}

void closef()
{
    f1.close();
}

    array<string, 45> ten;
    signed stt = 0;

void data()
{
    openf();
    while (!f1.eof())
    {
        stt++;
        getline(f1, ten[stt]);
    }
    closef();
}

void start()
{
    cout << endl;
    setsize(10);
    string xaus0 = "   Let 's start";
    string dau = "";
    int co = 0;
    while (co < 3)
    {
        system("cls");
        cout << "     RANDOM A1 " << endl;
        co++;
        if (co % 2 == 1)
            cout << xaus0;
        else
            cout << "";
        cout << endl;
        dau = dau + "  >>  ";
        cout << dau;
        sleep(1);
    }
    sleep(1.5);
    system("cls");
}

void random()
{

}

int main()
{
    start();
    data();
    random();
    getchar();
    return 0;
}
