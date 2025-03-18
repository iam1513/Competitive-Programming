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

        string st;
        cin >> st;

        // Find all log positions
        vector<ll> logs;
        for (ll i = 0; i < n; i++)
        {
            if (st[i] == 'L')
            {
                logs.push_back(i);
            }
        }
        logs.push_back(n); // Add the right bank as a log

        bool flag = true;
        ll swim_distance = 0;
        ll current_position = -1; // Start at the left bank
        ll next_log = 0;

        while (current_position < n - 1)
        {
            // Jump as far as possible to the next log
            if (m >= logs[next_log] - current_position)
            {
                current_position = logs[next_log];
                next_log++;
            }
            else
            {
                // Jump as far as possible within m meters
                current_position += m;

                // If we jump beyond the river, succeed
                if (current_position >= n)
                {
                    break;
                }

                // Swim through water segments until the next log
                while (current_position < n && current_position < logs[next_log])
                {
                    if (st[current_position] == 'C')
                    {
                        // Cannot land on a crocodile
                        flag = false;
                        break;
                    }
                    else if (st[current_position] == 'W')
                    {
                        swim_distance++;
                        if (swim_distance > k)
                        {
                            flag = false;
                            break;
                        }
                    }
                    current_position++;
                }

                if (!flag)
                {
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
    }

    return 0;
}