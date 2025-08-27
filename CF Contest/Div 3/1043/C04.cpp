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

bool is_nines_then_zeros(ll n, ll &m, ll &t)
{
    if (n == 0)
        return false;

    m = 0;
    t = 0;

    ll temp = n;
    while (temp > 0 && temp % 10 == 0)
    {
        t++;
        temp /= 10;
    }

    while (temp > 0)
    {
        if (temp % 10 != 9)
        {
            return false;
        }
        m++;
        temp /= 10;
    }

    return true;
}

vll get_divisors(ll n)
{
    vll divisors;
    if (n == 0)
        return divisors;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
            {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t_cases;
    cin >> t_cases;

    while (t_cases--)
    {
        ll n;
        cin >> n;

        if (n == 0)
        {
            cout << "0\n";
            continue;
        }

        sl cand;
        ll m, t;

        if (is_nines_then_zeros(n, m, t))
        {
            if (m % 2 == 0)
            {
                ll M = m / 2;
                vll divisors_of_M = get_divisors(M);

                for (ll k : divisors_of_M)
                {
                    ll base_power = 1;
                    for (ll j = 0; j < k; j++)
                    {
                        base_power *= 10;
                    }
                    ll d = base_power + 1;

                    if (d <= n)
                    {
                        ll x = n / d;
                        cand.insert(x);
                    }
                }
            }
        }
        else
        {
            ll b = 10;
            for (ll k = 1;; k++)
            {
                ll d = 1 + b;
                if (d > n)
                    break;

                if (n % d == 0)
                {
                    ll x = n / d;
                    cand.insert(x);
                }

                b *= 10;
                if (b > n)
                    break;
            }
        }

        if (cand.empty())
        {
            cout << "0\n";
        }
        else
        {
            cout << cand.size() << "\n";
            vll res(cand.begin(), cand.end());
            sort(res.begin(), res.end());
            for (ll i = 0; i < res.size(); i++)
            {
                if (i != 0)
                    cout << " ";
                cout << res[i];
            }
            cout << "\n";
        }
    }

    return 0;
}