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

    int n;
    cin >> n;

    vector<int> nums(7, 100001);
    while (n--)
    {
        int p;
        string st;
        cin >> p >> st;

        sort(st.begin(), st.end());

        if (st == "A")
        {
            nums[0] = min(nums[0], p);
        }
        else if (st == "B")
        {
            nums[1] = min(nums[1], p);
        }
        else if (st == "C")
        {
            nums[2] = min(nums[2], p);
        }
        else if (st == "AB")
        {
            nums[3] = min(nums[3], p);
        }
        else if (st == "AC")
        {
            nums[5] = min(nums[5], p);
        }
        else if (st == "BC")
        {
            nums[4] = min(nums[4], p);
        }
        else if (st == "ABC")
        {
            nums[6] = min(nums[6], p);
        }
    }

    int f = (nums[0] == 100001 or nums[1] == 100001 or nums[2] == 100001) ? 3000003 : nums[0] + nums[1] + nums[2]; // A + B + C
    int s = (nums[4] == 100001 or nums[3] == 100001) ? 3000003 : nums[3] + nums[4];                                // AB + BC
    int t = (nums[3] == 100001 or nums[5] == 100001) ? 3000003 : nums[3] + nums[5];                                // AB + AC
    int fr = (nums[4] == 100001 or nums[5] == 100001) ? 3000003 : nums[4] + nums[5];                               // BC + AC
    int fv = (nums[2] == 100001 or nums[3] == 100001) ? 3000003 : nums[2] + nums[3];
    int sx = (nums[0] == 100001 or nums[4] == 100001) ? 3000003 : nums[0] + nums[4];
    int sv = (nums[1] == 100001 or nums[5] == 100001) ? 3000003 : nums[1] + nums[5];
    int eg = (nums[6] == 100001) ? 3000003 : nums[6];
    int ans = min({f, s, t, fr, fv, sx, sv, eg});

    // cout << f << " ";

    if (ans == 3000003)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}