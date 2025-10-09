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
        ll l, r;
        cin >> l >> r;
        vector<ll> ans; // Vector to store the result array

        // Loop through each index from 1 to n
        bool flag = false;
        for (ll i = 1; i <= n; i++)
        {
            // Calculate the smallest multiple of i that is >= l
            ll temp = ((l + i - 1) / i) * i;
            ans.push_back(temp); // Add the calculated value to the result array

            // If the calculated value exceeds r, no valid array can be formed
            if (temp > r)
            {
                cout << "NO" << endl;
                flag = true;
                break;
            }
        }

        if (flag)
        {
            continue;
        }

        // If all values are within the range, print "YES" and the array
        cout << "YES" << endl;
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}