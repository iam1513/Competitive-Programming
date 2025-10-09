#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<pll> nums;
        vll vec(n + 1);
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            nums.push_back({x, i + 1});
            vec[i + 1] = x;
        }

        sort(nums.begin(), nums.end(), [](const pll &a, const pll &b)
             { return a.first > b.first; });

        vll ans(n + 1, 0);
        ll current_pos = n;

        for (ll i = 0; i < nums.size(); i++)
        {
            ans[nums[i].second] = current_pos;
            current_pos--;
        }

        vll fixed;
        for (ll i = 1; i <= n; i++)
        {
            if (ans[i] == i)
            {
                fixed.push_back(i);
            }
        }

        if (fixed.size() == 1)
        {
            ll fix = fixed[0];
            for (ll i = 1; i <= n; i++)
            {
                if (i != fix && ans[i] != fix)
                {
                    swap(ans[fix], ans[i]);
                    break;
                }
            }
        }
        else if (fixed.size() > 1)
        {
            for (ll i = 0; i < fixed.size(); i++)
            {
                ll next = (i + 1) % fixed.size();
                ans[fixed[i]] = fixed[next];
            }
        }

        for (ll i = 1; i <= n; i++)
        {
            if (ans[i] == i)
            {
                ll swap_with = (i == n) ? i - 1 : i + 1;
                swap(ans[i], ans[swap_with]);
            }
        }

        ll new_ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (vec[ans[i]] <= vec[i])
            {
                new_ans++;
            }
        }

        cout << new_ans << endl;
        for (ll i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}