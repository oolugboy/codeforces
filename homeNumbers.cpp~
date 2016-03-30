#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int a = 0;
    int n = 0;
    cin >> n >> a;

    int countE = 1, countO = 1;
    int oStart = 1;
    int evStart = n;
    if(a % 2 == 0)
    {
        while(true)
        {
            if(evStart == a)
            {
                cout << countE << endl;
                return 0;
            }
            evStart -= 2;
            countE++;
        }
    }
    else
    {
        while(true)
        {
            if(oStart == a)
            {
                cout << countO << endl;
                return 0;
            }
            oStart += 2;
            countO++;
        }
    }
    return 0;
}
