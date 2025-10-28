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

    ll n;
    cin >> n;

    vll nums(n);
    take_input_vector(nums, n);

    ll sum = accumulate(nums.begin(), nums.end(), 0LL);

    unordered_map<ll, vll> freq;
    for (ll i = 0; i < n; i++)
    {
        freq[nums[i]].pb(i); // This correctly adds zeros to map[0]
    }

    vll ans;

    // REMOVE THIS - it breaks the map iteration!
    // for (auto ele : freq)
    // {
    //     cout << ele.first << " " << ele.second.size() << endl;
    // }

    // Now freq.find(0) will work correctly
    for (ll i = 0; i < n; i++)
    {
        ll x = sum - nums[i];
        if ((x & 1))
        {
            continue;
        }
        x /= 2;

        if (freq.find(x) != freq.end())
        {
            for (auto idx : freq[x])
            {
                if (idx != i)
                {
                    ans.pb(i + 1);
                    break;
                }
            }
        }
    }

    cout << ans.size() << "\n";

    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}