//Program for FCFS CPU Scheduling with different arrival times
 
#include <bits/stdc++.h>
using namespace std; 
 
struct Process { 
    int id; 
    int at;  // Arrival Time 
    int bt;  // Burst Time 
    int ct;  // Completion Time 
    int tat; // Turnaround Time 
    int wt;  // Waiting Time 
}; 
 
 
// Sort by arrival time 
void sortByArrival(Process p[], int n) { 
    for(int i = 0; i < n - 1; i++) { 
        for(int j = 0; j < n - i - 1; j++) { 
            if(p[j].at > p[j+1].at) { 
                swap(p[j], p[j+1]); 
            } 
        } 
    } 
} 
 
void calculateTimes(Process p[], int n) { 
    int current_time = 0; 
 
    for(int i = 0; i < n; i++) { 
        if(current_time < p[i].at) { 
            current_time = p[i].at;  // CPU waits if no process has arrived 
        } 
        p[i].ct = current_time + p[i].bt; 
        p[i].tat = p[i].ct - p[i].at; 
        p[i].wt = p[i].tat - p[i].bt; 
        current_time = p[i].ct; 
    } 
} 
 

void display(Process p[], int n) { 
    cout << "\nProcess\tArrival\tBurst\tWaiting\tTurnaround\tCompletion\n"; 
    for(int i = 0; i < n; i++) { 
        cout << "  P[" << p[i].id << "]\t  "  
             << p[i].at << "\t"  
             << p[i].bt << "\t"  
             << p[i].wt << "\t   "  
             << p[i].tat << "\t\t"  
             << p[i].ct << "\n"; 
    } 
} 
 
int main() { 
    int n; 
    cout << "Enter number of processes: "; 
    cin >> n; 
 
    Process* p = new Process[n]; 
 
    for(int i = 0; i < n; i++) { 
        p[i].id = i + 1; 
        cout << "Enter Arrival Time for Process " << i + 1 << ": "; 
        cin >> p[i].at; 
        cout << "Enter Burst Time for Process " << i + 1 << ": "; 
        cin >> p[i].bt; 
    } 
 
    sortByArrival(p, n); 
    calculateTimes(p, n); 
    display(p, n); 
 
    return 0; 
}