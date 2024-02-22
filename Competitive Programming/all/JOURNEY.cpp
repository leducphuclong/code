#include <iostream> 
#include <fstream>
#include <string>

using namespace std; 
int c[10000][10000], d[10000] = {0};
bool cd[10000] = {0};
int n, k, t, ct = 0; string result, ch = "";

fstream f1, f2;

void openf()
{
	f1.open("/storage/emulated/0/CppCompiler/JOURNEY.INP", ios:: in);
	f2.open("/storage/emulated/0/CppCompiler/JOURNEY.OUT", ios:: out);
}

void closef()
{
	f1.close();
	f2.close();
}

<<void read_data()
{
	f1 >> n >> k >> t;
	cout << n << "\t" << k << "\t" << t << "\t" << endl;
	for (int i = 1; i <= k; i++)
		{
		f1 >> d[i];
		cout << d[i] << "\t";
		}
	cout << endl;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i-1; j++)
			{
			f1 >> c[i][j];
			cout << c[i][j] << " ";
			}
			cout << endl;
	}
}

bool check_in(int des)
{
  for (int i = 1; i <= k; i++)
    if (des == d[i]) return true;
  return false;
}

void take_out()
{
 if (ch == "1")
   {
   int p; string ss = "";
	  cout << "result: " << result << endl << endl << "t:" << t << endl;
   for (int i = 1; i <= result.length(); i++)
     {
     if (result[i] == ' ')
       {
         p = stoi(ss);
         cout << p << " ";
         ss = "";
       }
       else
       {
         ss = ss + result[i];
       
       }
     }
   }
}

void go(int j)
{
  	if (t > 0) 
  {
		  	for (int i = 1; i <= n; i++)
				  {
       int p = 0;
       if (c[i][j] != 0) 
         p = c[i][j];
         else
         p = c[j][i];    
       if (p > 0 && i != j)
							 {
         t = t - p;
         if (t >= 0)
           {
							    ch = to_string(i);
							    result = result + ch + " " ;
           }
					   	 go(i);
         if (t >= 0)
			   				result.erase(result.length() - ch.length() - 1, ch.length() + 1);
 					    t = t + p;
         }  
       }       
  }
  else
	 take_out();
}

void xuli()
{
	openf();
	read_data();
	go(1);
	closef();
}

int main()
{
	xuli();
	cout << endl;
 cout << "Chuong trinh da chay xong!" << endl;
	return 0;
}
