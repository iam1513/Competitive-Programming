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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vll nums(n + 1, 0);
        vector<vll> adj(n + 1);
        for (int i = 2; i <= n; i++)
        {
            cin >> nums[i];
            adj[nums[i]].pb(i);
        }

        string st;
        cin >> st;

        vll order;
        queue<ll> q;
        q.push(1);
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            order.pb(u);
            for (ll v : adj[u])
            {
                q.push(v);
            }
        }

        vector<pll> count(n + 1, {0, 0});
        ll ans = 0;
        for (ll i = order.size() - 1; i >= 0; i--)
        {
            ll u = order[i];
            if (st[u - 1] == 'B')
            {
                count[u].first++;
            }
            else
            {
                count[u].second++;
            }
            for (ll v : adj[u])
            {
                count[u].first += count[v].first;
                count[u].second += count[v].second;
            }
            if (count[u].first == count[u].second)
            {
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}