#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int d = 0, k = 0, a = 0, b = 0, t = 0;
    scanf("%d%d%d%d%d", &d, &k, &a, &b, &t);
    if(d <= k)
    {
        printf("%d\n", (d * a));
    }
    else if(t + (k * a) > (k * b)) 
    {
        printf("%d\n", (k * a) + (d
    }
    return 0;
}
