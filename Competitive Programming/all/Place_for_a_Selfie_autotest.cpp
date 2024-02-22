// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

#include <conio.h>
#include <chrono> // NOLINT
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <thread> // NOLINT
#include <random>
#include <cassert>

using namespace std; // NOLINT

typedef int64_t lo;

#define nln '\n'

const lo N = 1e1, M = 1e1, C = 1e4;
const char file_name_of_problem[] = "";

mt19937 rand_t(chrono::steady_clock::now().time_since_epoch().count());
//  This sets the seed for the Mersenne Twister engine to the current time
//  in milliseconds since the Unix epoch. (for the random)

lo random(lo miv, lo mav) {
    assert(miv <= mav);
    return miv + rand_t() * 1LL * rand_t() % (mav-miv+1);
}

char *concat(const char *a, const char *b) {
    // allocate memory for concatenated string
    char *result = new char[strlen(a) + strlen(b) + 1];
    // copy string a to result
    snprintf(result, strlen(a) + strlen(b) + 1, "%s%s", a, b);
    return result;
}

void generate() {
    fstream fi;
    fi.open(concat(file_name_of_problem, ".inp"), ios::out);
    fi << 1 << nln;
    fi.close();
}

bool compare(lo t, lo T) {
    cout << t << "/" << T << nln;
    system(concat(file_name_of_problem, ".exe"));
    system(concat(file_name_of_problem, "_bruteforce.exe"));
    char *nfc = concat("fc ", concat(concat(file_name_of_problem, ".out "),
                                   concat(file_name_of_problem, ".ans > nul")));
    if (system(nfc) == 0) {
        cout << "Test case " << t << " passed, Long." << endl;
        return true;
    } else {
        cout << "Test case " << t << " failed, Long." << endl;
        return false;
    }
}

int main() {
    srand(time(NULL));  // Seed of random is time
    lo T;
    cout << "How many test do you want to run, Long? ";
    cin >> T;
    cout << "Ok You want " << T << " testcases." << nln;
    chrono::seconds delay(2);
    this_thread::sleep_for(delay);
    for (lo t = 1; t <= T; ++t) {
        generate();
        if (compare(t, T) == false)
            break;
    }
    return 0;
}
