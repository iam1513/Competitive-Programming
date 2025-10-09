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

        ll cnt_0 = 0;
        for (auto ele : st)
        {
            if (ele == '0')
            {
                cnt_0++;
            }
        }

        if (cnt_0 == st.size())
        {
            cout << 0 << endl;
            continue;
        }

        ll maxi = 0;
        ll l = -1;
        ll r = 0;

        while (r < st.size())
        {
            if (st[r] == '0')
            {
                ll cnt = r - l - 1;
                maxi = max(maxi, cnt);
                l = r;
                r++;
            }
            else
            {
                r++;
            }
        }
        maxi = max(maxi, (ll)(st.size() - l - 1));

        ll x = 0, y = 0;

        for (ll i = 0; i < st.size(); i++)
        {
            if (st[i] == '0')
            {
                break;
            }
            x++;
        }

        for (ll i = st.size() - 1; i >= 0; i--)
        {
            if (st[i] == '0')
            {
                break;
            }
            y++;
        }

        // cout << "x " << x << " y " << y << endl;

        if (x + y <= st.size())
        {
            maxi = max(maxi, x + y);
        }

        // cout << "Maxi " << maxi << endl;

        if (maxi == st.size())
        {
            cout << maxi * maxi << endl;
        }
        else if (maxi == 1)
        {
            cout << '1' << endl;
        }
        else
        {
            maxi++;
            ll temp = (maxi + 1) / 2;
            cout << temp * (maxi / 2) << endl;
        }
    }

    return 0;
}