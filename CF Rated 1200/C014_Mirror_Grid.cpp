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

        vector<vector<char>> grid(n, vector<char>(n));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        ll ans = 0;

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (grid[i][j] != 'D') // Only process if not already processed
                {
                    ll cnt_0 = 0, cnt_1 = 0;

                    // Get all 4 rotations for position (i, j)
                    ll x1 = i, y1 = j;
                    ll x2 = j, y2 = n - 1 - i;
                    ll x3 = n - 1 - i, y3 = n - 1 - j;
                    ll x4 = n - 1 - j, y4 = i;

                    // Count 0s and 1s in the rotation group
                    if (grid[x1][y1] == '1')
                        cnt_1++;
                    else
                        cnt_0++;

                    if (grid[x2][y2] == '1')
                        cnt_1++;
                    else
                        cnt_0++;

                    if (grid[x3][y3] == '1')
                        cnt_1++;
                    else
                        cnt_0++;

                    if (grid[x4][y4] == '1')
                        cnt_1++;
                    else
                        cnt_0++;

                    // Mark all positions in this rotation group as processed
                    grid[x1][y1] = 'D';
                    grid[x2][y2] = 'D';
                    grid[x3][y3] = 'D';
                    grid[x4][y4] = 'D';

                    ans += min(cnt_0, cnt_1);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}