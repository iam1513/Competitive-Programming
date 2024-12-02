#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string st;
        cin >> st;

        int cnt0 = 0, cnt1 = 0;

        string t = "";

        for (int i = 0; i < st.size(); i++)
        {
            if (st[i] == '0')
            {
                cnt0++;
            }
            else
            {
                cnt1++;
            }
        }

        int ans = 0;
        int i = 0;

        while (i < st.size())

        {

            if ((st[i] == '0' && cnt1 == 0) || (st[i] == '1' && cnt0 == 0))
            {
                break;
            }

            else if (st[i] == '0' && cnt1 != 0)
            {
                i++;
                cnt1--;
            }
            else if (st[i] == '1' && cnt0 != 0)
            {
                i++;
                cnt0--;
            }
        }

        cout << st.size() - i << endl;
    }

    return 0;
}