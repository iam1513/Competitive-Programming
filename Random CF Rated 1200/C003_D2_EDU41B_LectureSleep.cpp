#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n), t(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    ll total = 0;
    for (ll i = 0; i < n; i++)
    {
        if (t[i] == 1)
        {
            total += a[i];
        }
    }

    ll window_sum = 0;
    for (ll i = 0; i < k; i++)
    {
        if (t[i] == 0)
        {
            window_sum += a[i];
        }
    }

    ll max_sum = window_sum;

    for (ll i = k; i < n; i++)
    {
        if (t[i - k] == 0)
        {
            window_sum -= a[i - k];
        }
        if (t[i] == 0)
        {
            window_sum += a[i];
        }
        max_sum = max(max_sum, window_sum);
    }

    cout << total + max_sum << endl;

    return 0;
}