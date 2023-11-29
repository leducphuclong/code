// /Đơn thức:
#include <bits/stdc++.h>

using namespace std;

struct Donthuc {
	int heso;
	double somu;
};

void nhap(Donthuc &p) {
	cout << "Nhap he so: ";
	cin >> p.heso;
	cout << "Nhap so mu: ";
	cin >> p.somu;
}

void xuat(Donthuc p) {
	cout << p.heso << "x^" << p.somu;
}

Donthuc tich(Donthuc a, Donthuc b) {
	Donthuc c;
	c.heso = a.heso * b.heso;
	c.somu = a.somu + b.somu;
	return c;
}

Donthuc thuong(Donthuc a, Donthuc b) {
	Donthuc d;
	d.heso = double(a.heso) / b.heso;
	d.somu = a.somu - b.somu;
	return d;
}

int main() {
	Donthuc P, Q;
	cout << "Nhap thong tin cho don thuc 1: " << endl;
	nhap(P);
	
	cout << "Nhap thong tin cho don thuc 2: " << endl;
	nhap(Q);
	
	cout << "Tich 2 don thuc: "; 
	Donthuc T = tich(P, Q);
	xuat(T);
	
	cout << "\nThuong 2 don thuc: ";
	Donthuc N = thuong(P, Q);
	xuat(N);
	return 0;
}