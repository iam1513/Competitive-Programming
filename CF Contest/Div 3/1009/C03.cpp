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

bool isPowerOfTwo(int x)
{
    return (x & (x - 1)) == 0;
}

bool isAllOnes(int x)
{
    return (x & (x + 1)) == 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (isPowerOfTwo(x) || isAllOnes(x))
        {
            cout << -1 << "\n";
            continue;
        }
        int ans = -1;

        for (int p = 31; p >= 0 && ans == -1; p--)
        {
            if (x & (1 << p))
            {
                for (int q = p - 1; q >= 0 && ans == -1; q--)
                {
                    if ((x & (1 << q)) == 0)
                    { 
                        int candidate = x - (1 << p) + (1 << q);
                        ans = candidate;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
