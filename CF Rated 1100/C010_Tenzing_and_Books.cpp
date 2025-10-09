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
        ll n, x;
        cin >> n >> x;

        queue<ll> a, b, c;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.push(x);
        }

        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            b.push(x);
        }
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            c.push(x);
        }

        bool ct_1 = true, ct_2 = true, ct_3 = true;
        ll start = 0;

        while ((ct_1 && !a.empty()) || (ct_2 && !b.empty()) || (ct_3 && !c.empty()))
        {
            bool took_number = false;

            if (ct_1 && !a.empty())
            {
                ll f = a.front();
                if ((f | x) == x)
                {
                    start |= f;
                    a.pop();
                    took_number = true;
                }
                else
                {
                    ct_1 = false;
                }
            }

            if (ct_2 && !b.empty())
            {
                ll f = b.front();
                if ((f | x) == x)
                {
                    start |= f;
                    b.pop();
                    took_number = true;
                }
                else
                {
                    ct_2 = false;
                }
            }

            if (ct_3 && !c.empty())
            {
                ll f = c.front();
                if ((f | x) == x)
                {
                    start |= f;
                    c.pop();
                    took_number = true;
                }
                else
                {
                    ct_3 = false;
                }
            }

            if (!ct_1 && !ct_2 && !ct_3)
                break;
            if (!took_number)
                break;
            if (start == x)
                break;
        }

        if (start == x)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}