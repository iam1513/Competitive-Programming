#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
using namespace std;

bool check(vll &nums, ll x, ll k) {
    ll n = nums.size();
    ll cnt = 0;

    for (ll i = 0; i < x; i++) {
        if (nums[i] == 0) cnt++;
    }

    if (cnt <= k) return true;

    for (ll start = 1, end = x; end < n; start++, end++) {
        if (nums[start - 1] == 0) cnt--; 
        if (nums[end] == 0) cnt++;       
        if (cnt <= k) return true;      
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        vll nums(n);
        for (ll i = 0; i < n; i++) {
            cin >> nums[i];
        }

        ll lo = 0, hi = n, ans = 0;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (check(nums, mid, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
