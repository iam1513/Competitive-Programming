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
void pr(vll &nums)
{
    for (ll i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vll nums(n);
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x % m == 0)
            {
                nums[i] = m;
            }
            else
            {
                nums[i] = (x % m);
            }
        }

        mll mp;

        for (ll i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        // pr(nums);

        // for (auto ele : mp)
        // {
        //     cout << ele.first << " " << ele.second << " - ";
        // }
        // cout << endl;

        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll curr = nums[i];
            ll cnt1 = -1;

            if (mp.find(curr) != mp.end())
            {
                if (mp[curr] == 0)
                    continue;
                cnt1 = mp[curr];
            }

            if (cnt1 == -1)
            {
                continue;
            }

            ll need = m - curr;
            if (need % m == 0)
            {
                need = m;
            }
            // cout << need << " ";
            if (need == curr)
            {
                // cout << "here" << " ";
                mp[curr] = 0;
                ans++;
                continue;
            }

            ll cnt2 = -1;
            if (mp.find(need) != mp.end())
            {
                cnt2 = mp[need];
            }

            if (cnt2 == -1)
            {
                ans++;
                mp[curr]--;
                continue;
            }

            ll mini = min(cnt1, cnt2);

            if (cnt1 == cnt2)
            {
                mp[curr] = 0;
                mp[need] = 0;
                ans++;
                continue;
            }

            if (mini == cnt1)
            {
                mp[curr] = mp[0];
                mp[need] -= (mini + 1);
                ans++;
                continue;
            }

            if (mini == cnt2)
            {
                mp[curr] -= (mini + 1);
                mp[need] = 0;
                ans++;
                continue;
            }
        }

        cout << ans << endl;
    }

    return 0;
}