#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll power(ll base, ll exp)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, q, k;
    cin >> n >> q >> k;

    vector<ll> nums(1e6, 0);
    vector<ll> temp(1e6, 0);
    vector<ll> powerK(1e6, 1);

    for (ll i = 1; i <= n; i++)
    {
        powerK[i] = (powerK[i - 1] * k) % MOD;
    }

    for (ll i = 1; i <= n; i++)
    {
        cin >> nums[i];
        nums[i] = (nums[i] * powerK[i]) % MOD;
        if (nums[i] < 0)
            nums[i] += MOD;
    }

    for (ll i = 1; i <= n; i++)
    {
        temp[i] = (temp[i - 1] + nums[i]) % MOD;
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        
        ll ans = (temp[b] - temp[a - 1] + MOD) % MOD;

        // TO find inverse 
        ans = (ans * power(powerK[a], MOD - 2)) % MOD;

        cout << ans << "\n";
    }

    return 0;
}
