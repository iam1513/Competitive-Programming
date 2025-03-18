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

    string st1, st2, st3;
    cin >> st1 >> st2 >> st3;

    if ((st1 == st2 && st1 == "rock" && st3 == "paper") || (st1 == st2 && st1 == "paper" && st3 == "scissors") || (st1 == st2 && st1 == "scissors" && st3 == "rock"))
    {
        cout << "S" << endl;
        return 0;
    }

    if ((st3 == st2 && st3 == "rock" && st1 == "paper") || (st3 == st2 && st3 == "paper" && st1 == "scissors") || (st3 == st2 && st3 == "scissors" && st1 == "rock"))
    {
        cout << "F" << endl;
        return 0;
    }

    if ((st1 == st3 && st3 == "rock" && st2 == "paper") || (st1 == st3 && st1 == "paper" && st2 == "scissors") || (st1 == st3 && st1 == "scissors" && st2 == "rock"))
    {
        cout << "M" << endl;
        return 0;
    }

    cout << "?" << endl;

    return 0;
}