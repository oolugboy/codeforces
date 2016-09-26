#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool func (int i,int j) { return (i<j); }
int main() {
    int n = 0;
    scanf("%d", &n);
    vector<int> vals;
   // vals.resize(n);
    int sum = 0, res = 0;
    for(int i = 0; i < n; i++)
    {
        int curr = 0;
        scanf("%d", &curr);
        sum+=curr;
        vals.push_back(curr);
    }
    sort(vals.begin(), vals.end(), func);
    if(n == 1)
        printf("%d\n", sum);
    else if(n == 2)
        printf("%d\n", (2 * sum));
    else
    {
        for(int i = 1; i < n; i++)
        {
            res += ((i + 1) * vals[i-1]);
        }
        res += n * vals[n - 1];
        printf("%d\n", res);
    }
    return 0;
}
