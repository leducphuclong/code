////Câu 1: Đếm có bao nhiêu khoảng trắng trong chuỗi:
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main() {
//	string s;
//	getline(cin, s);
//	int dem = 0;
//	for(int i = 0; i < s.length(); i++) {
//		if(s[i] == ' ')
//			dem += 1;
//	}
//	cout << "So khoang trang la: " << dem;
//	return 0;
//}

////Đếm có bao nhiêu từ trong chuỗi:
//#include <iostream>
//#include <string>
//using namespace std;
//int dem_tu(string s) {
//  	int dem = 0;
//  	if(s[0] != ' ') 
//  		dem += 1;
//  	for (int i = 0; i < s.size() - 1; i++) {
//    	if (s[i] == ' ' && s[i + 1] != ' ')  
//      		dem++;
//    }
//  	return dem; 
//}
//
//int main() {
//  	string s ;
//  	getline(cin, s);
//  	cout << dem_tu(s);
//  	return 0;
//}

//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	string s;
//	getline(cin, s);
//	int dem = 0;
//	int i = 0;
//	while(i < s.size() && s[i] == ' ')
//		i += 1;
//	if(i < s.size() && s[i] != ' ')
//		dem += 1;
//	for(int j = i; j < s.size() - 1; j++)
//		if(s[j] == ' ' && s[j+1] != ' ')
//			dem += 1;
//	cout << dem;
//	return 0;
//
//}

////Đếm xem có bao nhiêu ký tự hoa:
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	string s;
//	getline(cin, s);
//	int dem = 0;
//	for(int i = 0; i < s.length(); i++) 
//		if(s[i] >= 'A' && s[i] <= 'Z')
//			dem += 1;
//	cout << dem;
//	return 0;
//}
/////Câu 2: Loại bỏ khoảng trắng thừa trong chuỗi:
//#include <iostream>
//#include <string>
//using namespace std;
//void xoa_dau_cuoi(string &s) {
//	while(s[0] == ' ') { 				
//		s.erase(s.begin() + 0);  	
//	}
//	while(s[s.length() - 1] == ' ') { 			
//		s.erase(s.begin() + s.length() - 1); 			
//	}
//}
//void xoa_giua(string &s) {
//	for(int i = 0; i < s.length(); i++) {
//		//Nếu 2 ký tự liên tiếp nhau là khoảng trắng => xóa đi 1 ký tự
//		if(s[i] == ' ' && s[i+1] == ' ') {
//			s.erase(s.begin() + i);
//			i--;
//		}
//	}
//}
//int main() {
//	string s;
//	getline(cin, s);
//	xoa_dau_cuoi(s);
//	cout << s << endl;
//	xoa_giua(s);
//	cout << s << endl;
//	return 0;
//}
////sửa XÓA KHOẢNG TRẮNG
//#include <iostream>
//using namespace std;
//int main() {
//    string s; getline(cin, s);
//    string tmp = ""; // string s without space
//    for (auto c : s)
//        if (c != ' ')
//            tmp += c;
//        else // c == ' '
//            continue;
//    s = tmp;
//    cout << s << endl;
//
//    return 0;
//}

////Câu 3: Nhập vào 2 chuỗi s1 và s2, nối chuỗi s2 vào s1. Xuất chuỗi s1
//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	s1.append(s2);
//	cout << s1;
//	return 0;
//}

////Câu 4 + 5: Đổi tất cả các ký tự trong chuỗi thành ký tự thường, ký tự hoa
//#include <iostream>
//#include <string>
//using namespace std;
//void hoa(string &s) {
//	for(int i = 0; i < s.length(); i++) {
//		s[i] = toupper(s[i]);
//	}
//}
//void thuong(string &s) {
//	for(int i = 0; i < s.length(); i++) {
//		s[i] = tolower(s[i]);
//	}
//}
//int main() {
//	string s;
//	getline(cin, s);
//	hoa(s);
//	cout << s << endl;
//	thuong(s);
//	cout << s;
//	return 0;
//}

////Câu 6: Đổi những ký tự đầu tiên của mỗi từ thành từ in hoa
//#include <iostream>
//#include <string>
//using namespace std;
//void hoa(string &s) {
//	if(s[0] != ' ') { 
//		if(s[0] >= 97 && s[0] <= 122)  
//			s[0] -= 32;
//	}
//	for(int i = 0; i < s.length() - 1; i++) {
//		if(s[i] == ' ' && s[i + 1] != ' ') { 
//			if(s[i + 1] >= 97 && s[i + 1] <= 122) {
//				s[i + 1] -= 32; 
//			}
//		}
//	}
//}
//int main() {
//	string s;
//	getline(cin, s);
//	hoa(s);
//	cout << s;
//	return 0;
//}

////Câu 7: Viết chương trình đổi chữ xen kẻ 2 chữ hoa 1 chữ thường:
//Vd: nhập ABCDEfgh => AbCdEfGh
//#include <iostream>
//#include <string>
//using namespace std;
//void dao(string &s) {
//	for(int i = 0; i < s.length(); i++) {
//		if(i % 2 == 0) 
//			s[i] = tolower(s[i]);
//		else
//			s[i] = toupper(s[i]);
//	}
//}
//int main() {
//	string s;
//	getline(cin, s);
//	dao(s);
//	cout << s;
//	return 0;
//}

////Câu 8: Viết chương trình đảo ngược các ký tự trong chuỗi:
//Vd: ABCDE => EDCBA
//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//	string s;
//	getline(cin, s);
//	for(int i = 0; i < s.length() / 2; i++) {
//		char tam = s[i];
//		s[i] = s[s.length() - i - 1];
//		s[s.length() - i - 1] = tam;
//	}
//	cout << s;
//	return 0;
//}

////sửa ĐẢO NGƯỢC CHUỖI:
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	string s;
//	getline(cin, s);
//    reverse(s.begin(), s.end());
//
//	cout << s;
//	return 0;
//}



////Viết hàm đếm 1 ký tự xuất hiện bao nhiêu lần trong xâu:
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int dem_kytu(string &s, char kt) {
//	int dem = 0;
//	for(char c : s)
//		if(c == kt)
//			dem += 1;
//	return dem;
//}
//int main() {
//	string s;
//	getline(cin, s);
//	char kt;
//	cin >> kt;
//	cout << dem_kytu(s, kt);
//	return 0; 
//}

////Viết hàm kiểm tra xem xâu có đối xứng hay không:
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//bool DX(string &s) {
//	for(int i = 0; i < s.length() / 2; i++) {
//		if(s[i] == s[s.length() - i - 1])
//			return true;
//	}
//	return false;
//}
//int main() {
//	string s;
//	getline(cin, s);
//	if(DX(s))
//		cout << "Chuoi doi xung";
//	else cout << "Chuoi khong doi xung";
//	return 0;
//}

////Viết ctrinh xóa từ trong xâu:
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	string s;
//	getline(cin, s);
//	string kq = "";
//	for(int i = 0; i < s.length(); i++)
//		if(isdigit(s[i]) != 0)
//			kq += s[i];
//	cout << kq;
//	return 0;
//}

////Đếm số lượng chữ cái, chữ số trong xâu:
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main() {
//	string s;
//	getline(cin, s);
//	int dem_chu, dem_so = 0;
//	for(int i = 0; i < s.length(); i++) {
//		if(isalpha(s[i]))
//			dem_chu += 1;
//		else if(isdigit(s[i]))
//			dem_so += 1;
//	}
//	cout << dem_chu << " " << dem_so;
//	return 0;
//}


//////////BÀI TẬP OJ
////Chữ hoa chữ thường: CORRECT
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main() {
//	string s;
//	while(getline(cin, s)) {
//		int dem_hoa, dem_thuong = 0;
//		for(int i = 0; i < s.length(); i++) {
//			if(s[i] >= 'A' and s[i] <= 'Z')
//				dem_hoa += 1;
//			else if (s[i] >= 'a' and s[i] <= 'z')
//				dem_thuong += 1;
//		}
//		if (dem_hoa > dem_thuong) {
//			for(int i = 0; i < s.length(); i++) 
//				s[i] = toupper(s[i]);
//			cout << s << endl;
//		}
//		else {
//			for(int i = 0; i < s.length(); i++) 
//				s[i] = tolower(s[i]);
//			cout << s << endl;
//		}			
//	}	
//	return 0;
//}

////Xoay trái xâu: CORRECT
//#include<iostream>
//using namespace std;
//
//int main() {
//    int m; cin >> m;
//	cin.ignore();
//	string s;
//	getline(cin, s);
//	m = m % s.size();
//	for (int i = m; i < s.size(); i++){
//		cout << s[i];
//	}
//	for (int i = 0; i < m; i++){
//		cout << s[i];
//	}
//	return 0;
//}

////Xâu AZ: CORRECT
//#include <bits/stdc++.h>
//using namespace std;
//int main(){
//    string s;
//    cin >> s;
//    int A = 0,Z = 0;
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] == 65) {
//            A = i;
//            break;
//        }
//    }
//    for (int i = s.size() - 1; i >= 0; i--) {
//        if (s[i] == 90) {
//            Z = i;
//            break;
//        }
//    }
//    cout << Z - A + 1<< endl;
//}

////Độ dài và nối chuỗi: CORRECT
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	string s; cin >> s;
//	string t; cin >> t;
//	cout << s.length() << " " << t.length() << endl;
//	string a = s + " " + t;
//	cout << a;
//	return 0;
//}

////Xâu có ký tự khác nhau: CORRECT
//#include <iostream>
//#include <set>
//
//using namespace std;
//
//int main() {
//	string s; cin >> s;
//	set<char> m;
//	for(int i = 0; i < s.length(); i++) 
//		m.insert(s[i]);
//	if(m.size() == s.length())
//		cout << "Yes";
//	else cout << "No";
//	return 0;
//}

////Xâu pangram: TIMELIMIT
//#include <iostream>
//#include <set>
//
//using namespace std;
//
//bool xauPan(string &s) {
//	set<char> xau;
//	for(char c : s) {
//		if(isalpha(c))
//			xau.insert(c);
//	}
//	return xau.size() == 26;
//}
//int main() {
//	string s;
//	while(getline(cin, s)) {
//		if(xauPan(s))
//			cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//	return 0;
//}

////Thống kê nguyên âm: ERROR
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    string s;
//    while(getline(cin, s)) {
//        int dem = 0;
//        for(int i = 0; i < s.length(); i++) {
//            if(toupper(s[i]) == 'a' || toupper(s[i]) == 'e' || toupper(s[i]) == 'i' || toupper(s[i]) == 'o' || toupper(s[i]) == 'u' || toupper(s[i]) == 'y')
//                dem += 1;
//        }
//        cout << dem << endl; 
//    }
//    return 0;
//}

////Đảo xâu: CORRECT: KTLT Nhom 14
//#include<bits/stdc++.h>
//#include<string>
//using namespace std;
//
//int main() {
//	string s;
//	int l, r;
//	cin >> l >> r >> s;
//	string a="";
//	for(int i = 0; i < l-1; i++){
//		a += s[i];
//	}
//	for(int i = r-1; i >= l-1; i--){
//		a += s[i];
//	}
//	for(int i = r; i<s.length(); i++){
//		a += s[i];
//	}
//	cout<<a;
//	return 0;
//}

////Mã hóa thư: CORRECT : KTLT Nhom 14
//#include <bits/stdc++.h>
//
//using namespace std;
//
//void daoXau(string &s) {
//	reverse(s.begin(), s.end());
//}
//
//int main() {
//	string s;
//	cin >> s;
//	int k; cin >> k;
//	string s1, s2;
//	s1 = s.substr(0,k);  //cắt chuỗi
//	daoXau(s1);
//   	s2 = s.erase(0,k);
//   	daoXau(s2);
//   	string s3 = s1 + s2;
//   	cout << s3;
//   return 0;
//}

////Convert_binaryStr_Decimal: chuyển số nhị phân sang thập phân: KTLT Nhom 15: ERROR
//#include <bits/stdc++.h>
//
//using namespace std;
//
//long long thap_phan(string &n) {
//	long long tong = 0;
//	for(int i = n.length() - 1; i >= 0; i--) {
//		if(n[i] == '1') {
//			tong += pow(2, n.length() - 1 - i);
//		}
//	}
//	return tong;
//}
//
//int main() {
//	string n; cin >> n;
//	cout << thap_phan(n);
//	return 0;
//}

////Tính tổng các số tìm dc trong xâu: COMPILER - ERROR: KTLT Nhom 10 
//Tổng số trong xâu: KTLT Nhom 4 (Lần 1):
//#include<iostream>
//#include<string>
//#include<sstream>
//using namespace std;
//
//int main(){
//	string s;
//	while(getline(cin, s)){
//		stringstream ss(s);
//		string tach = "";
//		int tong = 0;
//		while(ss >> tach){
//			if (tach[0] == '-'|| (tach[0] >= '0' && tach[0] <= '9')){
//				tong += stoi(tach);
//			}
//			
//		}
//		cout << tong << endl;
//	}
//	return 0;
//}
//Co bao nhieu so chinh phuong tu 1 den 100 -> 101
//Nuoc bay hoi o 100 do C con oxi hoa long o -183 do  -> -83

////////Xóa số trong xâu: Kiểm tra giữa kì - LTPython: CORRECT
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//	string kq = "";
//	for(int i = 0; i < s.length(); i++)
//		if(isalpha(s[i]) != 0)
//			kq += s[i];
//	cout << kq;
//	return 0;
//}

////Viết chương trình tìm số lần xuất hiện của từng phần tử phân biệt trong một danh sách theo thứ tự tăng dần: Kiểm tra giữa kì - LTPython

////Nén chiều dài dữ liệu: Thi học kỳ - Kỹ thuật lập trình nhóm 1, 2, 3, 4, 7, 8, 9: CORRECT
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	string s;
//	while(cin >> s) {
//		long long dem = 1;
//		for(int i = 0; i < s.length(); i++) {
//			if(s[i] == s[i+1]) {
//				dem += 1;
//			}
//			else {
//				cout << s[i] << dem;
//				dem = 1;  //khai báo lại để đếm ký tự mới
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}

////P1 - Thi LTNC Nhóm 9, 19: CORRECT
//#include <bits/stdc++.h>

//using namespace std;
//
//int main() {
//	string s;
//	getline(cin, s);
//	string kq = "";
//	for(int i = 0; i < s.length(); i++)
//		if(isalpha(s[i]) != 0 || s[i] ==' ')
//			kq += s[i];
//		
//	cout << kq;
//	return 0;
//}

////C1 - Thi học kỳ 2: Lập trình nâng cao nhóm 5, 8, 11, 12, 13, 14, 18: CORRECT
//#include<iostream>
//#include<sstream>
//#include<string>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//int main(){
//	string s;
//	getline(cin,s);
//	
//	stringstream ss(s);
//	
//	vector<string> v;
//	
//	string tu;
//	while(getline(ss, tu, '_')) //tach tu
//		v.push_back(tu);  //them cac ptu vao cuoi xau
//		
//	reverse(v.begin(), v.end());  //đảo chuỗi vừa tách dc
//	
//	string daochuoi = v[0];
//	
//	for(int i = 1; i < v.size(); i++)
//		daochuoi += '_' + v[i];
//	cout << daochuoi;
//	return 0;
//}



