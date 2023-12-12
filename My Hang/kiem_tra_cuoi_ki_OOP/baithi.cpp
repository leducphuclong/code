#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

class Computer {
private:
    string mamt;
    string hangsx;
    int namsx;
    float giaban;

public:
    Computer(string mamt = "A17", string hangsx = "Intel", int namsx = 2018, float giaban = 10) {
        this->mamt = mamt;
        this->hangsx = hangsx;
        this->namsx = namsx;
        this->giaban = giaban;
    }

    void setmamt(const string& mamt) {
        this->mamt = mamt;
    }

    void sethangsx(const string& hangsx) {
        this->hangsx = hangsx;
    }

    void setnamsx(int namsx) {
        this->namsx = namsx;
    }

    void setgiaban(float giaban) {
        this->giaban = giaban;
    }

    string getmamt() const {
        return mamt;
    }

    string gethangsx() const {
        return hangsx;
    }

    int getnamsx() const {
        return namsx;
    }

    float getgiaban() const {
        return giaban;
    }

    void nhap() {
        cout << "Ma may tinh: ";
        getline(cin, mamt);
        cout << "Hang san xuat: ";
        getline(cin, hangsx);
        cout << "Nam san xuat: ";
        cin >> namsx;
        cout << "Gia ban: ";
        cin >> giaban;
        cin.ignore();
    }

    void xuat() const {
        cout << "Ma may tinh: " << getmamt() << endl;
        cout << "Hang san xuat: " << gethangsx() << endl;
        cout << "Nam san xuat: " << getnamsx() << endl;
        cout << "Gia ban: " << getgiaban() << endl;
    }
};

class Laptop : public Computer {
private:
    float cannang;
    float doday;
    float kichthuocmh;
    string hdh;
    int namhtai;

public:
    Laptop(float cannang = 5.5, float doday = 20, float kichthuocmh = 17.5, string hdh = "Windows 11", int namhtai = 2023)
        : Computer(), cannang(cannang), doday(doday), kichthuocmh(kichthuocmh), hdh(hdh), namhtai(namhtai) {}

    void setcannang(float cannang) {
        this->cannang = cannang;
    }

    void setdoday(float doday) {
        this->doday = doday;
    }

    void setkichthuocmh(float kichthuocmh) {
        this->kichthuocmh = kichthuocmh;
    }

    void sethdh(const string& hdh) {
        this->hdh = hdh;
    }

    float getcannang() const {
        return cannang;
    }

    float getdoday() const {
        return doday;
    }

    float getkichthuocmh() const {
        return kichthuocmh;
    }

    string gethdh() const {
        return hdh;
    }

    int getnamhtai() {
        return namhtai;
    }

    void nhap() {
        Computer::nhap();
        cout << "Can nang (gram): ";
        cin >> cannang;
        cout << "Do day (mm): ";
        cin >> doday;
        cout << "Kich thuoc man hinh (mm): ";
        cin >> kichthuocmh;
        cin.ignore();
        cout << "He dieu hanh: ";
        getline(cin, hdh);
        cout << "Nam hien tai: ";
        cin >> namhtai;
        cin.ignore();
        cout << endl;
    }

    float giatriconlai() const {
        int namsd = namhtai - getnamsx();
        float giatriconlai;
        if (hdh.find("Windows") != string::npos) {
            giatriconlai = getgiaban() - namsd * 0.1f * getgiaban();
        } else {
            giatriconlai = getgiaban() - namsd * 0.05f * getgiaban();
        }

        return giatriconlai > 0 ? giatriconlai : 0;
    }

    void xuat() const {
        cout << "THONG TIN CUA LAPTOP: " << endl;
        Computer::xuat();
        cout << "Can nang: " << getcannang() << endl;
        cout << "Do day: " << getdoday() << endl;
        cout << "Kich thuoc man hinh: " << getkichthuocmh() << endl;
        cout << "He dieu hanh: " << gethdh() << endl;
        cout << "Gia tri con lai: " << fixed << setprecision(2) << giatriconlai() << endl;
        cout << endl;
    }

    bool operator >( Laptop other) {
        return giatriconlai() > other.giatriconlai();
    }
};

class Quanly {
private:
    Laptop a[50];
    int n;

public:
    void nhapql();
    void sapxeptang();
    void sdnhieunhat();
};

void Quanly::nhapql() {
    bool check;
    do {
        cout << "Nhap so luong may tinh: ";
        cin >> n;

        if (n <= 0 || n > 50)
            cout << "Nhap so luong sai. Hay nhap lai! \n"
                 << endl;
    } while (n <= 0 || n > 50);

    cin.ignore();

    for (int i = 0; i < n; i++) {
        do {
            check = false;
            a[i].nhap();
            for (int j = 0; j < i; j++) {
                if (a[i].getmamt() == a[j].getmamt()) {
                    cout << "Ma may tinh bi trung. Vui long nhap lai: ";
                    check = true;
                    break;
                }
            }
        } while (check == true);
    }
    cout << endl;
}

void Quanly::sapxeptang() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                Laptop tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }

    for (int i = 0; i < n; i++){
        a[i].xuat();
    }
        
}

void Quanly::sdnhieunhat() {
    int maxnamsd = 0;
    for (int i = 0; i < n; i++) {
        int namsd = a[i].getnamhtai() - a[i].getnamsx();
        if (namsd > maxnamsd) {
            maxnamsd = namsd;
        }
    }

    for (int i = 0; i < n; i++) {
        int namsd = a[i].getnamhtai() - a[i].getnamsx();
        if (namsd == maxnamsd) {
            a[i].xuat();
        }
    }
}

int main() {
    Quanly ql;
    ql.nhapql();
    cout << "Sau khi sap xep tang theo gia tri con lai: " << endl;
    ql.sapxeptang();
    cout << "Cac san pham su dung nhieu nhat la: " << endl;
    ql.sdnhieunhat();

    return 0;
}

