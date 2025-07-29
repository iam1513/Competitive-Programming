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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool is_prime(ll x) {
    if (x == 1) return false;
    for (int i = 2; i <= round(sqrt(x)); i++)
        if (x % i == 0) return false;
    return true;
}

void input(vll &v, ll n) {
    for (ll i = 0; i < n; i++) cin >> v[i];
}

void debug(const vll &v) {
    for (auto x : v) cout << x << " ";
    cout << "\n";
}


ll get_pow(ll x, ll c) {
    if (x > c) return -1;
    ll limit = c / x;
    ll p = 0;
    while ((1LL << (p + 1)) <= limit) p++;
    return p;
}

ll solve(ll n, ll c, const vll &a) {
    ll coins = 0;
    multiset<ll> st;

    for (ll i = 0; i < n; i++) {
        ll p = get_pow(a[i], c);
        if (p == -1) coins++;
        else st.insert(p);
    }

    ll curr = 0, ok = 0;
    for (auto it = st.begin(); it != st.end(); it++) {
        if (curr <= *it) {
            ok++;
            curr++;
        }
    }

    coins += st.size() - ok;
    return coins;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll T;
    cin >> T;

    while (T--) {
        ll n, c;
        cin >> n >> c;

        vll a(n);
        input(a, n);

        ll res = solve(n, c, a);
        cout << res << "\n";
    }

    return 0;
}
