//Priority Scheduling (Non-Preemptive) – Different Arrival Time 

#include <bits/stdc++.h> 
using namespace std; 
 
struct Process { 
    int id, at, bt, priority, ct, tat, wt, rt; 
    bool completed = false; 
}; 
 
int findNext(Process p[], int n, int time) { 
    int max_priority = -1, idx = -1; 
    for (int i = 0; i < n; i++) { 
        if (!p[i].completed && p[i].at <= time) { 
            if (p[i].priority > max_priority) { 
                max_priority = p[i].priority; 
                idx = i; 
            } 
        } 
    } 
    return idx; 
} 
 
int main() { 
    int n; 
    cout << "Enter number of processes: "; 
    cin >> n; 
    Process p[n]; 
 
    for (int i = 0; i < n; i++) { 
        p[i].id = i + 1; 
        cout << "Enter AT, BT, Priority (higher number = higher priority) for P" << i + 1 << ": "; 
        cin >> p[i].at >> p[i].bt >> p[i].priority; 
    } 
 
    int time = 0, completed = 0; 
    while (completed < n) { 
        int idx = findNext(p, n, time); 
        if (idx == -1) { 
            time++; 
            continue; 
        } 
 
        p[idx].rt = time - p[idx].at; 
        time += p[idx].bt; 
        p[idx].ct = time; 
        p[idx].tat = p[idx].ct - p[idx].at; 
        p[idx].wt = p[idx].tat - p[idx].bt; 
        p[idx].completed = true; 
        completed++; 
    } 
 
    cout << "\nP\tAT\tBT\tPri\tCT\tTAT\tWT\tRT\n"; 
    for (int i = 0; i < n; i++) { 
        cout << "P" << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" 
<< p[i].priority 
             << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << 
"\t" << p[i].rt << "\n"; 
    } 
 
    return 0; 
}