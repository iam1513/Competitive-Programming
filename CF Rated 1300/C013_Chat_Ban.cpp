#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll sum_n(ll n)
{
    return n * (n + 1) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll k, x;
        cin >> k >> x;

        ll ans = 1;
        if (x <= sum_n(k))
        {
            ll s = 1, e = k;
            while (s <= e)
            {
                ll m = s + (e - s) / 2;
                if (sum_n(m) >= x)
                {
                    ans = m;
                    e = m - 1;
                }
                else
                {
                    s = m + 1;
                }
            }
        }
        else
        {
            ans = k;
            ll remaining = x - sum_n(k);

            ll s = 1, e = k - 1; 
            ll d_ans = k - 1;
            while (s <= e)
            {
                ll d = s + (e - s) / 2;

                // Formula to avoid large overflows
                ll dec_sum = d * k - sum_n(d);
                if (dec_sum >= remaining)
                {
                    d_ans = d;
                    e = d - 1;
                }
                else
                {
                    s = d + 1;
                }
            }
            ans += d_ans;
        }

        cout << ans << "\n";
    }

    return 0;
}