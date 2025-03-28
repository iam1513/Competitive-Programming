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
        string s;
        cin >> s;

        map<char, int> mp;

        for (ll i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        ll ws = mp.size();

        vector<int> nums(26, 0);

        for (ll i = 0; i < ws; i++)
        {
            ll z = s[i] - 'a';
            // cout << "z " << z << " ";
            nums[z]++;
        }
        // cout << endl;

        bool flag = true;
        ll i = 0, j = ws - 1;
        while (j < s.size())
        {

            // for (ll k = 0; k < 26; k++)
            // {
            //     cout << nums[k] << " ";
            // }
            // cout << endl;

            for (ll k = 0; k < 26; k++)
            {
                if (nums[k] > 1)
                {
                    flag = false;
                    break;
                }
            }
            if (flag == false)
            {
                break;
            }
            i++, j++;
            if (j < s.size())
            {
                ll z = s[i - 1] - 'a';
                ll x = s[j] - 'a';
                nums[z]--;
                nums[x]++;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}