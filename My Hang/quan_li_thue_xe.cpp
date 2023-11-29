#include <iostream>

using namespace std;

class thuexe {
	private:
		string hoten;
	protected:
		int sogiothue;
	public:
		bool loaixe;
		void nhap() {
			cout << "Nhap ho ten nguoi thue xe: ";
			cin.ignore();
			getline(cin, hoten);
			cout << "Nhap so gio thue: ";
			cin >> sogiothue;
		}
		
		void xuat() {
			cout << hoten << "\t" << sogiothue << endl;
		}

		long long getNum(string str) {
			// str = "xe 100 pk" -> 100
			long long num = 0;
			for (auto v : str)
				if (isdigit(v))
					num = num*10+(v-'0'); // v-'0' to convert v from char to integer
			return num;
		}
};
class xedap:public thuexe {
	private:
		string loaixedap;
	public:
		string get_loaixedap() {
			return loaixedap;
		}
		void set_loaixedap(const string& new_loai_xe_dap) {
			loaixedap = new_loai_xe_dap;
		}
		void nhap_xedap() {
			nhap();
			cout << "\nNhap loai xe dap: ";
			cin.ignore();
			getline(cin, loaixedap);
		}
		
		void xuat_xedap() {
			xuat();
			cout << "Loai xe dap: " << loaixedap << endl;
			cout << "Tien thue xe dap: " << tienthuexedap() << endl;
		}
		
		long long tienthuexedap() {
			return 30000 + (sogiothue - 1) * 20000;
		}
};

class xemay: public thuexe {
	private:
		string loaixemay, bienso;
	public:
		string get_loaixemay() {
			return loaixemay;
		}
		void set_loaixemay(const string &new_loai_xe_may) {
			loaixemay = new_loai_xe_may;
		}
		void nhap_xemay() {
			nhap();
			cout << "Thong tin xe may: " << endl;
			cout << "Nhap loai xe may: ";
			cin.ignore();
			getline(cin, loaixemay);
			cout << "Nhap bien so xe may: ";
			getline(cin, bienso);
		}
		
		void xuat_xemay() {
			xuat();
			cout << "Loai xe may: " << loaixemay << endl;
			cout << "Bien so xe: " << bienso << endl;
			cout << "Tien thue xe may: " << tienthuexemay() << endl;
		}
		
		long long tienthuexemay() {
			if(getNum(loaixemay) == 100)
				return 15000 * sogiothue;
			else if (getNum(loaixemay) == 250)
				return 20000 * sogiothue;
			else
				return 0;
		}
};

int main() {
	int n1 = 0; // n1 is number of xe dap
	xedap* thuexedap[100];
	int n2 = 0; // n2 is number of xe may
	xemay* thuexemay[100];

	int n, m;
	cout << "Nhap so luong xe muon thue: ";
	cin >> n;
	for(int i = 0; i < n; i++) {
		cout << "Nhap loai danh muc: 1 - xe dap, 2 - xe may: ";
		cin >> m;
		if(m == 1) {
			xedap *p = new xedap;
			p->nhap_xedap();
			thuexedap[n1++] = p;
		}
		else {
			xemay *p = new xemay;
			p->nhap_xemay();
			thuexemay[n2++] = p;
		}
	}
	
	cout << "Danh sach thue xe: \n" << endl;

	cout << "Danh sach thue xe dap: " << endl;

	for (int i = 0; i < n1; ++i) {
		thuexedap[i]->xuat_xedap();
		cout << endl;
	}

	cout << "Danh sach thue xe may: " << endl;
	for (int i = 0; i < n2; ++i) {
		thuexemay[i]->xuat_xemay();
		cout << endl;
	}


	return 0;
}

		


