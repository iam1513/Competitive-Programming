#include <iostream>
using namespace std;
const int P = 5;
const int R = 3;
int Available[R];
int Max[P][R];
int Allocation[P][R];
int Need[P][R];
bool isSafe(int safeSequence[])
{
    int work[R];
    bool finish[P] = {false};
    for (int i = 0; i < R; i++)
        work[i] = Available[i];
    int count = 0;
    while (count < P)
    {
        bool found = false;
        for (int i = 0; i < P; i++)
        {
            if (!finish[i])
            {
                bool canAllocate = true;
                for (int j = 0; j < R; j++)
                {
                    if (Need[i][j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate)
                {
                    for (int j = 0; j < R; j++)
                        work[j] += Allocation[i][j];
                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found)
            return false; // Deadlock
    }
    return true;
}
// Function to process a resource request from a process
bool requestResources(int process, int request[])
{
    // Check if request exceeds need
    for (int i = 0; i < R; i++)
    {
        if (request[i] > Need[process][i])
        {
            cout << "Error: Process exceeded its maximum claim!\n";
            return false;
        }
    }
    // Check if resources r available
    for (int i = 0; i < R; i++)
    {
        if (request[i] > Available[i])
        {
            cout << "Resources not available. Process must wait.\n";
            return false;
        }
    }
    // Temporarily allocat
    for (int i = 0; i < R; i++)
    {
        Available[i] -= request[i];
        Allocation[process][i] += request[i];
        Need[process][i] -= request[i];
    }
    int safeSequence[P];
    if (!isSafe(safeSequence))
    {
        // Rollback
        for (int i = 0; i < R; i++)
        {
            Available[i] += request[i];
            Allocation[process][i] -= request[i];
            Need[process][i] += request[i];
        }
        cout << "Unsafe state detected! Request denied.\n";
        return false;
    }
    cout << "Request granted. System is in a safe state.\n";
    return true;
}

int main()
{
    cout << "-----------------------------------------------------------" << endl;
    cout << "Name : Om Shelke" << endl;
    cout << "Reg No : 22BCE10150" << endl;
    cout << "-----------------------------------------------------------" << endl;
    // Available res
    cout << "Enter available resources:\n";
    for (int i = 0; i < R; i++)
        cin >> Available[i];
    // Max and Allocate
    cout << "Enter Maximum resource matrix:\n";
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            cin >> Max[i][j];
    cout << "Enter Allocation matrix:\n";
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            cin >> Allocation[i][j];
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];
    int safeSequence[P];
    if (isSafe(safeSequence))
    {
        cout << "System is in a safe state.\nSafe sequence: ";
        for (int i = 0; i < P; i++)
            cout << "P" << safeSequence[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "System is in an unsafe state! Deadlock possible.\n";
    }
    int process;
    int request[R];
    cout << "Enter process number making request: ";
    cin >> process;
    cout << "Enter request for each resource: ";
    for (int i = 0; i < R; i++)
        cin >> request[i];
    requestResources(process, request);
    return 0;
}