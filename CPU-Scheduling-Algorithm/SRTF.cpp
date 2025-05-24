//  Shortest Job First- Preemptive 
// Shortest Remaining Time First (SRTF)

#include <bits/stdc++.h> 
using namespace std; 
 
struct Process { 
    int id, at, bt, rt, ct, tat, wt, start = -1; 
}; 
 
int main() { 
    int n; 
    cout << "Enter number of processes: "; 
    cin >> n; 
    Process p[n]; 
 
    for(int i = 0; i < n; i++) { 
        p[i].id = i + 1; 
        cout << "Enter Arrival and Burst Time for P" << p[i].id << ": "; 
        cin >> p[i].at >> p[i].bt; 
        p[i].rt = p[i].bt; 
    } 
 
    int completed = 0, time = 0; 
    while(completed < n) { 
        int idx = -1, min_rt = INT_MAX; 
        for(int i = 0; i < n; i++) { 
            if(p[i].at <= time && p[i].rt > 0 && p[i].rt < min_rt) { 
                min_rt = p[i].rt; 
                idx = i; 
            } 
        } 
 
        if(idx == -1) { 
            time++; 
            continue; 
        } 
 
        if(p[idx].start == -1) 
            p[idx].start = time; // First time getting CPU 
 
        p[idx].rt--; 
        time++; 
 
        if(p[idx].rt == 0) { 
            p[idx].ct = time; 
            p[idx].tat = p[idx].ct - p[idx].at; 
            p[idx].wt = p[idx].tat - p[idx].bt; 
            completed++; 
        } 
    } 
 
    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n"; 
    for(int i = 0; i < n; i++) { 
        int responseTime = p[i].start - p[i].at; 
        cout << "P" << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" 
<< p[i].ct 
             << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << responseTime 
<< "\n"; 
    } 
 
    return 0; 
}