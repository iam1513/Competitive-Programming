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
        int n;
        cin >> n;
        vll a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<pll> store;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < i + 1)
            {
                store.pb({a[i], i + 1});
            }
        }

        sort(store.begin(), store.end());

        ll count = 0;
        for (ll i = 0; i < store.size(); i++)
        {
            ll x = store[i].second;

            ll low = i + 1, high = store.size() - 1, idx = store.size();
            while (low <= high)
            {
                ll mid = low + (high - low) / 2;
                if (store[mid].first > x)
                {
                    idx = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // cout << "High " << idx << endl;

            count += (store.size() - idx);
        }

        cout << count << "\n";
    }

    return 0;
}
