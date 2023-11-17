#include "date.h"

int main(int argc, char *argv[]) {
    date init;
    init.viewDay();
    init.setDay(20), init.setMonth(2), init.setYear(2003);
    int cnt = 40;
    cout << "Following is 40 consecutive days! " << endl;
    while (cnt--) {
        init.viewDay();
        init.nextDay();
    }   
    return 0;
}