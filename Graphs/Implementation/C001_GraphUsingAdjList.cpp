#include <bits/stdc++.h>

using namespace std;

template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adj;
    Graph()
    {
    }

    void add_edge(T n1, T n2, bool bidir = true)
    {
        adj[n1].push_back(n2);

        if (bidir)
        {
            adj[n2].push_back(n1);
        }
    }

    void print()
    {
        for (auto row : adj)
        {
            cout << row.first << "--->";
            for (auto ele : row.second)
            {
                cout << ele << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Graph<int> gh;
    gh.add_edge(1, 2);
    gh.add_edge(2, 3);
    gh.add_edge(2, 4);
    gh.add_edge(3, 2);
    gh.add_edge(4, 2);
    gh.add_edge(3, 4);

    gh.print();

    Graph<string> gs;
    gs.add_edge("dl", "blr");
    gs.add_edge("dl", "mum");
    gs.add_edge("mum", "kol");
    gs.add_edge("blr", "dl");
    gs.add_edge("kol", "mum");
    gs.add_edge("pn", "kol");

    gs.print();

    return 0;
}