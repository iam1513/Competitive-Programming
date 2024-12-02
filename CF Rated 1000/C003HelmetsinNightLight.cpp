#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        ll n, p;
        cin >> n >> p;
        vector<ll> a(n);
        vector<ll> b(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<pair<ll, ll>> nums;
        for (ll i = 0; i < n; i++)
        {
            nums.push_back({b[i], a[i]});
        }

        sort(nums.begin(), nums.end());
        ll ans = 0;
        map<ll, ll> mp;
        mp[p] = n + 100;
        for (auto ele : nums)
        {
            ll mini = (*mp.begin()).first;
            ans += mini;
            mp[mini]--;
            mp[ele.first] += ele.second;
            if (mp[mini] == 0)
                mp.erase(mini);
        }

        cout << ans << endl;
    }

    return 0;
}