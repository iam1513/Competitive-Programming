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

        mll mp;

        for (auto ele : nums)
        {
            mp[ele]++;
        }

        bool flag = true;

        for (auto ele : mp)
        {
            if (ele.second % ele.first != 0)
            {
                flag = false;
                break;
            }
        }

        if (flag == false)
        {
            cout << "-1" << endl;
        }
        else
        {
            unordered_map<ll, pair<ll, ll>> m1;
            vll ans;

            ll k = 1;
            for (ll i = 0; i < n; i++)
            {
                if (m1.find(nums[i]) != m1.end())
                {
                    m1[nums[i]].second--;
                    ans.push_back(m1[nums[i]].first);
                    if (m1[nums[i]].second == 0)
                    {
                        m1.erase(nums[i]);
                    }
                }
                else
                {
                    m1[nums[i]] = make_pair(k, nums[i] - 1);
                    if (m1[nums[i]].second == 0)
                    {
                        m1.erase(nums[i]);
                    }
                    ans.push_back(k);
                    k++;
                }
            }
            for (auto ele : ans)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
    }

    return 0;
}