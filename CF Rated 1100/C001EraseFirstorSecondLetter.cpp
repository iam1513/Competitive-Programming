#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<string> s;
unordered_set<string> visited;

void recom(const string &st)
{

    if (st.empty() || visited.count(st))
        return;

    visited.insert(st);
    s.insert(st);

    if (!st.empty())
    {
        string temp1 = st.substr(1);
        recom(temp1);
    }

    if (st.size() > 1)
    {
        string temp2 = st[0] + st.substr(2);
        recom(temp2);
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
        ll n;
        cin >> n;

        string st;
        cin >> st;

        recom(st);

        cout << s.size() << endl;
        s.clear();
        visited.clear();
    }

    return 0;
}