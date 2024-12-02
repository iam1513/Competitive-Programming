#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> nums(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        for (ll i = 0; i < n; i++)
        {
            nums[i] = nums[i] % k;
            if (nums[i] == 0)
            {
                nums[i] = k;
            }
        }

        vector<ll> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](ll i, ll j)
             { return nums[i] > nums[j]; });

        for (ll i = 0; i < n; i++)
        {
            cout << indices[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}