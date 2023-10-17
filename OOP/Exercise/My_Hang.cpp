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

        void Nhap_thong_tin();

        void In_ra_thong_tin();

        int tien_phai_tra();
};

int khach_hang::so_luong_khach_hang = 0;

void khach_hang::Nhap_thong_tin() {
    cout << "Nhap thong tin khach hang co id la " << this->id << endl;
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
    cout << endl;
}

void khach_hang::In_ra_thong_tin() {
    cout << "Sau day la thong tin khach co id: " << this->id << endl;
    cout << "Ho ten: " << this->get_ho_ten() << endl;
    cout << "Dia chi: " << this->get_dia_chi() << endl;
    cout << "SDT: " << this->get_sdt() << endl;
    cout << "Ngay tinh tien: ";
    thoi_gian t = this->get_ngay_tinh_tien();
    cout << t.ngay << '/' << t.thang << '/' << t.nam << endl;
    cout << "Tieu thu: " << this->get_tieu_thu() << " m3" << endl;
    cout << "So tien phai tra: " << tien_phai_tra() << " VND" << endl << endl;
}

int khach_hang::tien_phai_tra() {
    int tong_tien = 0, da_tieu_thu = this->tieu_thu;
    if (da_tieu_thu <= 100) {
        tong_tien += da_tieu_thu * 2000;
    } else if (da_tieu_thu <= 200) {
        tong_tien += 100*2000 + (da_tieu_thu-100)*3000;
    } else {
        tong_tien = 100*2000 + 100*3000 + (da_tieu_thu-200)*5000;
    }
    return tong_tien;
}

class quan_ly {
    private:
        int so_luong;
        khach_hang khach[100];
    public:
        quan_ly() : so_luong(0) {}
        ~quan_ly() {}

        void them_khach_hang(const khach_hang& khach_moi);

        void in_ra_danh_sach_khach_hang();

        int so_tien_phai_tra_lon_nhat();

        void in_ra_cac_khach_hang_co_tien_phai_tra_la_cao_nhat();

        void swap(int i, int j);

        bool so_sanh(int i, int j);

        void sap_xep_theo_ngay_tinh_tien();
};

void quan_ly::them_khach_hang(const khach_hang& khach_moi) {
    if (so_luong == 100) {
        cout << "Da chua so luong khach toi da, khong the chua them !! " << endl;
    } else {
        khach[so_luong++] = khach_moi;
    }
}

void quan_ly::in_ra_danh_sach_khach_hang() {
    cout << "Sau day la danh sach cac khach hang: " << endl << endl;
    for (int i = 0; i < so_luong; ++i)
        this->khach[i].In_ra_thong_tin();
}

void quan_ly::swap(int i, int j) {
    auto tmp = khach[i];
    khach[i] = khach[j];
    khach[j] = tmp;
}

bool quan_ly::so_sanh(int i, int j) {
            if (khach[i].get_ngay_tinh_tien().nam != khach[j].get_ngay_tinh_tien().nam)
                return khach[i].get_ngay_tinh_tien().nam < khach[j].get_ngay_tinh_tien().nam;
                
            if (khach[i].get_ngay_tinh_tien().thang != khach[j].get_ngay_tinh_tien().thang)
                return khach[i].get_ngay_tinh_tien().thang < khach[j].get_ngay_tinh_tien().thang;

            if (khach[i].get_ngay_tinh_tien().ngay != khach[j].get_ngay_tinh_tien().ngay)
                return khach[i].get_ngay_tinh_tien().ngay < khach[j].get_ngay_tinh_tien().ngay;
            
            return true;
        }

void quan_ly::sap_xep_theo_ngay_tinh_tien() {
    for (int i = 0; i < so_luong-1; i++)
        for (int j = i+1; j < so_luong; ++j)
            if (so_sanh(i, j) == false)
                swap(i, j);
}

int quan_ly::so_tien_phai_tra_lon_nhat() {
    int MAX = 0;
    for (int i = 0; i < so_luong; ++i)
        if (khach[i].tien_phai_tra() > MAX)
            MAX = khach[i].tien_phai_tra();
    return MAX;
}

void quan_ly::in_ra_cac_khach_hang_co_tien_phai_tra_la_cao_nhat() {
    cout << "Sau day la danh sach khach hang co so tien phai tra la lon nhat: " << endl << endl;
    int M = so_tien_phai_tra_lon_nhat();
    for (int i = 0; i < so_luong; ++i)
        if (khach[i].tien_phai_tra() == M)
            khach[i].In_ra_thong_tin();
}

int main(int argc, char **argv) {
    khach_hang c1("1", "Hue", "0914167544", {17, 10, 2022}, 189);
    khach_hang c2("2", "Hue", "0000000000", {10, 11, 2021}, 201);
    khach_hang c3("3", "Hue", "111111111", {10, 10, 2021}, 201);
    khach_hang c4("4", "Hue", "11111111111", {8, 11, 2021}, 201);
    // c1.Nhap_thong_tin();
    // c2.Nhap_thong_tin();
    quan_ly q;
    q.them_khach_hang(c1);
    q.them_khach_hang(c2);
    q.them_khach_hang(c3);
    q.them_khach_hang(c4);

    q.sap_xep_theo_ngay_tinh_tien();

    q.in_ra_danh_sach_khach_hang();
    q.in_ra_cac_khach_hang_co_tien_phai_tra_la_cao_nhat();

    return 0;
}
