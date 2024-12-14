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

using namespace std;

vector<ll> findDivisors(ll n)
{
    vector<ll> divisors;

    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            divisors.push_back(i); // Add the divisor
            if (i != n / i)
            {
                divisors.push_back(n / i); // Add the complement divisor
            }
        }
    }

    sort(divisors.begin(), divisors.end()); // Sort the divisors
    return divisors;
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

        vector<ll> nums;
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            nums.push_back(a);
        }

        vector<ll> divisors = findDivisors(n);

        if (n == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            ll ans = LLONG_MIN;
            for (ll i = 0; i < divisors.size(); i++)
            {
                ll mini = LLONG_MAX, maxi = LLONG_MIN, sum = 0;
                ll j = 0, cnt = 0;
                while (j < n)
                {
                    sum += nums[j];
                    cnt++;
                    if (cnt == divisors[i])
                    {
                        cnt = 0;
                        mini = min(sum, mini);
                        maxi = max(sum, maxi);
                        sum = 0;
                    }

                    j++;
                }
                ans = max(ans, maxi - mini);
            }

            cout << ans << endl;
        }
    }

    return 0;
}