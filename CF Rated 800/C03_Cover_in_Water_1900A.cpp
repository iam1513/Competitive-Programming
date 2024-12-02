#include <iostream>
using namespace std;

int func(int n, string st)
{
    int ans = 0;
    int cnt = 0;
    int maxi = 0;

    for (int i = 0; i < st.size(); i++)
    {
        if (st[i] == '.')
        {
            cnt++;
            // cout << cnt << " ";
        }
        else
        {
            ans += cnt;
            maxi = max(maxi, cnt);
            cnt = 0;
        }
    }
    ans += cnt;
    maxi = max(maxi, cnt);

    return (maxi > 2 ? 2 : ans);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string st;
        cin >> st;

        cout << func(n, st) << endl;
        // cout << endl
        //      << endl
        //      << endl;
    }

    return 0;
}