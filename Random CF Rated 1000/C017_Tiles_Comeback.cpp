#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>

using namespace std;

void take_input_vector(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
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

        vll nums(n);
        take_input_vector(nums, n);

        ll i = 0, j = n - 1;
        ll left = 0, right = 0;
        ll k_left = k, k_right = k;

        if (nums[0] == nums[n - 1])
        {
            k_left = k / 2;
            k_right = k - k_left;
        }

        while (i < n && left < k_left)
        {
            if (nums[i] == nums[0])
            {
                left++;
            }
            i++;
        }

        while (j >= 0 && right < k_right)
        {
            if (nums[j] == nums[n - 1])
            {
                right++;
            }
            j--;
        }

        if (left == k_left && right == k_right && (i - 1) < (j + 1))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
