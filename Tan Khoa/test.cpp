#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Process {
    int arrivalTime;
    int executionTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
    int remainingTime;
};

bool arrivalTimeComparator(const Process& a, const Process& b) {
    return a.arrivalTime < b.arrivalTime;
}

bool priorityComparator(const Process& a, const Process& b) {
    return a.priority < b.priority;
}

void FCFS(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), arrivalTimeComparator);
    int n = processes.size();
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].executionTime;

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].turnaroundTime - processes[i].arrivalTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].executionTime;
    }

    // Print the results
    cout << "FCFS Scheduling:\n";
    cout << "Process\tWaiting Time\tTurnaround Time\n";
    double avr_waitingTime = 0, avr_turnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << endl;
        avr_waitingTime += processes[i].waitingTime;
        avr_turnaroundTime += processes[i].turnaroundTime;
    }
    cout << endl;
    cout << "Average Waiting Time: " << avr_waitingTime << endl;
    cout << "Average Turn Around: " << avr_turnaroundTime << endl;
}

void SJF(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), arrivalTimeComparator);
    int n = processes.size();
    vector<bool> completed(n, false);
    int currentTime = 0;

    while (true) {
        int shortestJob = -1;
        int shortestTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].arrivalTime <= currentTime && processes[i].executionTime < shortestTime) {
                shortestJob = i;
                shortestTime = processes[i].executionTime;
            }
        }

        if (shortestJob == -1)
            break;

        processes[shortestJob].waitingTime = currentTime - processes[shortestJob].arrivalTime;
        currentTime += processes[shortestJob].executionTime;
        processes[shortestJob].turnaroundTime = processes[shortestJob].waitingTime + processes[shortestJob].executionTime;
        completed[shortestJob] = true;
    }

    // Print the results
    cout << "SJF Scheduling:\n";
    cout << "Process\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << endl;
    }
    cout << endl;
}

void SRT(vector<Process>& processes) {
    int n = processes.size();
    vector<bool> completed(n, false);
    int currentTime = 0;

    while (true) {
        int shortestRemainingTime = INT_MAX;
        int shortestJob = -1;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].arrivalTime <= currentTime && processes[i].remainingTime < shortestRemainingTime) {
                shortestRemainingTime = processes[i].remainingTime;
                shortestJob = i;
            }
        }

        if (shortestJob == -1)
            break;

        processes[shortestJob].remainingTime--;
        currentTime++;

        if (processes[shortestJob].remainingTime == 0) {
            processes[shortestJob].turnaroundTime = currentTime - processes[shortestJob].arrivalTime;
            processes[shortestJob].waitingTime = processes[shortestJob].turnaroundTime - processes[shortestJob].executionTime;
            completed[shortestJob] = true;
        }
    }

    // Print the results
    cout << "SRT Scheduling:\n";
    cout << "Process\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << endl;
    }
    cout << endl;
}

void RR(vector<Process>& processes, int timeQuantum) {
    int n = processes.size();
    vector<int> remainingTime(n);
    vector<int> waitingTime(n, 0);
    vector<int> turnaroundTime(n, 0);

    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].executionTime;
        int currentTime = 0;
        queue<int> readyQueue;
        vector<int> executedTime(n, 0);

        while (true) {
            bool allCompleted = true;

            for (int i = 0; i < n; i++) {
                if (remainingTime[i] > 0) {
                    allCompleted = false;

                    if (remainingTime[i] > timeQuantum) {
                        remainingTime[i] -= timeQuantum;
                        currentTime += timeQuantum;
                        executedTime[i] += timeQuantum;
                        readyQueue.push(i);
                    } else {
                        currentTime += remainingTime[i];
                        executedTime[i] += remainingTime[i];
                        remainingTime[i] = 0;
                        turnaroundTime[i] = currentTime - processes[i].arrivalTime;
                        waitingTime[i] = turnaroundTime[i] - processes[i].executionTime;
                    }
                }
            }

            if (allCompleted)
                break;

            while (!readyQueue.empty()) {
                int processIndex = readyQueue.front();
                readyQueue.pop();

                if (remainingTime[processIndex] > 0)
                    readyQueue.push(processIndex);
            }
        }

        // Print the results
        cout << "Round Robin Scheduling (Time Quantum = " << timeQuantum << "):\n";
        cout << "Process\tWaiting Time\tTurnaround Time\n";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << "\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
        }
        cout << endl;
    }
}

void PriorityScheduling(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), priorityComparator);
    int n = processes.size();
    vector<int> waitingTime(n, 0);
    vector<int> turnaroundTime(n, 0);

    for (int i = 0; i < n; i++) {
        if (i > 0)
            waitingTime[i] = waitingTime[i - 1] + processes[i - 1].executionTime;

        turnaroundTime[i] = waitingTime[i] + processes[i].executionTime;
    }

    // Print the results
    cout << "Priority Scheduling:\n";
    cout << "Process\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }
    cout << endl;
}

void LotteryScheduling(vector<Process>& processes) {
    int n = processes.size();
    vector<int> tickets(n, 0);
    int totalTickets = 0;

    for (int i = 0; i < n; i++) {
        tickets[i] = processes[i].priority;
        totalTickets += tickets[i];
    }

    srand(time(0));
    vector<int> waitingTime(n, 0);
    vector<int> turnaroundTime(n, 0);

    for (int i = 0; i < n; i++) {
        int winningTicket = rand() % totalTickets;
        int winner = -1;
        int sum = 0;

        for (int j = 0; j < n; j++) {
            sum += tickets[j];

            if (winningTicket < sum) {
                winner = j;
                break;
            }
        }

        if (i > 0)
            waitingTime[i] = waitingTime[i - 1] + processes[i - 1].executionTime;

        turnaroundTime[i] = waitingTime[i] + processes[i].executionTime;

        // Update the tickets of the winner
        totalTickets -= tickets[winner];
        tickets[winner] = 0;
    }

    // Print the results
    cout << "Lottery Scheduling:\n";
    cout << "Process\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time, execution time, and priority for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].executionTime;
        processes[i].remainingTime = processes[i].executionTime;
        // Uncomment and implement priority input
        // cin >> processes[i].priority;
    }

    FCFS(processes);
    SJF(processes);
    SRT(processes);
    RR(processes, 10); // timeQuantum = 10
    PriorityScheduling(processes);
    LotteryScheduling(processes);

    return 0;
}