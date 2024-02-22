#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>

using namespace std;

#define nln '\n'

int main(int argc, char **argv) {
    // Get data
    freopen("FCFS.inp", "r", stdin);
    int n;  cin >> n;
    pair<int, int> process[n];
    for (int i = 0; i < n; ++i)
        cin >> process[i].first;
    for (int i = 0; i < n; ++i)
        cin >> process[i].second;
    // First come first serve algorithm
    sort(process, process+n);
    int curr_time = 0;
    vector<pair<int, int>> informations;
    for (int i = 0; i < n; ++i) {
        int free_time = process[i].first - curr_time;
        if (free_time > 0)
            curr_time += free_time;
        informations.push_back(make_pair(max(0, curr_time - process[i].first), curr_time + process[i].second - process[i].first));
        curr_time += process[i].second;
        
        // cout << curr_time << nln;
        // cout << informations.back().first << " " << informations.back().second << nln;
        // getch();
    }
    // Output the information
    double avr_waiting_time = 0;
    double avr_turnaround_time = 0;
    for (auto p : informations)
        avr_waiting_time += p.first, avr_turnaround_time += p.second;
    avr_waiting_time /= n, avr_turnaround_time /= n;
    cout << "Average waiting time: " << avr_waiting_time << nln;
    cout << "Average Turnaround time: " << avr_turnaround_time << nln;
    return 0;
}