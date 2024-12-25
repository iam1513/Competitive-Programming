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

bool check(ll x, vll &nums)
{

    ll sum = accumulate(nums.begin(), nums.end(), 0LL);

    ll maxi = *max_element(nums.begin(), nums.end());

    sum = sum + x;

    double avg = (double)sum / nums.size();

    double min_avg = avg / 2;
    ll cnt = 0;

    for (ll i = 0; i < nums.size(); i++)
    {
        if (nums[i] < min_avg)
        {
            cnt++;
        }
    }

    return cnt > nums.size() / 2;
}

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

        if (n == 1 || n == 2)
        {
            cout << -1 << endl;
        }

        else
        {
            ll lo = 0, hi = 1e12;
            ll ans = -1;

            while (lo <= hi)
            {
                ll mid = (lo + hi) / 2;
                if (check(mid, nums))
                {
                    ans = mid;
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}