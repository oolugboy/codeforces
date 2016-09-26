#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    cin >> n;
    bool rest1[n];
    int vals[n];
    for(int i = 0; i < n; i++)
    {
        cin >> vals[i];
        rest1[i] = false;
    }
    if(vals[0] == 0)
        rest1[0] = true;
    for(int i = 1; i < n; i++)
    {
        if(vals[i] == 0)
            rest1[i] = true;
        if(vals[i] == 3 || rest1[i - 1] == true)
            continue;
        if(vals[i] == vals[i - 1])
            rest1[i] = true;
        else if(vals[i - 1] == 3)
        {
            int j = i - 1;
            int am = 0;
            while(vals[j] == 3 && j >= 0)
            {
                am++;
                j--;
            }
           // cout << " The j is " << j << " and the am is " << am << endl;
            if(j >= 0 && vals[j] != 3)
            {
                if(am % 2 == 1)
                {
                    if(vals[j] != vals[i] && rest1[j] == false)
                        rest1[i] = true;
                }
                else
                {
                    if(vals[j] == vals[i] && rest1[j] == false)
                        rest1[i] = true;
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        if(rest1[i] == true)
            res++;
    }
    cout << res << endl;
    return 0;
}
