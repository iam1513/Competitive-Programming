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

    int t;
    cin >> t;

    while (t--)
    {
        string st, st2;
        cin >> st >> st2;

        bool isTung = true;

        int i = 0, j = 0;

        while (i < st.size() && j < st2.size())
        {
            if (st[i] != st2[j]) {
                isTung = false;
                break;
            }

            char ch = st[i];
            int cnt1 = 0, cnt2 = 0;

            while (i < st.size() && st[i] == ch) {
                cnt1++;
                i++;
            }

            while (j < st2.size() && st2[j] == ch) {
                cnt2++;
                j++;
            }

            if ((cnt2 < cnt1) || (cnt1 * 2 < cnt2)) {
                isTung = false;
                break;
            }
        }

        if (isTung && i == st.size() && j == st2.size())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
