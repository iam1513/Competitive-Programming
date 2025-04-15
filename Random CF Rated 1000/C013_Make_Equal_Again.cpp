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
        ll n;
        cin >> n;

        vll nums(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        // vll temp;
        // ll i = 0, j = n - 1;
        // while (nums[i] == nums[j] && i != j)
        // {
        //     temp.pb(nums[i]);
        //     i++;
        // }

        // vll temp1;
        // for (ll x = i; x <= j; x++)
        // {
        //     temp1.pb(nums[x]);
        // }

        // for (ll x = 0; x < temp.size(); x++)
        // {
        //     temp1.pb(temp[x]);
        // }

        // // for (ll i = 0; i < temp1.size(); i++)
        // // {
        // //     cout << temp1[i] << " ";
        // // }

        // ll max_cnt = 1;
        // ll cnt = 1;
        // bool flag = true;
        // for (ll x = 1; x < temp1.size(); x++)
        // {
        //     if (temp1[x] == temp1[x - 1] && flag)
        //     {
        //         max_cnt++;
        //     }
        //     else
        //     {
        //         max_cnt = max(max_cnt, cnt);
        //         cnt = 1;
        //         break;
        //     }
        // }

        // if (max_cnt == temp1.size())
        // {
        //     flag = false;
        // }
        // else
        // {
        //     flag = true;
        // }

        // for (ll x = n - 2; x >= 0; x--)
        // {
        //     if (temp1[x] == temp1[x + 1] && flag)
        //     {
        //         max_cnt++;
        //     }
        //     else
        //     {
        //         max_cnt = max(max_cnt, cnt);
        //         cnt = 1;
        //         break;
        //     }
        // }

        // cout << temp1.size() - max_cnt << endl;
        bool flag = true;
        for (ll x = 1; x < n; x++)
        {
            if (nums[x] != nums[x - 1])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << 0 << endl;
            continue;
        }

        ll start = 1, end = 1;
        ll cnt = 1;
        ll i = 1;
        for (; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                cnt++;
            }
            else
            {
                start = max(start, cnt);
                cnt = 1;
                break;
            }
        }

        for (ll j = n - 2; j >= 0; j--)
        {
            if (nums[j] == nums[j + 1])
            {
                cnt++;
            }
            else
            {
                end = max(end, cnt);
                cnt = 1;
                break;
            }
        }

        // cout << "Start " << start << " end " << end << endl;

        ll maxi = nums[0] == nums[n - 1] ? start + end : max(start, end);

        cout << n - maxi << endl;
    }
    return 0;
}