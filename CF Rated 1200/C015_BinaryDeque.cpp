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
        ll n, s;
        cin >> n >> s;
        ll t = s;

        vll nums(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }

        vll temp;
        ll ptr = 1;
        while (s > 0 && ptr <= n)
        {
            if (nums[ptr] == 1)
            {
                temp.push_back(ptr);
                s--;
                ptr++;
            }
            else
            {
                ptr++;
            }
        }

        // for (ll i = 0; i < temp.size(); i++)
        // {
        //     cout << temp[i] << " ";
        // }
        // cout << endl;
        // cout << temp.size() << " " << t << endl;
        if (ptr > n && temp.size() != t)
        {
            cout << -1 << endl;
            continue;
        }

        ll ans = n;
        ll cnt = n - temp[temp.size() - 1];
        // cout << cnt << " " << ptr << endl;
        ans = min(cnt, ans);
        for (ll i = ptr; i <= n; i++)
        {
            // cout << i << " ";
            if (nums[i] == 0)
            {
                // cout << i << " " << nums[i] << " ";
                cnt--;
            }
            if (nums[i] == 1)
            {

                cnt = n - i + temp[0];
                temp.erase(temp.begin() + 0);
                temp.push_back(i);
            }

            ans = min(cnt, ans);
        }

        ans = min(cnt, ans);

        cout << ans << endl;
    }

    return 0;
}