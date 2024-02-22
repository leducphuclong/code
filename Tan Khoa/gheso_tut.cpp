#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	... a, b;
	cin >> a >> b;
	
	sort(a.begin(), a.end()); //  Acsending
	
	string c1 = ""; // Acsending
    int i1 = 0, i2 = 0;
    while (i1 < a.size() || i2 < ...) {
		if (i1 == a.size()) {
		    c1 += b[i2], i2 ++;
		} else if (i2 == b.size()) {
			c1 += ..., ...;
		} else { // truong hop ca 2 xau a, b deu chua het
		   if (a[i1] < b[i2]) {
			    c1 += ..., ...;
		    } else {
  	            c1 += b[i2]], i2++;
		    }
		}
	}
	
	if (c1[0] == '0') {
		for (int i = 0; i < c1.size(); ++i)
			if (c1[i] != '0') {
				swap(c1[0], c1[i]);
				break;
			}
	}
	
	string c2 = "";
	sort(a.rbegin(), a.rend());
	i1 = 0, i2 = 0;
	while (i1 < ... || i2 < ...) {
		
	}
	
	return 0;
}
