#include <bits/stdc++.h>
using namespace std;

int main()
{

    int q;
    cin >> q;

    while (q--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int cnt = 0;

        int n = min(s1.size(), s2.size());

        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                break;
            }
            else
            {
                cnt++;
            }
        }

        int ans = 0;

        if (cnt > 0)
        {
            ans = cnt + 1 + (s1.size() - cnt) + (s2.size() - cnt);
        }
        else
        {
            ans = s1.size() + s2.size();
        }
        cout << ans << endl;
    }

    return 0;
}