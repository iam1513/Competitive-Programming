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
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        take_input_vector(a, n);
        take_input_vector(b, m);

        vector<ll> pre(m + 1, n), suf(m + 1, -1);
        pre[0] = -1;
        ll j = 0;
        for (ll i = 0; i < n && j < m; i++)
        {
            if (a[i] >= b[j])
            {
                pre[j + 1] = i;
                j++;
            }
        }

        j = m - 1;
        suf[m] = n;
        for (ll i = n - 1; i >= 0 && j >= 0; i--)
        {
            if (a[i] >= b[j])
            {
                suf[j] = i;
                j--;
            }
        }

        if (pre[m] < n)
        {
            cout << "0\n";
            continue;
        }

        print_vector_to_debug(pre, m + 1);
        print_vector_to_debug(suf, m + 1);

        ll ans = INT_MAX;
        for (ll i = 1; i <= m; i++)
        {
            if (pre[i - 1] < suf[i])
            {
                ans = min(ans, b[i - 1]);
            }
        }

        cout << (ans == INT_MAX ? -1 : ans) << '\n';
    }

    return 0;
}