#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x1, x2, v1, v2, x, t;
    cin >> x1 >> x2 >> v1 >> v2;
    if (x1 == x2)    {
		cout << "hi" << endl;
  	    x = 0;
	} else if (v1 == v2)
      x = -1;
	else {
	  t =(x1 - x2)/(v2 - v1);
	}
    
    if (t < 0)
      x = -1;
    else
      x = t;
    cout << x << endl;
    return 0;
}
