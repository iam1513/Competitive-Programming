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
        ll n, k;
        cin >> n >> k;

        vll nums(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());
        ll i = 0, j = 1;
        bool flag = false;
        while (i < n && j < n)
        {
            if (nums[i] + abs(k) == nums[j])
            {
                flag = true;
                break;
            }

            else if (nums[i] + abs(k) < nums[j])
                ++i;
            else
                ++j;
        }

        if (flag || (n == 1 && nums[0] == k))
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