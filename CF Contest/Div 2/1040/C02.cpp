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
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

bool prime(ll a)
{
    if (a <= 1)
        return false;
    for (ll i = 2; i * i <= a; ++i)
        if (a % i == 0)
            return false;
    return true;
}

void take_input_vector(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
        cin >> nums[i];
}

void print_vector(const vll &nums)
{
    for (ll i = 0; i < nums.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << nums[i];
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
        ll n, s;
        cin >> n >> s;

        vll nums(n);
        take_input_vector(nums, n);

        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        ll diff = s - sum;

        mll freq;
        for (auto num : nums)
            freq[num]++;

        if (diff < 0 || diff == 1)
        {
            vll result;
            result.insert(result.end(), freq[0], 0);
            result.insert(result.end(), freq[2], 2);
            result.insert(result.end(), freq[1], 1);
            print_vector(result);
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}
