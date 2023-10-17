// Chương trình quản lí tiền nước hàng tháng của khách hàng

#include <iostream>

using namespace std;

struct thoi_gian {
    int ngay, thang, nam;
};

class khach_hang {
    private: 
        string ho_ten, dia_chi, sdt;
        thoi_gian ngay_tinh_tien;
        int id, tieu_thu;
        static int so_luong_khach_hang;
    public:
        khach_hang(string ho_ten = "", string dia_chi = "", 
        string sdt = "", thoi_gian ngay_tinh_tien = {0, 0, 0}, int tieu_thu = 0):
        ho_ten(ho_ten), dia_chi(dia_chi), sdt(sdt), ngay_tinh_tien(ngay_tinh_tien),
        tieu_thu(tieu_thu), id(so_luong_khach_hang++) {}

        ~khach_hang() {
            cerr << "Da huy thong tin khach hang id " << id << " !!" << endl;
        }

        void set_ho_ten(const string &ho_ten) { this->ho_ten = ho_ten; }
        void set_dia_chi(const string &dia_chi) { this->dia_chi = dia_chi; }
        void set_sdt(const string &sdt) { this->sdt = sdt; }
        void set_ngay_tinh_tien(const thoi_gian &ngay_tinh_tien) { 
            this->ngay_tinh_tien = ngay_tinh_tien; }
        void set_tieu_thu (int tieu_thu) { this->tieu_thu = tieu_thu; }

        int get_id() { return this->id; }
        string get_ho_ten() { return this->ho_ten; }
        string get_dia_chi() { return this->dia_chi; }
        string get_sdt() { return this->sdt; }
        thoi_gian get_ngay_tinh_tien() { return this->ngay_tinh_tien; }
        int get_tieu_thu() { return this->tieu_thu; };

        void Nhap_thong_tin() {
            cout << "Nhap thong tin khach hang: " << endl;
            string tmp;
            cout << "Ho ten: ";
            getline(cin >> ws, tmp);  this->set_ho_ten(tmp);

            cout << "Dia chi: ";
            getline(cin >> ws, tmp);  this->set_dia_chi(tmp);

            cout << "SDT: ";
            getline(cin >> ws, tmp);  this->set_sdt(tmp);

            int d, m, y;
            cout << "Nhap thoi diem tinh tien: " << endl;
            cout << "Ngay: ";   cin >> d;
            cout << "Thang: ";  cin >> m;
            cout << "Nam: ";    cin >> y;
            this->set_ngay_tinh_tien(thoi_gian({d, m, y}));

            cout << "Tieu thu (m3): ";
            int tieu_thu;   cin >> tieu_thu; this->set_tieu_thu(tieu_thu);
            cin.ignore();
        }

        void In_ra_thong_tin() {
            cout << "Sau day la thong tin khach co id: " << this->id << endl;
            cout << "Ho ten: " << this->get_ho_ten() << endl;
            cout << "Dia chi: " << this->get_dia_chi() << endl;
            cout << "SDT: " << this->get_sdt() << endl;
            cout << "Ngay tinh tien: ";
            thoi_gian t = this->get_ngay_tinh_tien();
            cout << t.ngay << '/' << t.thang << '/' << t.nam << endl;
            cout << "Tieu thu: " << this->get_tieu_thu() << " m3" << endl;
        }
};

int khach_hang::so_luong_khach_hang = 0;

int main(int argc, char **argv) {
    khach_hang c1;
    c1.Nhap_thong_tin();
    c1.In_ra_thong_tin();   
    return 0;
}