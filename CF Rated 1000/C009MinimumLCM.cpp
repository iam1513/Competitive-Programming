#include <bits/stdc++.h>
#define ll long long
using namespace std;

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

        ll ans = LLONG_MAX;
        ll one = 0, two = 0;

        for (ll a = 1; a <= n / 2; a++)
        {
            ll b = n - a;
            ll gcd = __gcd(a, b);
            ll lcm = (a * b) / gcd;

            if (lcm < ans)
            {
                ans = lcm;
                one = a;
                two = b;
            }
        }

        cout << one << " " << two << endl;
    }

    return 0;
}
