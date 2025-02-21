/*
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
*/

#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define sl set<ll>
#define sc set<char>

#define pb push_back

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, p;
        cin >> n >> p;

        vll a(n), b(n);
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
            nums.pb({a[i], b[i]});
        }

        sort(nums.begin(), nums.end(), [](const pair<ll, ll> &x, const pair<ll, ll> &y)
             { return x.second < y.second; });

        ll ans = 0;
        ll temp = n - 1;
        ans += p;
        for (ll i = 0; i < n; i++)
        {
            if (nums[i].second <= p)
            {
                if (temp >= nums[i].first)
                {
                    ans += nums[i].first * nums[i].second;
                    temp -= nums[i].first;
                }
                else
                {
                    ans += temp * nums[i].second;
                    break;
                }
            }
            else
            {
                ans += temp * p;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}