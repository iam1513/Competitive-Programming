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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        vector<bool> flip(n);
        ll c0 = 0, c1 = 0;
        for (ll i = 0; i < n; i++)
        {
            (a[i] == '0') ? c0++ : c1++;
            if (c0 == c1)
                flip[i] = 1;
        }

        bool f = 0, ok = 1;
        for (ll i = n - 1; i >= 0; i--)
        {
            if (!f)
            {
                if (a[i] != b[i])
                {
                    if (flip[i])
                        f ^= 1;
                    else
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            else
            {
                if (a[i] == b[i])
                {
                    if (flip[i])
                        f ^= 1;
                    else
                    {
                        ok = 0;
                        break;
                    }
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}