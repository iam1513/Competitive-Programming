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

        vll a(n), b(n);
        take_input_vector(a, n);
        take_input_vector(b, n);

        bool flag = false;

        ll prev = -1;
        ll cnt_minus = 0;
        ll mini = INT_MAX;
        ll maxi = INT_MIN;
        for (ll i = 0; i < n; i++)
        {
            if (b[i] != -1)
            {
                ll sum = b[i] + a[i];
                if (prev == -1)
                {
                    prev = sum;
                }
                if (prev != -1 && a[i] + b[i] != prev)
                {
                    flag = true;
                    break;
                }
            }
            if (b[i] == -1)
            {
                cnt_minus++;
            }
            if (a[i] < mini)
            {
                mini = a[i];
            }
            if (a[i] > maxi && b[i] == -1)
            {
                maxi = a[i];
            }
        }

        if (flag || mini + k < prev || (maxi > prev && prev != -1 && maxi != INT_MIN))
        {
            cout << 0 << endl;
            continue;
        }

        if (!flag && cnt_minus != n)
        {
            cout << 1 << endl;
            continue;
        }

        ll L = INT_MIN, R = INT_MAX;

        for (ll i = 0; i < n; i++)
        {
            L = max(L, a[i]);
            R = min(R, a[i] + k);
        }
        cout << max(0LL, R - L + 1) << endl;
    }

    return 0;
}