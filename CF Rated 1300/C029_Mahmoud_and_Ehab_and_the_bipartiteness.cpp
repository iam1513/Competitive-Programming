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

ll red = 0, white = 0;

void dfs(ll node, ll color, vector<vector<ll>> &adj, vll &visited)
{
    visited[node]++;

    if (color == 1)
    {
        red++;
    }
    else
    {
        white++;
    }

    for (auto neighbor : adj[node])
    {
        if (visited[neighbor] == 0)
        {
            dfs(neighbor, 1 - color, adj, visited);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<vector<ll>> adj(n, vector<ll>());

    vll visited(n, 0);

    ll temp = n;

    n--;
    while (n--)
    {
        ll u, v;
        cin >> u >> v;

        u--, v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    // DFS from Node 0
    dfs(0, 0, adj, visited);

    cout << 1ll * (red * white) - (temp - 1) << endl;

    return 0;
}