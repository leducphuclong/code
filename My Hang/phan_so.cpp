//Tính tổng, hiệu, tích, thương hai psố
//Kiểm tra phân số tối giản

#include <bits/stdc++.h>

using namespace std;

struct PhanSo {
	int tu, mau;
};

void nhap(PhanSo &p) {
	cout << "Nhap tu so: ";
	cin >> p.tu;
	do {
		cout << "Nhap mau so: ";
		cin >> p.mau;
	} while(p.mau == 0);
}

void xuat(PhanSo p) {
	cout << p.tu << "/" << p.mau;
}

void rutgon(PhanSo &p) {
	long long l = __gcd(p.tu, p.mau);
	p.tu /= l;
	p.mau /= l;
}

long long __lcm(int a, int b) {
	// a*b/gcd(a, b)
	return a/__gcd(a, b)*b;
}

PhanSo tong (PhanSo a, PhanSo b) {
	PhanSo t;
	int bcnn = __lcm(a.mau, b.mau);
	t.tu = a.tu * (bcnn / a.mau) + b.tu *(bcnn / b.mau);
	t.mau = bcnn;
	rutgon(t);
	return t;
}

PhanSo hieu(PhanSo a, PhanSo b) {
	PhanSo h;
	h.tu = a.tu * b.mau - b.tu * a.mau;
	h.mau = a.mau * b.mau;
	rutgon(h);
	return h;
}

PhanSo tich(PhanSo a, PhanSo b) {
	PhanSo n;
	rutgon(a), rutgon(b);
	n.tu = a.tu * b.tu;
	n.mau = a.mau * b.mau;
	rutgon(n);
	return n;
}

PhanSo thuong(PhanSo a, PhanSo b) {
	PhanSo c;
	rutgon(a), rutgon(b);
	c.tu = a.tu * b.mau;
	c.mau = a.mau * b.tu;
	rutgon(c);
	return c;
}

// Kiểm tra phân số tối giản
bool toi_gian(const PhanSo &p) {
	return __gcd(p.tu, p.mau) == 1;
}

int main() {
	PhanSo p1, p2;
	
	cout << "Nhap phan so thu nhat: " << endl;
	nhap(p1);
	
	cout << "Nhap phan so thu hai: " << endl;
	nhap(p2);
	
	cout << "\nPhan so thu nhat: ";
	xuat(p1);
	
	cout << "\nPhan so thu hai: ";
	xuat(p2);
	
	cout << "\nTong 2 phan so: ";
	PhanSo p3 = tong(p1, p2);
	xuat(p3);
	
	cout << "\nHieu 2 phan so: ";
	PhanSo p4 = hieu(p1, p2);
	xuat(p4);
	
	cout << "\nTich 2 phan so: ";
	PhanSo p5 = tich(p1, p2);
	xuat(p5);
	
	cout << "\nThuong 2 phan so: ";
	PhanSo p6 = thuong(p1, p2);
	xuat(p6);
	
	cout << endl;
	
	if(toi_gian(p1))
		cout << "P1 la phan so toi gian" << endl;
	else
		cout << "P1 kp la phan so toi gian" << endl;
		

	if(toi_gian(p2))
		cout << "P2 la phan so toi gian" << endl;
	else
		cout << "P2 kp la phan so toi gian" << endl;
	return 0;
}