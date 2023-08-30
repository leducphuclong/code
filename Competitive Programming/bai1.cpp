#include<iostream>

#define nln '\n'

using namespace std;

struct Product{
	int id, gia;
	string hoten;
};

int main()
{
	Product A;
	cout << "Nhap id: ";
	cin >> A.id;
	cout << "Nhap ho ten: ";
	cin.ignore();
	getline(cin, A.hoten, nln);
	cout << "Nhap gia: ";
	cin >> A.gia;
	cout << "----------------------------" << nln;
	cout << "Mo ta san pham: " << nln;
	cout << "Id: " << A.id << nln;
	cout << "Ho ten: " << A.hoten << nln;
	cout << "Gia: " << A.gia << nln;	
	return 0;
}