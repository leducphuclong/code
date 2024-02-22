#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    double number = 3.14159;
    cout << number << endl;
    cout << setiosflags(ios_base::fixed | ios_base::showpoint) << number << endl;
    return 0;
}