#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;
int main() {
    cin >> n;
    long long int a = 0, c = 0;
    if(n == 1 || n == 2)
        cout << -1 << endl;
    else if(n % 2 == 0)
    {
        a = ((pow(n,2))/4) - 1;
        c = ((pow(n,2))/4) + 1;
        cout << a << " " << c << endl;
    }
    else
    {
       a = (pow(n,2) - 1);
       c = (pow(n,2) + 1);       
       if(a % 2 == 0  && c % 2 == 0)
            cout << (a/2) << " " << (c/2) << endl;
       else
           cout << -1 << endl;
    }
    return 0;
}

