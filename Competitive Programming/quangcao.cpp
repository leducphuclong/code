
Đã mở cuộc trò chuyện. 3 thư. Đã đọc tất cả thư. 

Chuyển đến nội dung
Sử dụng Gmail bằng trình đọc màn hình
quangcao 
Có phải ý của bạn là: quang cao
Cuộc trò chuyện
Một số thư trong thư mục Thùng rác hoặc Thư rác khớp với cụm từ bạn tìm kiếm. Xem thư
Đã dùng 2,34 GB trong tổng số 15 GB
Điều khoản · Bảo mật · Chính sách chương trình
Hoạt động gần đây nhất của tài khoản: 0 phút trước
Mở tại 1 vị trí khác · Chi tiết
//#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

#define long short int
#define nln '\n'

const short N = 10;
const short M = 100;

using namespace std;

fstream f1, f2;

inline void openf()
{
	f1.open("quangcao.inp", ios:: in);
	f2.open("quangcao.out", ios:: out);
}

inline void closef()
{
	f1.close();
	f2.close();
}

vector<vector<bool> > a(N), tea(N);

long n, m;

void data()
{
    f1.tie(0)->sync_with_stdio(0);
    f2.tie(0)->sync_with_stdio(0);

	f1 >> n >> m;
	for (size_t i = 0; i != n; ++i)
		for (size_t j = 0; j != m; ++j)
		{
			long x;
			f1 >> x;
			a[i].push_back(x);
		}
}

void showa()
{
    for (long i = 0 ; i != n; ++i)
    {
        for (long j = 0; j != m; ++j)
            cout << a[i][j] << "    ";
        cout << nln;
    }
}

void switchrow(long x)
{
	for (size_t i = 0; i != m; ++i)
		if (a[x][i] == 0)
			a[x][i] = 1;
		else
			a[x][i] = 0;
}

void switchcolumn(long y)
{
	for (size_t i = 0; i != n; ++i)
		if (a[i][y] == 0)
			a[i][y] = 1;
		else
			a[i][y] = 0;
}

long mac = 0, fla = 1;
vector<bool> bin;
bool stop = 0;

void gen()
{
    fla = n-1;

    while (bin[fla] == 1 && fla != 0)
        --fla;

    if (bin[fla] == 1 && fla == 0)
    {
        stop = 1;
        return;
    }

    bin[fla] = 1;
    for (size_t i = fla+1; i != n; ++i)
        bin[i] = 0;
}

long cim = 1005;
string hom;

void con()
{
    tea = a;

    long sul = 0, coi = 0;
    string how = "";

    for (size_t i = 0; i != n; ++i)
        if (bin[i])
        {
            switchrow(i);
            ++coi;
            how += 'D' + to_string(i+1) + ' ';
        }
    
    for (long i = 0; i != m; ++i)
    {
        long col = 0;
        for (long j = 0; j != n ; ++j)
            if (a[j][i] == 1) ++col;

        if (col < n-col)
        {
            switchcolumn(i);
            sul += n-col;
            ++coi;
            how  += 'C' + to_string(i+1) + ' ';
        }
        else
            sul += col;
    }

    if (sul > mac)
    {
        mac = sul;
        cim = coi;
        hom = how;
    }

    a = tea;
}

void process()
{
    for (size_t i = 0; i != n; ++i)
        bin.push_back(0);

    while (!stop)
    {
        con();
        gen();
    }
}

void view()
{
    f2 << mac << nln;
	f2 << cim << nln;

	for (size_t i = 0; i != hom.size(); ++i)
		if (hom[i] != ' ')
			f2 << hom[i];
		else
			f2 << nln;
}

int main()
{
	openf();
	data();
	process();
	view();
	closef();
	return 0;
}
