#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    vector<ll> nums(n + 2, 0);
    vector<ll> extra(n + 2, 0);

    while (q--)
    {
        ll a, d, l, r;
        cin >> a >> d >> l >> r;

        ll add1 = ((a - l * d) % MOD + MOD) % MOD;
        nums[l] = (nums[l] + add1) % MOD;
        nums[r + 1] = (nums[r + 1] - add1 + MOD) % MOD;

        ll add2 = d % MOD;
        extra[l] = (extra[l] + add2) % MOD;
        extra[r + 1] = (extra[r + 1] - add2 + MOD) % MOD;
    }

    for (ll i = 1; i <= n; i++)
    {
        nums[i] = (nums[i] + nums[i - 1]) % MOD;
        extra[i] = (extra[i] + extra[i - 1]) % MOD;
    }

    vector<ll> ans(n + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        ans[i] = (nums[i] + i * extra[i] % MOD) % MOD;
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
