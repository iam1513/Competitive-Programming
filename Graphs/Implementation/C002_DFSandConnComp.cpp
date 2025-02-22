#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define sl set<ll>
#define sc set<char>

#define pb push_back

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}

using namespace std;

class Graph
{
public:
    ll v;
    list<ll> *adj;
    Graph(ll n)
    {
        this->v = n;
        this->adj = new list<ll>[this->v];
    }

    void addEgde(ll u, ll v, bool bidir = true)
    {
        adj[u].push_back(v);
        if (bidir)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (ll i = 0; i < v; i++)
        {
            cout << i << " -> ";
            for (auto neighbor : adj[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(ll src, unordered_map<ll, bool> &visited)
    {
        visited[src] = true;
        // cout << src << " ";
        for (auto neighbour : this->adj[src])
        {
            if (not visited[neighbour])
            {
                dfsHelper(neighbour, visited);
            }
        }
    }

    void dfs(ll src)
    {
        unordered_map<ll, bool> visited;
        dfsHelper(src, visited);
    }

    ll connectedComp()
    {
        unordered_map<ll, bool> visited;
        ll result = 0;

        for (ll i = 0; i < v; i++)
        {
            if (not visited[i])
            {
                dfsHelper(i, visited);
                result++;
            }
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Graph g(6);
    g.addEgde(0, 1);
    g.addEgde(2, 1);
    g.addEgde(3, 2);
    g.addEgde(4, 5);
    g.printGraph();

    cout << g.connectedComp() << endl;

    return 0;
}