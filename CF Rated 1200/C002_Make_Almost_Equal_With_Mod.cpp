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

        vll nums(n);
        take_input_vector(nums, n);

        ll ans;

        // Its same as bas 10 ... say 122%10 = 22 ... We get last two digits ... so in base 2, we will get last bits 
        // say if all are evn the lsb for all will be 0 ...  but for 2,4,8,16 lsb3 = 0 for 2 and for all , it will be 1
        for (ll i = 1; i <= 57; i++)
        {
            mll mp;
            ll take_mod_with = (1LL << i); // as int has only 32 bits
            for (ll j = 0; j < n; j++)
            {
                mp[(nums[j] % take_mod_with)]++;
            }
            if (mp.size() == 2)
            {
                ans = take_mod_with;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}