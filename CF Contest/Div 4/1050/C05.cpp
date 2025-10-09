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

ll function_om(ll n, ll k, vll &nums)
{
    mll mp;
    for (ll x : nums)
        mp[x]++;

    for (auto ele : mp)
    {
        if (ele.second % k != 0)
        {
            return 0;
        }
    }

    mll new_mp;
    for (auto ele : mp)
    {
        new_mp[ele.first] = ele.second / k;
    }

    ll l = 0, r = 0, ans = 0;
    mll store_cnt;

    while (r < n)
    {
        store_cnt[nums[r]]++;
        while (store_cnt[nums[r]] > new_mp[nums[r]])
        {
            store_cnt[nums[l]]--;
            l++;
        }
        ans += (r - l + 1);
        r++;
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
        ll n, k;
        cin >> n >> k;
        vll nums(n);
        take_input_vector(nums, n);

        cout << function_om(n, k, nums) << "\n";
    }

    return 0;
}