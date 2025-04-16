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

    string x;
    cin >> x;

    if (x.length() != t)
    {
        cout << "NO\n";
        return 0;
    }

    ll sum1 = 0, sum2 = 0;
    bool flag = true;

    for (ll i = 0; i < t / 2; i++)
    {
        ll digit = x[i] - '0';
        sum1 += digit;
        if (digit != 4 && digit != 7)
        {
            flag = false;
        }
    }

    for (ll i = t / 2; i < t; i++)
    {
        ll digit = x[i] - '0';
        sum2 += digit;
        if (digit != 4 && digit != 7)
        {
            flag = false;
        }
    }

    if (sum1 == sum2 && flag)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}