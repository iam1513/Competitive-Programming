#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> results(n, std::vector<int>(2));

    for (int i = 0; i < n; ++i)
    {
        std::cin >> results[i][0] >> results[i][1];
    }

    for (const auto &r : results)
    {
        if (r[0] != r[1])
        {
            std::cout << "rated" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (results[i][0] > results[j][0])
            {
                std::cout << "unrated" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "maybe" << std::endl;
    return 0;
}