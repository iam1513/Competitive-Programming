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

bool check(vll &nums)
{
    ll i = 0, j = nums.size() - 1;
    bool ans = true;
    while (i < j)
    {
        if (nums[i] != nums[j])
        {
            ans = false;
            break;
        }
        i++, j--;
    }

    return ans;
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

        ll i = 0, j = n - 1;
        while (i < j && nums[i] == nums[j])
        {
            i++, j--;
        }

        if (i >= j)
        {
            cout << "YES" << endl;
            continue;
        }

        vll temp1, temp2;
        for (ll k = 0; k < n; k++)
        {
            if (nums[k] != nums[i])
            {
                temp1.push_back(nums[k]);
            }
        }

        for (ll k = 0; k < n; k++)
        {
            if (nums[k] != nums[j])
            {
                temp2.push_back(nums[k]);
            }
        }

        bool one = check(temp1);
        bool two = check(temp2);

        if (one || two)
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