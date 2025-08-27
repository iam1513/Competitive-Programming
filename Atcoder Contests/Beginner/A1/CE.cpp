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

class dsu
{
    vll parent, rank;
    vll black_count;
    vll color;

public:
    dsu(ll n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        black_count.resize(n, 0);
        color.resize(n, 0); 
        for (ll i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    ll findUlP(ll n)
    {
        if (parent[n] == n)
        {
            return n;
        }
        return parent[n] = findUlP(parent[n]);
    }

    void unionByRank(ll u, ll v)
    {
        ll ulp_u = findUlP(u);
        ll ulp_v = findUlP(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            black_count[ulp_v] += black_count[ulp_u];
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            black_count[ulp_u] += black_count[ulp_v];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            black_count[ulp_u] += black_count[ulp_v];
            rank[ulp_u]++;
        }
    }

    void toggle(ll v)
    {
        ll idx = v - 1;
        ll root = findUlP(idx);
        if (color[idx] == 0)
        {
            color[idx] = 1;
            black_count[root]++;
        }
        else
        {
            color[idx] = 0;
            black_count[root]--;
        }
    }

    bool query(ll v)
    {
        ll idx = v - 1;
        ll root = findUlP(idx);
        return black_count[root] > 0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, Q;
    cin >> N >> Q;

    dsu d(N);

    while (Q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll u, v;
            cin >> u >> v;
            u--;
            v--;
            d.unionByRank(u, v);
        }
        else if (type == 2)
        {
            ll v;
            cin >> v;
            d.toggle(v);
        }
        else
        {
            ll v;
            cin >> v;
            if (d.query(v))
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }

    return 0;
}