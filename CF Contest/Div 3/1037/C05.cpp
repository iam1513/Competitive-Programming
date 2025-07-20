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
        ll n, q;
        cin >> n >> q;

        vll nums(n);
        take_input_vector(nums, n);

        vector<vector<ll>> queries(q, vector<ll>(3));
        vector<vector<ll>> store;
        ll add = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
            add += queries[i][2];
            store.push_back({queries[i][0], queries[i][1], queries[i][2]});
            store.push_back({queries[i][1], queries[i][0], queries[i][2]});
        }

        sort(store.begin(), store.end());

        while (q--)
        {
            ll v, x;
            cin >> v >> x;
            nums[v - 1] = x;

            vector<ll> search = {v, 0, 0};
            auto it = lower_bound(store.begin(), store.end(), search);

            ll sum = 0;
            if (it != store.end() && (*it)[0] == v)
            {
                cout << "Found " << (*it)[0] << " " << (*it)[1] << " " << (*it)[2] << "\n";
                for (; it != store.end() && (*it)[0] == v; ++it)
                {
                    if (nums[(*it)[1] - 1] != nums[(*it)[0] - 1])
                    {
                        sum += (*it)[2];
                    }
                }
            }
            cout << sum << "\n";
        }
    }

    return 0;
}