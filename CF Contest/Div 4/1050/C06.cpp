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

        vector<vector<ll>> nums(n);
        ll maxi = INT_MIN;
        for (ll i = 0; i < n; i++)
        {
            ll k;
            cin >> k;
            maxi = max(maxi, k);

            while (k--)
            {
                ll x;
                cin >> x;
                nums[i].push_back(x);
            }
        }

        vll ans;

        for (ll j = 0; j < maxi; j++)
        {
            ll mini = INT_MAX;
            ll min_idx = -1;
            ll mini_cnt = 1;

            // bool flag = false;
            for (ll i = 0; i < n; i++)
            {
                if (nums[i].size() > j)
                {
                    if (nums[i][j] == mini && mini != INT_MAX)
                    {
                        mini_cnt++;
                    }
                    if (nums[i][j] < mini)
                    {
                        // cout << "HERE " << endl;
                        mini = min(mini, nums[i][j]);
                        min_idx = i;
                    }
                }
            }

            if (mini_cnt > 1)
            {
                // Need to find which row with 'mini' has the best remaining sequence
                ll best_row = -1;
                vector<ll> best_remaining;

                for (ll i = 0; i < n; i++)
                {
                    if (nums[i].size() > j && nums[i][j] == mini)
                    {
                        // Compare remaining sequences
                        vector<ll> remaining(nums[i].begin() + j, nums[i].end());

                        if (best_row == -1 || remaining < best_remaining)
                        {
                            best_row = i;
                            best_remaining = remaining;
                        }
                    }
                }

                // Take only the current element from the best row
                ans.push_back(mini);
                // Don't advance j - let next iteration handle next position
                continue;
            }

            // cout << "Min IDx : " << min_idx << endl;
            // cout << "Min IDX " << min_idx << endl;

            for (ll x = j; x < nums[min_idx].size(); x++)
            {
                ans.push_back(nums[min_idx][x]);
                j++;
            }
            j--;
        }

        for (ll i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}