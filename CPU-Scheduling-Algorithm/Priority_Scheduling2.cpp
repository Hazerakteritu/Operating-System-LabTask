//Priority Scheduling (Preemptive) – Different Arrival Time 

#include <bits/stdc++.h> 
using namespace std; 
 
struct Process { 
    int id, at, bt, remaining_bt, priority, ct, tat, wt, rt, start = -1; 
    bool completed = false; 
}; 
 
int main() { 
    int n; 
    cout << "Enter number of processes: "; 
    cin >> n; 
    Process p[n]; 
 
    for (int i = 0; i < n; i++) { 
        p[i].id = i + 1; 
        cout << "Enter AT, BT, Priority (higher = higher priority) for P" << 
i + 1 << ": "; 
        cin >> p[i].at >> p[i].bt >> p[i].priority; 
        p[i].remaining_bt = p[i].bt; 
    } 
 
    int time = 0, completed = 0; 
    while (completed < n) { 
        int idx = -1; 
        int highest_priority = -1; 
 
        for (int i = 0; i < n; i++) { 
            if (p[i].at <= time && p[i].remaining_bt > 0) { 
                if (p[i].priority > highest_priority) { 
                    highest_priority = p[i].priority; 
                    idx = i; 
                } 
            } 
        } 
 
        if (idx != -1) { 
            if (p[idx].start == -1) 
                p[idx].start = time; 
 
            p[idx].remaining_bt--; 
            time++; 
 
            if (p[idx].remaining_bt == 0) { 
                p[idx].ct = time; 
                p[idx].tat = p[idx].ct - p[idx].at; 
                p[idx].wt = p[idx].tat - p[idx].bt; 
                p[idx].rt = p[idx].start - p[idx].at; 
                p[idx].completed = true; 
                completed++; 
            } 
        } else { 
            time++; 
        } 
    } 
 
    cout << "\nP\tAT\tBT\tPri\tCT\tTAT\tWT\tRT\n"; 
    for (int i = 0; i < n; i++) { 
        cout << "P" << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].priority 
             << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << "\n"; 
    } 
 
    return 0; 
} 