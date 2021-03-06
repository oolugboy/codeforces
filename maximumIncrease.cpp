#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n = 0;
    scanf("%d", &n);
    int vals[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
    }
    int res = 1;
    int locRes = 1;
    for(int i = 0; i < (n - 1); i++)
    {
       if(vals[i] < vals[i + 1])
       {
            locRes++;
       }
       else
           locRes = 1;
       res = max(res, locRes);
    }
    printf("%d\n", res);
    return 0;
}
