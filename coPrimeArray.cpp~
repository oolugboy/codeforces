#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int p[1230];
bool v[10000];
void getPrimes()
{
    int end = sqrt(10000);
    for(int i = 0; i < 10000; i++)
        v[i] = true;
    for(int i = 2; i < (end + 1); i++)
    {
        for(int j = pow(i,2); j < 10000; j+=i)
        {
            v[j] = false;
        }
    }
    int index = 0;
    for(int i = 2; i < 10000; i++)
    {
        if(v[i] == true)
        {
           // printf("%s%d","The i ", i);
            p[index] = i;
            index++;
        }
    }
}
int gcd(int a, int b)
{
    int q = a/b;
    int r = a % b;
    if(r == 0)
        return b;
    else
        return gcd(b,r);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n = 0;
    scanf("%d", &n);
    int vals[n];
    getPrimes();
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
    }
    vector<int> res;
    int am = 0;
    for(int i = 0; i < (n - 1); i++)
    {

        int div = gcd(max(vals[i], vals[i + 1]), min(vals[i], vals[i +
        1]));
        if(div != 1)
        {
           am++;
           res.push_back(vals[i]);
           res.push_back(1);
        }
        else
            res.push_back(vals[i]);
    }
    res.push_back(vals[(n - 1)]);
    printf("%d\n", am);
    int size = res.size();
    for(int i = 0; i < size; i++)
    {
        printf("%d%s", res[i], " ");
    }
    printf("\n");
    return 0;
}

