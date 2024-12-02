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
        ll n;
        cin >> n;
        string st;
        cin >> st;

        map<char, ll> mp1, mp2;

        for (auto ele : st)
        {
            mp1[ele]++;
        }

        ll ans = 0;

        for (ll i = 0; i < n - 1; i++)
        {
            mp2[st[i]]++;
            mp1[st[i]]--;
            if (mp1[st[i]] == 0)
                mp1.erase(st[i]);
            ans = max(ans, static_cast<ll>(mp1.size() + mp2.size()));
        }

        cout << ans << endl;
    }

    return 0;
}