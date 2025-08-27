#include <bits/stdc++.h>

using namespace std;

class dsu
{

    vector<int> parent, rank;

public:
    dsu(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUlP(int n)
    {
        if (parent[n] == n)
        {
            return n;
        }

        return parent[n] = findUlP(parent[n]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUlP(u);
        int ulp_v = findUlP(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};