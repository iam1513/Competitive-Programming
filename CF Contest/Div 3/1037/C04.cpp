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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<vector<ll>> nums(n, vector<ll>(3));
        for (ll i = 0; i < n; ++i)
        {
            cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
        }

        sort(nums.begin(), nums.end());

        ll curr = k;
        bool flag = true;
        priority_queue<pll> pq;
        ll ptr = 0;

        while (flag)
        {
            flag = false;
            while (ptr < n && nums[ptr][0] <= curr)
            {
                if (nums[ptr][1] >= curr)
                {
                    pq.emplace(nums[ptr][2], nums[ptr][1]);
                }
                ptr++;
            }

            if (!pq.empty())
            {
                auto top = pq.top();
                pq.pop();
                if (top.first > curr)
                {
                    curr = top.first;
                    flag = true;
                }
            }
        }

        cout << curr << "\n";
    }

    return 0;
}