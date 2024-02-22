#include<iostream>
#include<vector>
#include<tuple>
#include<climits>

#define long long long
#define nln '\n'

using namespace std;

struct rgb{
	long red, green, blue;
	string color;
};

void initialization(vector<rgb> &a)
{
	a[1].red = 255, a[1].green = 255, a[1].blue = 255, a[1].color = "White";
	a[2].red = 192, a[2].green = 192, a[2].blue = 192, a[2].color = "Silver";
	a[3].red = 128, a[3].green = 128, a[3].blue = 128, a[3].color = "Gray";
	a[4].red = 0, a[4].green = 0, a[4].blue = 0, a[4].color = "Black";
	a[5].red = 255, a[5].green = 0, a[5].blue = 0, a[5].color = "Red";
	a[6].red = 128, a[6].green = 0, a[6].blue = 0, a[6].color = "Maroon";
	a[7].red = 255, a[7].green = 255, a[7].blue = 0, a[7].color = "Yellow";
	a[8].red = 128, a[8].green = 128, a[8].blue = 0, a[8].color = "Olive";
	a[9].red = 0, a[9].green = 255, a[9].blue = 0, a[9].color = "Lime";
	a[10].red = 0, a[10].green = 128, a[10].blue = 0, a[10].color = "Green";
	a[11].red = 0, a[11].green = 255, a[11].blue = 255, a[11].color = "Aqua";
	a[12].red = 0, a[12].green = 128, a[12].blue = 128, a[12].color = "Teal";
	a[13].red = 0, a[13].green = 0, a[13].blue = 255, a[13].color = "Blue";
	a[14].red = 0, a[14].green = 0, a[14].blue = 128, a[14].color = "Navy";
	a[15].red = 255, a[15].green = 0, a[15].blue = 255, a[15].color = "Fuchsia";
	a[16].red = 128, a[16].green = 0, a[16].blue = 128, a[16].color = "Purple";
}

long sqr(long x)
{
	return x*x;
}

string color(long r, long g, long b, const vector<rgb> &a)
{
	string clr;
	long min = LLONG_MAX;
	for (long i = 1; i <= 16; ++i){
		long dst = sqr(a[i].red-r) + sqr(a[i].green-g) + sqr(a[i].blue-b);
		if (dst < min){
			min = dst;
			clr = a[i].color;
		}
	}
	return clr;
}	

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n = 16;
	vector<rgb> a(n+1);
	initialization(a);
	long r , g, b;
	while (1){
		cin >> r >> g >> b;
		if (r == -1)
			break;
		cout << color(r, g, b, a) << nln;
	}
	return 0;
}