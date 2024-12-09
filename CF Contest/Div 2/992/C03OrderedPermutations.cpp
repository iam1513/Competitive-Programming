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

void func(ll i, ll l, ll r, ll k, vll &ans)
{
    if (l == r)
    {
        ans[l] = i;
        return;
    }

    ll s = r - l - 1;
    if (s < 60 && (1ll << s) < k)
    {
        ans[r] = i;
        func(i + 1, l, r - 1, k - (1LL << s), ans);
    }
    else
    {
        ans[l] = i;
        func(i + 1, l + 1, r, k, ans);
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
        ll n, k;
        cin >> n >> k;
        if (n - 1 < 60 && (1LL << (n - 1)) < k)
        {
            cout << "-1" << "\n";
        }

        else
        {
            vll ans(n);
            func(1, 0, n - 1, k, ans);
            for (ll i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}