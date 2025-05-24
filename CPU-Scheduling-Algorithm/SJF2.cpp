//SJF (Non-Preemptive) — Different Arrival Time 

#include <bits/stdc++.h> 
using namespace std; 
 
struct Process { 
    int id, at, bt, ct, tat, wt, rt; 
    bool completed = false; 
}; 
 
int findNext(Process p[], int n, int time) { 
    int min_bt = 1e9, index = -1; 
    for(int i = 0; i < n; i++) { 
        if(!p[i].completed && p[i].at <= time && p[i].bt < min_bt) { 
            min_bt = p[i].bt; 
            index = i; 
        } 
    } 
    return index; 
} 
 
void calculate(Process p[], int n) { 
    int time = 0, completed = 0; 
    while(completed < n) { 
        int i = findNext(p, n, time); 
        if(i == -1) { 
            time++; 
            continue; 
        } 
 
        p[i].rt = time - p[i].at;  // First response 
        p[i].ct = time + p[i].bt; 
        p[i].tat = p[i].ct - p[i].at; 
        p[i].wt = p[i].tat - p[i].bt; 
        p[i].completed = true; 
        time = p[i].ct; 
        completed++; 
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
        p[i].id = i+1; 
        cout << "Enter Arrival Time and Burst Time for P" << i+1 << ": "; 
        cin >> p[i].at >> p[i].bt; 
    } 
 
    calculate(p, n); 
    display(p, n); 
 
    return 0; 
} 