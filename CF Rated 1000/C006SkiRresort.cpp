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
        ll n, k, q;
        cin >> n >> k >> q;

        vector<ll> nums(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        ll ans = 0, len = 0;

        for (ll i = 0; i < n; i++)
        {
            if (nums[i] <= q)
            {
                len++;
            }
            else
            {
                if (len >= k)
                {
                    ans += (len - k + 1) * (len - k + 2) / 2;
                }
                len = 0;
            }
        }

        if (len >= k)
        {
            ans += (len - k + 1) * (len - k + 2) / 2;
        }

        cout << ans << endl;
    }

    return 0;
}
