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
        ll n;
        cin >> n;

        vll a(n), b(n);
        take_input_vector(a, n);
        take_input_vector(b, n);

        vll x = a, y = b;

        ll ans = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                    ans++;
                }
            }
        }

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (b[j] > b[j + 1])
                {
                    swap(b[j], b[j + 1]);
                    ans++;
                }
            }
        }

        for (ll i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                ans++;
            }
        }

        cout << ans << endl;
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (x[j] > x[j + 1])
                {
                    swap(x[j], x[j + 1]);
                    cout << "1" << " " << j + 1 << endl;
                }
            }
        }

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (y[j] > y[j + 1])
                {
                    swap(y[j], y[j + 1]);
                    cout << "2" << " " << j + 1 << endl;
                }
            }
        }

        for (ll i = 0; i < n; i++)
        {
            if (x[i] > y[i])
            {
                cout << "3" << " " << i + 1 << endl;
            }
        }
    }

    return 0;
}