//SapXepMangTuLeftDenRight
#include<iostream>
using namespace std;
#define MAXN 100

void mergeSort(int data[],int n, int left,int right,int a[]);

int main()
{
    int data[MAXN], n, left, right;
    cout<<"So phan tu can nhap la: ";
    cin>>n;
    for (int i=0;i<n;i++) // **********
    {
        cout<<"Phan tu thu "<<i+1<<" la: ";
        cin>>data[i]; // **********
    }
    cout<<"Can sap xep tu phan tu ... den ...: ";
    cin>>left>>right;
    left--, right--; // Vì mình nhập vào chỉ số của mảng bắt đầu từ 1, 
    //nhưng mình code nhập vào mảng bắt đầu từ số 0 nên trừ cả 2 lui 1, 
    //2 chỗ có dấu ***** giải thích cho dòng này
    int a[MAXN]; // mảng trung gian cho việc sắp xếp
    mergeSort(data, right-left+1, left, right, a); // phải thêm biến n là độ dài mảng
    // không thể dùng length vì trong CPP không có length
    // Và nếu có thì nó sẽ luôn bằng hằng số MAXN là 100
    // Lần sau dùng const cho việc gán hằng này nhé
    for (int i = 0; i < n; ++i) // In ra xem sort đúng chưa
    	cout << data[i] << ' ';
    return 0;
}

// Sắp xếp các phần tử có chỉ số từ left đến right của mảng data.
void mergeSort(int data[],int n, int left,int right,int a[]){
	if (n == 1) {
		// Dãy chỉ gồm 1 phần tử, ta không cần sắp xếp.
		return ;
	}
	int mid = (left + right) / 2;
	// Sắp xếp 2 phần
	mergeSort(data, mid-left+1, left, mid, a);
	mergeSort(data, right-(mid+1)+1, mid+1, right, a);
	// Trộn 2 phần đã sắp xếp lại
	int i = left, j = mid + 1; // phần tử đang xét của mỗi nửa
	int cur = 0; // chỉ số trên mảng a
	while (i <= mid || j <= right) { // chừng nào còn 1 phần chưa hết phần tử.
		if (i > mid) {
			// bên trái không còn phần tử nào
			a[cur++] = data[j++];
			continue; // này cho dễ đọc hơn thôi, thực hiện lần lặp tiếp theo
			// và bỏ qua mấy lệnh dưới
		}
		if (j > right) {
			// bên phải không còn phần tử nào
			a[cur++] = data[i++];
			continue;
		}
		if (data[i] < data[j]) {
			// phần tử bên trái nhỏ hơn
			a[cur++] = data[i++];
		} else {
			a[cur++] = data[j++];
		}
	}
	// copy mảng a về mảng data
	for (int i = 0; i < cur; i++)
		data[left + i] = a[i];
}
/*void mergeSort(int data[],int left,int right,int a[MAXN]) {
	if (n == 1) {
		// Dãy chỉ gồm 1 phần tử, ta không cần sắp xếp.
		return ;
	}
	int mid = (left + right) / 2;
	// Sắp xếp 2 phần
	mergeSort(data, left, mid, a);
	mergeSort(data, mid+1, right, a);

	// Trộn 2 phần đã sắp xếp lại
	int i = left, j = mid + 1; // phần tử đang xét của mỗi nửa
	int cur = 0; // chỉ số trên mảng a

	while (i <= mid || j <= right) { // chừng nào còn 1 phần chưa hết phần tử.
		if (i > mid) {
			// bên trái không còn phần tử nào
			a[cur++] = data[j++];
		} else if (j > right) {
			// bên phải không còn phần tử nào
			a[cur++] = data[i++];
		} else if (data[i] < data[j]) {
			// phần tử bên trái nhỏ hơn
			a[cur++] = data[i++];
		} else {
			a[cur++] = data[j++];
		}
	}

	// copy mảng a về mảng data
	for (int i = 0; i < cur; i++)
		data[left + i] = a[i];
}
*/
/*
int a[MAXN]; // mảng trung gian cho việc sắp xếp

// Sắp xếp các phần tử có chỉ số từ left đến right của mảng data.
void mergeSort(int data[MAXN], int left, int right) {
	if (data.length == 1) {
		// Dãy chỉ gồm 1 phần tử, ta không cần sắp xếp.
		return ;
	}
	int mid = (left + right) / 2;
	// Sắp xếp 2 phần
	mergeSort(data, left, mid);
	mergeSort(data, mid+1, right);

	// Trộn 2 phần đã sắp xếp lại
	int i = left, j = mid + 1; // phần tử đang xét của mỗi nửa
	int cur = 0; // chỉ số trên mảng a

	while (i <= mid || j <= right) { // chừng nào còn 1 phần chưa hết phần tử.
		if (i > mid) {
			// bên trái không còn phần tử nào
			a[cur++] = data[j++];
		} else if (j > right) {
			// bên phải không còn phần tử nào
			a[cur++] = data[i++];
		} else if (data[i] < data[j]) {
			// phần tử bên trái nhỏ hơn
			a[cur++] = data[i++];
		} else {
			a[cur++] = data[j++];
		}
	}

	// copy mảng a về mảng data
	for (int i = 0; i < cur; i++)
		data[left + i] = a[i];
}
*/