// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT
#include <conio.h>
#include <unistd.h>

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

mt19937 rand_t(chrono::steady_clock::now().time_since_epoch().count());

lo random(lo miv, lo mav) {
    assert(miv <= mav);
    return miv + abs(rand_t() * 1LL * rand_t()) % (mav-miv+1);
}

// Declare global variables.

int main(int argc, char* argv[]) {
    srand(time(NULL));  // Seed of random is time

    vector<string> orientation = {
        "ue", "shita", "mae", "ushiro", "migi", "hidari",
        "naka", "xoto", "tonari", "chikaku", "aida"};

    map<string, string> dictionary;
    dictionary["ue"] = "above";
    dictionary["shita"] = "below";
    dictionary["mae"] = "in front of";
    dictionary["ushiro"] = "behind";
    dictionary["migi"] = "on the right";
    dictionary["hidari"] = "on the left";
    dictionary["naka"] = "inside";
    dictionary["xoto"] = "outside";
    dictionary["tonari"] = "beside";
    dictionary["chikaku"] = "nearby";
    dictionary["aida"] = "in the middle, between";
    lo n = orientation.size();
    n = 2;
    lo round = 0;
    char rps;
    do {
        ++round;
        vector<bool> chk(n, 0);
        vector<pair<string, string>> wa;
        lo t = n;
        while (t--) {
            lo i;
            do {
                i = random(0, n-1);
            } while (chk[i]);
            cout << "Please write the meaning of the word: ";
            cout << orientation[i] << endl << " -> ";
            string ans;
             getline(cin >> ws, ans);
            chk[i] = true;
            if (ans != dictionary[orientation[i]])
                wa.push_back({orientation[i], ans});
        }
        cout << nln << "Result's round " << round << ": ";
        cout << "You are wrong " << wa.size() <<
        " out of " << n << " word !!" << nln << nln;
        if  (wa.size() != 0)
            cout << "These are the words you are wrong: " << nln << nln;
        for (auto ans : wa) {
            cout << "- Question: " << ans.first << nln;
            cout << "-> Your answer: " << ans.second << nln;
            cout << "-> Right answer: " << dictionary[ans.first] << nln << nln;
        }
        cout << "Press any key to do it again or ESC to exit." << nln;
        rps = getch();
        system("cls");
    } while (rps != 27);
    cout << "Practice make ... better, you will never be perfect, So just be better!!" << nln;
    sleep(3);
    cout << "Finnish!";
    return 0;
}
