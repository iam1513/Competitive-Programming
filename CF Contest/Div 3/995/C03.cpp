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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m, k;

        cin >> n >> m >> k;
        mll nums1, nums2;
        ll sum1 = 0, sum2 = 0;
        vll ms(m);
        vll ks(k);
        for (ll i = 0; i < m; i++)
        {
            cin >> ms[i];
            nums1[ms[i]]++;
            sum1 += ms[i];
        }
        for (ll i = 0; i < k; i++)
        {
            cin >> ks[i];
            nums2[ks[i]]++;
            sum2 += ks[i];
        }

        string ans = "";
        for (ll i = 0; i < m; i++)
        {
            ans += '0';
        }
        if (n > m)
        {
            cout << ans << endl;
        }

        else
        {
            if (m == k)
            {
                for (ll i = 0; i < m; i++)
                {
                    ans[i] = '1';
                }

                cout << ans << endl;
            }
            else if (m - k == 1)
            {
                ll find = sum1 - sum2;

                for (ll i = 0; i < m; i++)
                {
                    if (i + 1 == find)
                    {
                        ans[i] = '1';
                    }
                }

                cout << ans << endl;
            }

            else
            {
                cout << ans << endl;
            }
        }
    }

    return 0;
}