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

ll sum_digits_to(ll n)
{
    if (n <= 0)
    {
        return 0;
    }

    ll ans = 0, base = 1;
    while (base <= n)
    {
        ll q = n / base, r = n % base;
        ll digit = q % 10, left = q / 10;
        ans += (45 * left * base) + (digit * (digit - 1) / 2 * base) + digit * (r + 1);
        base *= 10;
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
        ll k;
        cin >> k;
        ll len = 1, start = 1, end = 9, tot_dig = 0, tot_sum = 0;
        while (1)
        {
            ll cnt = end - start + 1;
            ll dig = cnt * len;
            if (tot_dig + dig < k)
            {
                tot_sum += sum_digits_to(end) - sum_digits_to(start - 1);
                tot_dig += dig;
                start = end + 1;
                end = end * 10 + 9;
                len++;
            }
            else
            {
                break;
            }
        }
        ll rem = k - tot_dig;
        ll n = (rem - 1) / len;
        ll num = start + n;
        ll pos = (rem - 1) % len;
        tot_sum += sum_digits_to(num - 1) - sum_digits_to(start - 1);
        string s = to_string(num);
        for (ll i = 0; i <= pos; i++)
        {
            tot_sum += (s[i] - '0');
        }
        cout << tot_sum << '\n';
    }

    return 0;
}