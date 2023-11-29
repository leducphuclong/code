//Điểm trong mặt phẳng Oxy:
// Nhập, xuất tọa độ
// Tính khoảng cách giữa 2 điểm:
#include <bits/stdc++.h>

using namespace std;

struct Diem {
	double x, y;
};

void nhap(Diem &p) {
	cin >> p.x >> p.y;
}

void xuat(Diem p) {
	cout << p.x << " " << p.y;
}

double khoang_cach (Diem a, Diem b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
	Diem A, B;
	nhap(A);
	nhap(B);
	cout << "Khoang cach giua A va B: " << fixed << setprecision(4) << khoang_cach(A, B) << endl;
	return 0;
}