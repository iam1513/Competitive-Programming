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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        l--;

        vector<ll> arr(n);
        for (ll &x : arr)
            cin >> x;

        vector<ll> brr = arr, crr = arr;

        sort(brr.begin() + l, brr.end());
        sort(crr.begin(), crr.begin() + r, greater<int>());

        ll sum_brr = accumulate(brr.begin() + l, brr.begin() + r, 0LL);
        ll sum_crr = accumulate(crr.begin() + l, crr.begin() + r, 0LL);

        cout << min(sum_brr, sum_crr) << '\n';
    }

    return 0;
}