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

        string st;
        cin >> st;

        string ans;

        // Check for single character
        for (char x = 'a'; x <= 'z'; x++)
        {
            bool found = false;
            for (auto ele : st)
            {
                if (ele == x)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ans = string(1, x);
                break;
            }
        }

        if (!ans.empty())
        {
            cout << ans << "\n";
            continue;
        }

        // Check for two characters
        for (char x = 'a'; x <= 'z'; x++)
        {
            bool found_two = false;
            for (char y = 'a'; y <= 'z'; y++)
            {
                string to_check = string(1, x) + y;
                bool found = false;
                for (ll i = 0; i < n - 1; i++)
                {
                    string sub = st.substr(i, 2);
                    if (sub == to_check)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    ans = to_check;
                    found_two = true;
                    break;
                }
            }
            if (found_two)
                break;
        }

        if (!ans.empty())
        {
            cout << ans << "\n";
            continue;
        }

        // Check for three characters
        for (char x = 'a'; x <= 'z'; x++)
        {
            bool found_three = false;
            for (char y = 'a'; y <= 'z'; y++)
            {
                for (char z = 'a'; z <= 'z'; z++)
                {
                    string to_check = string(1, x) + y + z;
                    bool found = false;
                    for (ll i = 0; i < n - 2; i++)
                    {
                        string sub = st.substr(i, 3);
                        if (sub == to_check)
                        {
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        ans = to_check;
                        found_three = true;
                        break;
                    }
                }
                if (found_three)
                    break;
            }
            if (found_three)
                break;
        }

        cout << ans << "\n";
    }

    return 0;
}