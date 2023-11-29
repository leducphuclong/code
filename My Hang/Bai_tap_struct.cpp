//////PHÂN SỐ
////Nhập, xuất pso
////Rút gọn pso
////Tính tổng, hiệu, tích, thương hai psố
////Kiểm tra phân số tối giản
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct PhanSo {
//	int tu, mau;
//};
//
//void nhap(PhanSo &p) {
//	cout << "Nhap tu so: ";
//	cin >> p.tu;
//	do {
//		cout << "Nhap mau so: ";
//		cin >> p.mau;
//	} while(p.mau == 0);
//}
//
//void xuat(PhanSo p) {
//	cout << p.tu << "/" << p.mau;
//}
//
//void rutgon(PhanSo &p) {
//	long long l = __gcd(p.tu, p.mau);
//	p.tu /= l;
//	p.mau /= l;
//}
//
//PhanSo tong (PhanSo a, PhanSo b) {
//	PhanSo t;
//	t.tu = a.tu * b.mau + b.tu * a.mau;
//	t.mau = a.mau * b.mau;
//	rutgon(t);
//	return t;
//}
//
//PhanSo hieu(PhanSo a, PhanSo b) {
//	PhanSo h;
//	h.tu = a.tu * b.mau - b.tu * a.mau;
//	h.mau = a.mau * b.mau;
//	rutgon(h);
//	return h;
//}
//
//PhanSo tich(PhanSo a, PhanSo b) {
//	PhanSo n;
//	n.tu = a.tu * b.tu;
//	n.mau = a.mau * b.mau;
//	rutgon(n);
//	return n;
//}
//
//PhanSo thuong(PhanSo a, PhanSo b) {
//	PhanSo c;
//	c.tu = a.tu * b.mau;
//	c.mau = a.mau * b.tu;
//	rutgon(c);
//	return c;
//}
//
//Kiểm tra phân số tối giản
//bool toi_gian(PhanSo p) {
//	return __gcd(p.tu, p.mau) == 1;
//}
//
//int main() {
//	PhanSo p1, p2;
//	
//	cout << "Nhap phan so thu nhat: " << endl;
//	nhap(p1);
//	
//	cout << "Nhap phan so thu hai: " << endl;
//	nhap(p2);
//	
//	cout << "\nPhan so thu nhat: ";
//	xuat(p1);
//	
//	cout << "\nPhan so thu hai: ";
//	xuat(p2);
//	
//	cout << "\nTong 2 phan so: ";
//	PhanSo p3 = tong(p1, p2);
//	xuat(p3);
//	
//	cout << "\nHieu 2 phan so: ";
//	PhanSo p4 = hieu(p1, p2);
//	xuat(p4);
//	
//	cout << "\nTich 2 phan so: ";
//	PhanSo p5 = tich(p1, p2);
//	xuat(p5);
//	
//	cout << "\nThuong 2 phan so: ";
//	PhanSo p6 = thuong(p1, p2);
//	xuat(p6);
//	
//	cout << endl;
//	
//	if(toi_gian(p1))
//		cout << "P1 la phan so toi gian" << endl;
//	else
//		cout << "P1 kp la phan so toi gian" << endl;
//		
//
//	if(toi_gian(p2))
//		cout << "P2 la phan so toi gian" << endl;
//	else
//		cout << "P2 kp la phan so toi gian" << endl;
//	return 0;
//}

////Điểm trong mặt phẳng Oxy:
//Nhập, xuất tọa độ
//Tính khoảng cách giữa 2 điểm:
//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct Diem {
//	double x, y;
//};
//
//void nhap(Diem &p) {
//	cin >> p.x >> p.y;
//}
//
//void xuat(Diem p) {
//	cout << p.x << " " << p.y;
//}
//
//double khoang_cach (Diem a, Diem b) {
//	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
//}
//
//int main() {
//	Diem A, B;
//	nhap(A);
//	nhap(B);
//	cout << "Khoang cach giua A va B: " << fixed << setprecision(4) << khoang_cach(A, B) << endl;
//	return 0;
//}
//0 0 0 5
//0 199 5 6 

////Tam giác
//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct Tamgiac {
//	double a, b, c;
//};
//
//void nhap(Tamgiac &t) {
//	cout << "Nhap do dai 3 canh cua tam giac: ";
//	cin >> t.a >> t.b >> t.c;
//}
//
//void xuat(Tamgiac t) {
//	cout << "Cac canh cua tam giac: " << t.a << " " << t.b << " " << t.c << endl;
//}
//
//double chu_vi(Tamgiac t) {
//	return t.a + t.b + t.c;
//} 
//
//double dien_tich(Tamgiac t) {
//	double p = chu_vi(t) / 2;
//	return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
//}
//
//int main() {
//	Tamgiac tamgiac;
//	nhap(tamgiac);
//	xuat(tamgiac);
//	cout << "Chu vi tam giac: " << chu_vi(tamgiac) << endl;
//	cout << "Dien tich tam giac: " << fixed << setprecision(2) << dien_tich(tamgiac) << endl;
//	return 0;
//}

////Đơn thức:
//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct Donthuc {
//	int heso;
//	double somu;
//};
//
//void nhap(Donthuc &p) {
//	cout << "Nhap he so: ";
//	cin >> p.heso;
//	cout << "Nhap so mu: ";
//	cin >> p.somu;
//}
//
//void xuat(Donthuc p) {
//	cout << p.heso << "x^" << p.somu;
//}
//
//Donthuc tich(Donthuc a, Donthuc b) {
//	Donthuc c;
//	c.heso = a.heso * b.heso;
//	c.somu = a.somu + b.somu;
//	return c;
//}
//
//Donthuc thuong(Donthuc a, Donthuc b) {
//	Donthuc d;
//	d.heso = double(a.heso) / b.heso;
//	d.somu = a.somu - b.somu;
//	return d;
//}
//
//int main() {
//	Donthuc P, Q;
//	cout << "Nhap thong tin cho don thuc 1: " << endl;
//	nhap(P);
//	
//	cout << "Nhap thong tin cho don thuc 2: " << endl;
//	nhap(Q);
//	
//	cout << "Tich 2 don thuc: "; 
//	Donthuc T = tich(P, Q);
//	xuat(T);
//	
//	cout << "\nThuong 2 don thuc: ";
//	Donthuc N = thuong(P, Q);
//	xuat(N);
//	return 0;
//}

////Mảng phân số:
//Nhập/Xuất n phân số
//Rút gọn mọi phân số
//Đếm số lượng phân số âm / dương trong mảng
//Tìm phân số dương đầu tiên trong mảng
//Tìm phân số nhỏ nhất / lớn nhất trong mảng


//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct PhanSo {
//	int tu, mau;
//};
//
//void nhap(PhanSo &p) {
//	cout << "Nhap tu so: ";
//	cin >>p.tu;
//	do {
//		cout << "Nhap mau so: ";
//		cin >> p.mau;
//	} while(p.mau == 0);
//}
//
//void xuat(PhanSo p) {
//	cout << p.tu << "/" << p.mau;
//}
//
//void rutgon(PhanSo &p) {
//	long long l = __gcd(p.tu, p.mau);
//	p.tu /= l;
//	p.mau /= l;
//}
//
//void dem_am_duong (PhanSo ds[], int n, int &dem_am, int &dem_duong) {
//	dem_am = dem_duong = 0;
//	for(int i = 0; i < n; i++) {
//		if(ds[i].tu * ds[i].mau < 0) {
//			dem_am += 1;
//		}
//		else if (ds[i].tu * ds[i].mau > 0) 
//			dem_duong += 1;
//	}
//}
//
//PhanSo phansoduong (PhanSo ds[], int n) {
//	for(int i = 0; i < n; i++) {
//		if(ds[i].tu * ds[i].mau > 0) 
//			return ds[i];
//	}
//	return {0, 1};
//}
//
//int main() {
//	cout << "Nhap so luong phan so: ";
//	int n; cin >> n;
//	
//	PhanSo ds[n];
//	
//	
//	for(int i = 0; i < n; i++) {
//		cout << "Nhap thong tin phan so thu: " << i + 1 << ": " << endl;
//		nhap(ds[i]);
//		rutgon(ds[i]);
//	}
//	
//	cout << "Danh sach phan so da nhap: " << endl;
//	for(int i = 0; i < n; i++) {
//		xuat(ds[i]);
//		cout << " ";
//	}
//	
//	int dem_am, dem_duong;
//	dem_am_duong(ds, n, dem_am, dem_duong);
//	cout << "\nSo luong phan so am: " << dem_am << endl;
//	cout << "So luong phan so duong: " << dem_duong << endl;
//	
//	cout << "Phan so duong dau tien la: ";
//	PhanSo m = phansoduong(ds, n);
//	xuat(m);
//	
//	return 0;
//}

////Quản lý sv hệ tín chỉ: Ktra lần 2 - KTLT nhóm 14: CORRECT
//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//struct SinhVien {
//	float mon1, mon2, mon3, dtb;
//	string diemchu;
//};
//
//int main() {
//	int n; cin >> n;
//	SinhVien sv[n];
//	for(int i = 0; i < n; i++) 
//		cin >> sv[i].mon1 >> sv[i].mon2 >> sv[i].mon3;
//	
//	for(int i = 0; i < n; i++) 
//		sv[i].dtb = (sv[i].mon1 + sv[i].mon2 + sv[i].mon3) / 3;
//	
//	//sap xep giam dan cua dtb
//	for(int i = 0; i < n -1 ; i++) {
//		for(int j = i + 1; j < n; j++) {
//			if(sv[i].dtb < sv[j].dtb) {
//				float tam = sv[i].dtb;
//				sv[i].dtb = sv[j].dtb;
//				sv[j].dtb = tam;
//			}
//		}
//	}
//	
//	for(int i = 0; i < n; i++) {
//		if (sv[i].dtb < 4.0) 
//			cout << fixed << setprecision(2) << sv[i].dtb << " " << "F" << endl;
//		else if (sv[i].dtb >= 4.0 && sv[i].dtb < 5.5)
//			cout << fixed << setprecision(2) << sv[i].dtb << " " << "D" << endl; 
//		else if (sv[i].dtb >= 5.5 && sv[i].dtb < 7.0)
//			cout << fixed << setprecision(2) << sv[i].dtb << " " << "C" << endl;
//		else if (sv[i].dtb >= 7.0 && sv[i].dtb < 8.5)
//			cout << fixed << setprecision(2) << sv[i].dtb << " " << "B" << endl;
//		else if (sv[i].dtb >= 8.5 && sv[i].dtb <= 10)
//			cout << fixed << setprecision(2) << sv[i].dtb << " " << "A" << endl;
//	}
//	return 0;
//}
