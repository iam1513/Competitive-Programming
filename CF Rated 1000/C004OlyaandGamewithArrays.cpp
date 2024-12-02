#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll mini = 1e9, mini2 = 1e9, sum = 0;
        while (n--)
        {
            ll s;
            cin >> s;
            vector<ll> nums(s);
            for (ll i = 0; i < s; i++)
            {
                cin >> nums[i];
            }
            sort(nums.begin(), nums.end());
            mini = min(nums[0], mini);
            mini2 = min(nums[1], mini2);
            sum += nums[1];
        }

        cout << sum + mini - mini2 << endl;
    }

    return 0;
}