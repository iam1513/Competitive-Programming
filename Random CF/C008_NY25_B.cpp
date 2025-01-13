#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve()
{
    ll n, k;
    cin >> n >> k;

    vll nums(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vll cnt = {1};
    for (ll i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            cnt.back()++;
        }
        else
        {
            cnt.push_back(1);
        }
    }

    sort(cnt.begin(), cnt.end());
    ll s = cnt.size();

    for (ll i = 0; i < s - 1; i++)
    {
        if (cnt[i] > k)
        {
            cout << s - i << endl;
            return;
        }
        k -= cnt[i];
    }

    cout << 1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
