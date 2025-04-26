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

using namespace std;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
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

void take_input_vector(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}

void print_vector_to_debug(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

class Graph
{
public:
    list<ll> *adj;
    ll v;
    Graph(ll n)
    {
        this->v = n;
        this->adj = new list<ll>[this->v];
    }

    void addEgde(ll u, ll v, bool bidir = true)
    {
        adj[u].pb(v);
        if (bidir)
        {
            adj[v].pb(u);
        }
    }
};

void dfs(ll src, unordered_map<ll, bool> &visited, Graph &gh, unordered_map<ll, vll> &mp, ll comp_id)
{
    visited[src] = true;
    mp[comp_id].pb(src);
    for (auto neighbor : gh.adj[src])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, gh, mp, comp_id);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vll a(n + 1), b(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        for (ll i = 1; i <= n; i++)
            cin >> b[i];

        Graph gh(n + 1);
        while (m--)
        {
            ll u, v;
            cin >> u >> v;
            gh.addEgde(u, v);
        }

        unordered_map<ll, vll> mp;
        unordered_map<ll, bool> visited;
        for (ll i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, gh, mp, i);
            }
        }

        bool ans = true;

        for (auto ele : mp)
        {
            vll va, vb;
            for (auto idx : ele.second)
            {
                va.pb(a[idx]);
                vb.pb(b[idx]);
            }
            sort(va.begin(), va.end());
            sort(vb.begin(), vb.end());
            if (va != vb)
            {
                ans = false;
                break;
            }
        }

        if (ans)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
