//Tam giác
#include <bits/stdc++.h>

using namespace std;

struct Tamgiac {
	double a, b, c;
	// vector<>
	// string;
};

void nhap(Tamgiac &t) {
	cout << "Nhap do dai 3 canh cua tam giac: ";
	cin >> t.a >> t.b >> t.c;
}

void xuat(const Tamgiac &t) {
	cout << "Cac canh cua tam giac: " << t.a << " " << t.b << " " << t.c << endl;
}

double chu_vi(const Tamgiac &t) {
	return t.a + t.b + t.c;
} 

double dien_tich(const Tamgiac &t) {
	double p = chu_vi(t) / 2;
	return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}

int main() {
	Tamgiac tamgiac;
	nhap(tamgiac);
	xuat(tamgiac);
	cout << "Chu vi tam giac: " << chu_vi(tamgiac) << endl;
	cout << "Dien tich tam giac: " << fixed << setprecision(2) << dien_tich(tamgiac) << endl;
	return 0;
}