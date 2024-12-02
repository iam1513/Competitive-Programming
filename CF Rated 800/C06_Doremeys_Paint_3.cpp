#include <iostream>
#include <vector>
#include <map>
#include <algorithm>>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            mp[a]++;
        }
        if (mp.size() >= 3)
        {
            cout << "No" << endl;
        }

        else
        {
            if (abs(mp.begin()->second - mp.rbegin()->second) <= 1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}