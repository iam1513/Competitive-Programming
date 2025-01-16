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

    ll n, q;
    cin >> n >> q;

    vll nums(n);

    vll qs(q);

    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (ll i = 0; i < q; i++)
    {
        cin >> qs[i];
    }

    reverse(nums.begin(), nums.end());

    vll ans;
    for (ll i = 0; i < q; i++)
    {
        ll temp = qs[i];

        for (ll j = n - 1; j >= 0; j--)
        {
            if (temp == nums[j])
            {
                ll idx = n - j;
                ll temp2 = nums[j];
                nums.erase(nums.begin() + j);
                ans.push_back(idx);
                nums.push_back(temp2);
                break;
            }
        }
    }

    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}