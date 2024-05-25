#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to perform activity selection using dynamic programming
vector<pair<int, int>> activity_selection(const vector<int>& start_times, const vector<int>& finish_times) {
    int n = start_times.size();
    vector<pair<int, int>> activities(n);
    for (int i = 0; i < n; ++i) {
        activities[i] = make_pair(start_times[i], finish_times[i]);
    }
    // Sort activities by finish time
    sort(activities.begin(), activities.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    // Initialize table
    vector<vector<int>> C(n, vector<int>(n, 0));
    // Fill table using bottom-up approach
    for (int j = 0; j < n; ++j) {
        for (int i = j; i >= 0; --i) {
            if (i == j) {
                C[i][j] = 1;
            } else {
                int k = -1;
                for (int m = i; m < j; ++m) {
                    if (activities[m].second <= activities[j].first) {
                        k = m;
                    }
                }
                if (k != -1) {
                    C[i][j] = max(C[i][j], C[i][k] + C[k+1][j] + 1);
                } else {
                    C[i][j] = j - i + 1;
                }
            }
        }
    }
    // Reconstruct solution
    vector<pair<int, int>> selected_activities;
    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if (j == 0 || C[i][j] != C[i][j-1]) {
            selected_activities.push_back(activities[j]);
            int k;
            for (k = i; k < j; ++k) {
                if (activities[k].second <= activities[j].first) {
                    break;
                }
            }
            j = k;
        } else {
            --j;
        }
    }
    return selected_activities;
}
int main() {
    vector<int> start_times = {1, 2, 3, 1};
    vector<int> finish_times = {2, 3, 4, 3};
    vector<pair<int, int>> selected = activity_selection(start_times, finish_times);
    cout << "Selected activities: ";
    for (const auto& activity : selected) {
        cout << "(" << activity.first << ", " << activity.second << ") ";
    }
    cout << endl;
    return 0;
}
