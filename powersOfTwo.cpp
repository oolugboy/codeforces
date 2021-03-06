#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int valMax = pow(10,9) + 1;
void init(bool * vals, int * inds)
{
    for(int i = 0; i < valMax; i++)
    {
        vals[i] = false;
        inds[i] = -1;
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    bool * vals = new bool[valMax];
    int * inds = new int[valMax];
    init(vals, inds);
    for(int i = 0; i < n; i++)
    {
        int curr = 0;
        scanf("%d", &curr);
    }
    return 0;
}
