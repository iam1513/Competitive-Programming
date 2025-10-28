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

using namespace std;

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

void take_input_vector(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}

void print_vector_to_debug(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, W;
        cin >> n >> W;

        vll nums(n);
        take_input_vector(nums, n);

        mll mp;

        ll maxi = INT_MIN;
        for (ll i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            maxi = max(maxi, nums[i]);
        }

        ll k = 0;
        while (true)
        {
            if (((1 << k) ^ maxi) == 0)
            {
                break;
            }
            k++;
        }

        // cout << k << endl;

        ll ans = 0;

        while (!mp.empty())
        {
            ll need = W;
            ll temp_k = k;
            while (need > 0 && temp_k >= 0)
            {
                ll to_find = 1 << temp_k;
                if (mp.find(to_find) != mp.end() && to_find <= need)
                {
                    need -= to_find;
                    mp[to_find]--;
                    if (mp[to_find] == 0)
                    {
                        mp.erase(to_find);
                    }
                }
                else
                {
                    temp_k--;
                }
            }
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}