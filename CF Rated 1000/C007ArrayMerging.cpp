#include <bits/stdc++.h>
#define ll long long
using namespace std;

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

        vector<ll> a(n + 1), b(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 1; i <= n; i++)
        {
            cin >> b[i];
        }

        vector<ll> temp1(2 * n + 1, 0), temp2(2 * n + 1, 0);

        ll cnt = 1;
        for (ll i = 2; i <= n; i++)
        {
            if (a[i] != a[i - 1])
            {
                temp1[a[i - 1]] = max(temp1[a[i - 1]], cnt);
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        temp1[a[n]] = max(temp1[a[n]], cnt);

        cnt = 1;
        for (ll i = 2; i <= n; i++)
        {
            if (b[i] != b[i - 1])
            {
                temp2[b[i - 1]] = max(temp2[b[i - 1]], cnt);
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        temp2[b[n]] = max(temp2[b[n]], cnt);

        ll ans = 0;
        for (ll i = 1; i <= 2 * n; ++i)
        {
            ans = max(ans, temp1[i] + temp2[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}
