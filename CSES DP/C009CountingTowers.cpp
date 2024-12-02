#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll recom(ll n, ll total, ll area)
{
    if (total == area)
    {
        return 1;
    }

    int ans = 0;

    for (ll i = 1; i <= 2; i++)
    {
        ll tot = 0;
        for (ll j = 1; j <= n; j++)
        {
            ll l = i;
            ll b = j;

            tot += recom(n - j, (l * b) + total, area);
        }
        ans+=tot;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false); // Disable synchronization with C I/O for faster input/output
    cin.tie(0);                  // Untie cin from cout to improve input/output performance

    ll t;
    cin >> t;

    while (t--)
    {

        ll n;
        cin >> n;
        ll area = 2 * n;
        cout << recom(n, 0, area) << endl;
    }

    return 0;
}