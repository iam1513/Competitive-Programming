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

ll pos_from_left(ll n, int k)
{
    string bits = bitset<64>(n).to_string(); // 64-bit binary
    int first_one = -1;
    int count = 0;
    for (int i = 0; i < 64; i++)
    {
        if (bits[i] == '1')
        {
            if (++count == k)
                return i; // kth set bit from left
        }
    }
    return -1; // not found
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, d;
        cin >> n >> d;

        ll ans = -1;

        if (n % 2 == 1 && d % 2 == 0)
        {
            if (n % d == 1)
            {
                ans = n / d;
            }
        }

        else
        {
            while (n >= 1)
            {
                if (n - d == 1)
                {
                    cout << n << endl;
                    ans++;
                    break;
                }
                if (n % 2 == 1 && d % 2 == 1)
                {
                    cout << n << endl;
                    n = n - d;
                    ans++;
                }
                else if (n % 2 == 0)
                {
                    ll pos = pos_from_left(n, 2);
                    ll temp = n - d;

                    ll pos_2 = pos_from_left(temp, 2);

                    if (pos_2 > pos)
                    {
                        cout << n << endl;
                        n = temp;
                        ans++;
                    }
                    else
                    {
                        cout << n << endl;
                        n /= 2;
                        ans++;
                    }
                }
                else
                {
                    cout << n << endl;
                    n -= d;
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}