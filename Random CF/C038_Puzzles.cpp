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

    ll n, m;
    cin >> n >> m;

    vll nums(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    // for (ll i = 0; i < n; i++)
    // {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;

    ll i = 0;

    ll j = n - 1;
    ll mini = INT_MAX;
    while (j < m)
    {
        ll sub = nums[j] - nums[i];
        mini = min(mini, sub);
        j++;
        i++;
    }

    cout << mini << endl;

    return 0;
}