#include <iostream>
#include <climits>
using namespace std;

struct Process {
    int pno;
    int bt;
    int art;
};

void calculateTurnAroundTime(Process p[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = p[i].bt + wt[i];
}

void calculateWaitingTime(Process p[], int n, int wt[]) {
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = p[i].bt;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((p[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (!check) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];

        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time - p[shortest].bt - p[shortest].art;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

void averageTime(Process p[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    calculateWaitingTime(p, n, wt);
    calculateTurnAroundTime(p, n, wt, tat);

    cout << "Processes \t Burst Time \t Arrival Time \t Waiting Time \t Turn-Around Time \n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "\t" << p[i].pno << "\t\t\t" << p[i].bt << "\t\t\t" << p[i].art << "\t\t\t" << wt[i] << "\t\t\t\t" 
             << tat[i] << endl;
    }
    
    cout << endl;
    cout << "Average Waiting Time = " << (float)total_wt / (float)n << endl;
    cout << "Average Turn Around Time = " << (float)total_tat / (float)n << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process p[n];
    cout << endl;

    for (int i = 0; i < n; i++) {
        p[i].pno = i + 1;
        cout << "Enter the details for Process " << i + 1 << "\n";
        cout << "Enter Arrival Time: ";
        cin >> p[i].art;
        cout << "Enter Burst Time: ";
        cin >> p[i].bt;
    }

    averageTime(p, n);

    cout << endl;
    return 0;
}
