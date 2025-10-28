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

    ll n, h;
    cin >> n >> h;

    vll nums(n);
    take_input_vector(nums, n);

    vll s;
    ll maxi = 0;
    for (ll i = 0; i < n; i++)
    {
        s.pb(nums[i]);
        ll till = h;
        sort(s.begin(), s.end(), greater<ll>());
        ll k = 0;
        for (ll j = 0; j < s.size(); j += 2)
        {
            till -= s[j];
            if (till < 0)
            {
                break;
            }
            if (j == s.size() - 1)
            {
                k++;
            }
            else
            {
                k += 2;
            }
        }

        maxi = max(maxi, k);
    }

    cout << maxi << "\n";

    return 0;
}