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
        string st;
        cin >> st;

        stack<pair<char, int>> s1, s2;
        for (ll i = 0; i < st.size(); i++)
        {
            if (st[i] - 'A' >= 0 && st[i] - 'A' < 26)
            {
                if (st[i] == 'B' && !s1.empty())
                {
                    s1.pop();
                }
                else if (st[i] != 'B')
                {
                    s1.push({st[i], i});
                }
            }
            else
            {
                if (st[i] == 'b' && !s2.empty())
                {
                    s2.pop();
                }
                else if (st[i] != 'b')
                {
                    s2.push({st[i], i});
                }
            }
        }

        string ans = "";
        while (!s1.empty() && !s2.empty())
        {
            if (s1.top().second > s2.top().second)
            {
                ans += s1.top().first;
                s1.pop();
            }
            else
            {
                ans += s2.top().first;
                s2.pop();
            }
        }
        while (!s1.empty())
        {
            ans += s1.top().first;
            s1.pop();
        }
        while (!s2.empty())
        {
            ans += s2.top().first;
            s2.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }

    return 0;
}