#include <iostream>
#include <string>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    string x, s;
    cin >> x >> s;

    for (int i = 0; i < 6; ++i)
    {
        // std::string::npos is a constant that represents the value returned when find fails.
        // It is essentially the largest possible value for a size_t type, indicating "not found."
        if (x.find(s) != string::npos)
        {
            cout << i << endl;
            return;
        }
        x += x;
    }

    cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
