#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_PROCESSES 10

using namespace std;

struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};

void inputProcesses(vector<Process> &processes, int n)
{
    processes.resize(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for Process " << i + 1 << " (arrival_time, burst_time): ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
}

void fcfsScheduling(vector<Process> &processes, int n)
{
    int total_waiting_time = 0, total_turnaround_time = 0;

    sort(processes.begin(), processes.end(), [](Process a, Process b)
         { return a.arrival_time < b.arrival_time; });

    int current_time = 0;
    cout << "\nFCFS Scheduling:\n";
    cout << "Process\tArrival\tBurst\tWaiting\tTurnaround\n";

    for (int i = 0; i < n; i++)
    {
        if (current_time < processes[i].arrival_time)
            current_time = processes[i].arrival_time;

        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        cout << "P" << processes[i].id << "\t" << processes[i].arrival_time << "\t" << processes[i].burst_time
             << "\t" << processes[i].waiting_time << "\t" << processes[i].turnaround_time << "\n";

        current_time += processes[i].burst_time;
    }

    cout << "\nAverage Waiting Time: " << (float)total_waiting_time / n << "\n";
    cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << "\n";
}

void sjfScheduling(vector<Process> &processes, int n)
{
    sort(processes.begin(), processes.end(), [](Process a, Process b)
         { return a.burst_time < b.burst_time; });

    int current_time = 0, total_waiting_time = 0, total_turnaround_time = 0;
    cout << "\nSJF Scheduling:\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n";

    for (int i = 0; i < n; i++)
    {
        if (current_time < processes[i].arrival_time)
            current_time = processes[i].arrival_time;

        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        cout << "P" << processes[i].id << "\t" << processes[i].arrival_time << "\t" << processes[i].burst_time
             << "\t" << processes[i].waiting_time << "\t" << processes[i].turnaround_time << "\n";

        current_time += processes[i].burst_time;
    }

    cout << "\nAverage Waiting Time: " << (float)total_waiting_time / n << "\n";
    cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << "\n";
}

void srtfScheduling(vector<Process> &processes, int n)
{
    int total_waiting_time = 0, total_turnaround_time = 0, completed = 0, current_time = 0;

    while (completed < n)
    {
        int min_time = INT_MAX, index = -1;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0 && processes[i].remaining_time < min_time)
            {
                min_time = processes[i].remaining_time;
                index = i;
            }
        }

        if (index == -1)
        {
            current_time++;
            continue;
        }

        processes[index].remaining_time--;
        current_time++;

        if (processes[index].remaining_time == 0)
        {
            completed++;
            processes[index].turnaround_time = current_time - processes[index].arrival_time;
            processes[index].waiting_time = processes[index].turnaround_time - processes[index].burst_time;
            total_waiting_time += processes[index].waiting_time;
            total_turnaround_time += processes[index].turnaround_time;
        }
    }

    cout << "\nSRTF Scheduling:\n";
    cout << "Process\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (const auto &p : processes)
    {
        cout << "P" << p.id << "\t" << p.arrival_time << "\t" << p.burst_time << "\t" << p.waiting_time << "\t" << p.turnaround_time << "\n";
    }

    cout << "\nAverage Waiting Time: " << (float)total_waiting_time / n << "\n";
    cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << "\n";
}

void roundRobinScheduling(vector<Process> &processes, int n, int quantum)
{
    int total_waiting_time = 0, total_turnaround_time = 0, current_time = 0;
    vector<int> remaining_time(n);
    for (int i = 0; i < n; i++)
        remaining_time[i] = processes[i].burst_time;

    bool done;
    do
    {
        done = true;
        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0)
            {
                done = false;
                if (remaining_time[i] > quantum)
                {
                    current_time += quantum;
                    remaining_time[i] -= quantum;
                }
                else
                {
                    current_time += remaining_time[i];
                    processes[i].waiting_time = current_time - processes[i].arrival_time - processes[i].burst_time;
                    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                    total_waiting_time += processes[i].waiting_time;
                    total_turnaround_time += processes[i].turnaround_time;
                    remaining_time[i] = 0;
                }
            }
        }
    } while (!done);

    cout << "\nRound Robin Scheduling:\n";
    cout << "Process\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (const auto &p : processes)
    {
        cout << "P" << p.id << "\t" << p.arrival_time << "\t" << p.burst_time << "\t" << p.waiting_time << "\t" << p.turnaround_time << "\n";
    }

    cout << "\nAverage Waiting Time: " << (float)total_waiting_time / n << "\n";
    cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << "\n";
}

int main()
{
    int choice, n, quantum;
    vector<Process> processes(MAX_PROCESSES);

    cout << "Enter the number of processes: ";
    cin >> n;
    if (n > MAX_PROCESSES)
        n = MAX_PROCESSES;

    inputProcesses(processes, n);

    do
    {
        cout << "\nCPU Scheduling Algorithms:\n";
        cout << "1. FCFS\n2. SJF\n3 SRTF\n4. Round Robin\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << endl;
            cout << "Author : Om Shelke" << "\n";
            cout << " Reg No : 22BCE10150" << "\n";
            cout << " First Come First Serve " << "\n";
            fcfsScheduling(processes, n);
            cout << endl;
            break;
        case 2:
            cout << endl;
            cout << " Author : Om Shelke" << "\n";
            cout << " Reg No : 22BCE10150" << "\n";
            cout << " Shortest Job First " << "\n";
            sjfScheduling(processes, n);
            cout << endl;
            break;
        case 3:
            cout << endl;
            cout << "Author : Om Shelke" << "\n";
            cout << " Reg No : 22BCE10150" << "\n";
            cout << " Shortest Remaining Time First " << "\n";
            srtfScheduling(processes, n);
            cout << endl;
            break;
        case 4:
            cout << endl;
            cout << "Author : Om Shelke" << "\n";
            cout << " Reg No : 22BCE10150" << "\n";
            cout << " Round Robin " << "\n";
            cout << "Enter time quantum: ";
            cin >> quantum;
            roundRobinScheduling(processes, n, quantum);
            cout << endl;
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}