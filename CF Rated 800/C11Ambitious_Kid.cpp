#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int mini = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int ab = abs(a);
        mini = min(ab, mini);
    }

    cout << mini << endl;

    return 0;
}