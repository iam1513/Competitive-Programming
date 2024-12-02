#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n % 3 == 1 || n % 3 == 2)
        {
            cout << "First" << endl;
        }
        else
        {
            cout << "Second" << endl;
        }
    }

    return 0;
}