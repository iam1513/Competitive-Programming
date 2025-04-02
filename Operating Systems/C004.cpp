#include <iostream>
#include <vector>
#include <list>
using namespace std;
class ResourceAllocationGraph
{
public:
    int vertices;
    vector<vector<int>> adjMatrix;
    vector<list<int>> adjList;
    vector<string> vertexNames;
    ResourceAllocationGraph(int v)
    {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
        adjList.resize(v);
        vertexNames.resize(v);
    }
    void setVertexName(int index, string name)
    {
        vertexNames[index] = name;
    }
    void addEdge(int from, int to)
    {
        adjMatrix[from][to] = 1;
        adjList[from].push_back(to);
    }
    void displayAdjMatrix()
    {
        cout << "\nAdjacency Matrix Representation:\n";
        cout << " ";
        for (int i = 0; i < vertices; i++)
            cout << vertexNames[i] << " ";
        cout << "\n";
        for (int i = 0; i < vertices; i++)
        {
            cout << vertexNames[i] << " ";
            for (int j = 0; j < vertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    void displayAdjList()
    {
        cout << "\nAdjacency List Representation:\n";
        for (int i = 0; i < vertices; i++)
        {
            cout << vertexNames[i] << " -> ";
            for (int neighbor : adjList[i])
            {
                cout << vertexNames[neighbor] << " ";
            }
            cout << "\n";
        }
    }
};
int main()
{
    cout << "-----------------------------------------------------------" << endl;
    cout << "Name : Om Shelke" << endl;
    cout << "Reg No : 22BCE10150" << endl;
    cout << "-----------------------------------------------------------" << endl;
    int p, r;
    cout << "Enter number of processes: ";
    cin >> p;
    cout << "Enter number of resources: ";
    cin >> r;
    int totalVertices = p + r;
    ResourceAllocationGraph rag(totalVertices);
    cout << "Enter process names:\n";
    for (int i = 0; i < p; i++)
    {
        string pname;
        cout << "Process " << i + 1 << ": ";
        cin >> pname;
        rag.setVertexName(i, pname);
    }
    cout << "Enter resource names:\n";
    for (int i = 0; i < r; i++)
    {
        string rname;
        cout << "Resource " << i + 1 << ": ";
        cin >> rname;
        rag.setVertexName(p + i, rname);
    }
    int edges;
    cout << "Enter number of resource allocation requests: ";
    cin >> edges;
    cout << "Enter edges in format (Process Resource):\n";
    for (int i = 0; i < edges; i++)
    {
        string pName, rName;
        cin >> pName >> rName;
        int from = -1, to = -1;
        for (int j = 0; j < totalVertices; j++)
        {
            if (rag.vertexNames[j] == pName)
                from = j;
            if (rag.vertexNames[j] == rName)
                to = j;
        }
        if (from != -1 && to != -1)
        {
            rag.addEdge(from, to);
        }
    }
    rag.displayAdjMatrix();
    rag.displayAdjList();
    return 0;
}