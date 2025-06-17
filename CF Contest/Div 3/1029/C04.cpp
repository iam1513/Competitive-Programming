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

bool isValidSequence(vector<ll> &nums, ll n)
{
    if (n < 2)
        return true;

    ll diff = nums[1] - nums[0];

    for (ll i = 2; i < n; ++i)
    {
        if (nums[i] - nums[i - 1] != diff)
        {
            return false;
        }
    }

    ll sum_shifted = nums[0] - diff;
    ll terms = n + 1;

    if (sum_shifted < 0 || sum_shifted % terms != 0)
    {
        return false;
    }

    ll new_diff_1 = sum_shifted / terms;
    ll new_diff_2 = new_diff_1 + diff;

    return new_diff_2 >= 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> nums(n);
        take_input_vector(nums, n);

        cout << (isValidSequence(nums, n) ? "YES\n" : "NO\n");
    }

    return 0;
}
