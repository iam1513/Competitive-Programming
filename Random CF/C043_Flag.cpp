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

    ll n, m;
    cin >> n >> m;

    vector<vector<char>> nums(n, vector<char>(m));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }

    bool flag = true;

    if (n == 1)
    {
        for (ll j = 1; j < m; j++)
        {
            if (nums[0][j - 1] != nums[0][j])
            {
                flag = false;
                break;
            }
        }
    }

    for (ll i = 1; i < n; i++)
    {

        if (!flag)
            break;

        if (nums[i - 1][0] == nums[i][0])
        {
            flag = false;
            break;
        }
        for (ll j = 1; j < m; j++)
        {
            if (nums[i][j - 1] != nums[i][j])
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}