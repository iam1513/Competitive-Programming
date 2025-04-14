#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>> &wfg, vector<bool> &visited, vector<bool> &recStack)
{
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : wfg[node])
    {
        if (!visited[neighbor] && dfs(neighbor, wfg, visited, recStack))
            return true;
        else if (recStack[neighbor])
            return true;
    }

    recStack[node] = false;
    return false;
}

bool hasCycle(vector<vector<int>> &wfg, int numProcesses)
{
    vector<bool> visited(numProcesses, false);
    vector<bool> recStack(numProcesses, false);

    for (int i = 0; i < numProcesses; ++i)
    {
        if (!visited[i] && dfs(i, wfg, visited, recStack))
            return true;
    }
    return false;
}

int main()
{

    cout << "\n";
    cout << "Author : " << "Om Shelke\n";
    cout << "Reg No : " << "22BCE10150\n";
    cout << "\n";

    int numProcesses, numResources;
    cout << "Enter number of processes: ";
    cin >> numProcesses;

    cout << "Enter number of resources: ";
    cin >> numResources;

    int totalNodes = numProcesses + numResources;
    vector<vector<int>> rag(totalNodes);

    int edges;
    cout << "Enter number of edges in RAG: ";
    cin >> edges;

    cout << "Enter edges in format:\n";
    cout << "Type From To\n";
    cout << "(Type 1 = Process -> Resource, Type 2 = Resource -> Process)\n";
    for (int i = 0; i < edges; ++i)
    {
        int type, from, to;
        cin >> type >> from >> to;
        if (type == 1 || type == 2)
        {
            rag[from].push_back(to);
        }
        else
        {
            cout << "Invalid edge type! Skipping.\n";
        }
    }

    vector<vector<int>> wfg(numProcesses);

    for (int i = 0; i < numProcesses; ++i)
    {
        for (int resource : rag[i])
        {

            if (resource >= numProcesses && resource < totalNodes)
            {

                for (int proc : rag[resource])
                {
                    wfg[i].push_back(proc);
                }
            }
        }
    }

    cout << "\nWait-For Graph (Adjacency List):\n";
    for (int i = 0; i < numProcesses; ++i)
    {
        cout << "P" << i << " -> ";
        for (int p : wfg[i])
        {
            cout << "P" << p << " ";
        }
        cout << endl;
    }

    if (hasCycle(wfg, numProcesses))
    {
        cout << "\nDeadlock Detected: Cycle exists in Wait-For Graph.\n";
    }
    else
    {
        cout << "\nNo Deadlock: No cycle found in Wait-For Graph.\n";
    }

    cout << "\n";

    return 0;
}
