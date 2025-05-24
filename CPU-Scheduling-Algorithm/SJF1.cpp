// Shortest Job First (Non-Preemptive) — Same Arrival Time 


#include <bits/stdc++.h> 
using namespace std; 
 
struct Process { 
    int id, bt, at, ct, tat, wt, rt; 
}; 
 
void sortByBurst(Process p[], int n) { 
    for(int i = 0; i < n-1; i++) 
        for(int j = 0; j < n-i-1; j++) 
            if(p[j].bt > p[j+1].bt) 
                swap(p[j], p[j+1]); 
} 
 
void calculate(Process p[], int n) { 
    int time = 0; 
    for(int i = 0; i < n; i++) { 
        if(i == 0) time = p[i].at; 
        p[i].rt = time - p[i].at; // Response Time = Start Time - Arrival Time 
        p[i].ct = time + p[i].bt; 
        p[i].tat = p[i].ct - p[i].at; 
        p[i].wt = p[i].tat - p[i].bt; 
        time = p[i].ct; 
    } 
} 
 
void display(Process p[], int n) { 
    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n"; 
    for(int i = 0; i < n; i++) 
        cout << "P" << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" 
<< p[i].ct 
             << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << 
"\n"; 
} 
 
int main() { 
    int n; 
    cout << "Enter number of processes: "; 
    cin >> n; 
    Process p[n]; 
 
    for(int i = 0; i < n; i++) { 
        p[i].id = i + 1; 
        cout << "Enter Burst Time for Process P" << i+1 << ": "; 
        cin >> p[i].bt; 
        p[i].at = 0; 
    } 
 
    sortByBurst(p, n); 
    calculate(p, n); 
    display(p, n); 
 
    return 0; 
}