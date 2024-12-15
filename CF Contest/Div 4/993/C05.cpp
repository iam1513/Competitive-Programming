#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        ll ans = 0;
        for (ll power = 1; power <= r2; power *= k)
        {

            for (ll x = max(l1, (l2 + power - 1) / power); x <= min(r1, r2 / power); ++x)
            {
                ll y = x * power;
                if (y >= l2 && y <= r2)
                {
                    ans++;
                }
            }

            if (k == 1)
                break;
        }

        cout << ans << "\n";
    }

    return 0;
}
