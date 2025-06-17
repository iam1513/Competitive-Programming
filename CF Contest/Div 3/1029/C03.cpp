#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> nums(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        ll ans = 0;
        set<ll> one, two;
        for (ll i = 0; i < n; i++)
        {
            one.insert(nums[i]);
            two.insert(nums[i]);
            if (one == two)
            {
                ans++;
                one.clear();
            }
        }

        cout << ans << endl;
    }

    return 0;
}