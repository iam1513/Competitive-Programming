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
        cin >> nums[i];
}

void print_vector_to_debug(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
        cout << nums[i] << " ";
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
        ll n, m;
        cin >> n >> m;

        vector<vector<ll>> nums(n, vector<ll>(m));
        ll maxi = INT_MIN;

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> nums[i][j];
                maxi = max(maxi, nums[i][j]);
            }
        }

        mll rows, cols;
        vector<pair<ll, ll>> store;

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (nums[i][j] == maxi)
                {
                    rows[i]++;
                    cols[j]++;
                    store.push_back({i, j});
                }
            }
        }

        bool ans = false;
        set<ll> row_set;
        for (auto &entry : rows)
            row_set.insert(entry.first);

        for (auto r : row_set)
        {
            ll col_c = -1;
            bool valid = true;
            for (auto &p : store)
            {
                ll ri = p.first;
                ll ci = p.second;

                if (ri == r)
                    continue;

                if (col_c == -1)
                    col_c = ci;
                else if (ci != col_c)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                ans = true;
                break;
            }
        }

        if (ans)
        {
            cout << maxi - 1 << endl;
        }
        else
        {
            cout << maxi << endl;
        }
    }

    return 0;
}
