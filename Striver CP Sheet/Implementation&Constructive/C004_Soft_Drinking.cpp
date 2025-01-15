#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;


    ll total_drink = k * l;  
    ll total_slices = c * d; 
    ll total_salt = p;       

    ll toasts_from_drink = total_drink / nl;
    ll toasts_from_slices = total_slices;
    ll toasts_from_salt = total_salt / np;
    ll max_toasts = min({toasts_from_drink, toasts_from_slices, toasts_from_salt});

    ll toasts_per_friend = max_toasts / n;

    cout << toasts_per_friend << endl;

    return 0;
}
