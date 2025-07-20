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
        ll n, k;
        cin >> n >> k;
        vll nums(n);
        take_input_vector(nums, n);
        ll val = nums[k - 1];
        sort(nums.begin(), nums.end());
        ll idx = -1;

        for (ll i = 0; i < n; i++)
        {
            if (nums[i] == val)
            {
                idx = i;
                break;
            }
        }

        // cout << idx << endl;

        ll cnt = 0;
        bool flag = false;
        for (ll i = idx; i < n - 1; i++)
        {
            cnt += nums[i + 1] - nums[i];
            if (nums[i] < cnt)
            {
                flag = true;
            }

            // cout << "i " << i << " cnt " << cnt << " sub  " << nums[i + 1] - nums[i] << endl;
        }

        if (flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}