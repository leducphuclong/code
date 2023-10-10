#include <iostream>
#include <vector>

struct Process {
    int arrivalTime;
    int serviceTime;
};

void calculateCompletionTime(const std::vector<Process>& processes, std::vector<int>& completionTime) {
    int n = processes.size();
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        currentTime += processes[i].serviceTime;
        completionTime[i] = currentTime;
    }
}

void calculateTurnaroundTime(const std::vector<Process>& processes, const std::vector<int>& completionTime,
                             std::vector<int>& turnaroundTime) {
    int n = processes.size();

    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = completionTime[i] - processes[i].arrivalTime;
    }
}

void calculateWaitingTime(const std::vector<int>& turnaroundTime, const std::vector<int>& serviceTime,
                          std::vector<int>& waitingTime) {
    int n = turnaroundTime.size();

    for (int i = 0; i < n; i++) {
        waitingTime[i] = turnaroundTime[i] - serviceTime[i];
    }
}

void calculateAverageTimes(const std::vector<int>& turnaroundTime, const std::vector<int>& waitingTime) {
    int n = turnaroundTime.size();
    double totalTurnaroundTime = 0;
    double totalWaitingTime = 0;

    for (int i = 0; i < n; i++) {
        totalTurnaroundTime += turnaroundTime[i];
        totalWaitingTime += waitingTime[i];
    }

    double averageTurnaroundTime = totalTurnaroundTime / n;
    double averageWaitingTime = totalWaitingTime / n;

    std::cout << "Average Turnaround Time: " << averageTurnaroundTime << std::endl;
    std::cout << "Average Waiting Time: " << averageWaitingTime << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    std::vector<Process> processes(n);
    std::vector<int> completionTime(n);
    std::vector<int> turnaroundTime(n);
    std::vector<int> waitingTime(n);

    std::cout << "Enter the arrival times of the processes: ";
    for (int i = 0; i < n; i++) {
        std::cin >> processes[i].arrivalTime;
    }

    std::cout << "Enter the service times of the processes: ";
    for (int i = 0; i < n; i++) {
        std::cin >> processes[i].serviceTime;
    }

    calculateCompletionTime(processes, completionTime);
    calculateTurnaroundTime(processes, completionTime, turnaroundTime);
    calculateWaitingTime(turnaroundTime, processes[i].serviceTime, waitingTime);
    calculateAverageTimes(turnaroundTime, waitingTime);

    return 0;
}