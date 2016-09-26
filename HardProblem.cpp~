#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;

long long int maxVal = numeric_limits<long long int>::max();
string rev(string val)
{
    int size = val.size();
    string res = "";
    for(int i = 0; i < size; i++)
    {
        res = val[i] + res;
    }
    return res;
}   
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n = 0;
    cin >> n;
    string vals[n];
    long long int cost[n];
    long long int dp[n][2];
    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
       // cerr << " The init cost " << cost[i] << endl;
    }
    for(int i = 0; i < n; i++)
        cin >> vals[i];
    dp[0][0] = 0;
    dp[0][1] = cost[0];
    for(int i = 1; i < n; i++)
    { 
      //  cerr << " The i " << i << " and cost " << cost[i] << endl;
        bool found = false;
        dp[i][0] = dp[i][1] = maxVal;
        string reved = rev(vals[i - 1]);
        string jRev = rev(vals[i]);
        if(vals[i].compare(vals[i - 1]) >= 0)
        {
            if(dp[i - 1][0] != maxVal)
                dp[i][0] = min(dp[i][0], dp[i - 1][0]);
           // cerr << " The case 1 " << i <<  " "  << dp[i][0] << " " << dp[i][1] << endl;
        }
        if(vals[i].compare(reved) >= 0)
        {
            if(dp[i - 1][1] != maxVal)
                dp[i][0] = min(dp[i][0], dp[i - 1][1]);
          //  cerr << " The case 2 " << i <<  " "  << dp[i][0] << " " << dp[i][1] << endl;
        }
        if(jRev.compare(vals[i - 1]) >= 0)
        {
          //  cerr << " The cost " << cost[i] << " and i " << i << " the 3 "
           // << cost[3] << endl;
            if(dp[i - 1][0] != maxVal)
            {
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + cost[i]);
            }
         //   cerr << " The case 3 " << i <<  " "  << dp[i][0] << " " << dp[i][1] << endl;
        }
        if(jRev.compare(reved) >= 0)
        {
            if(dp[i - 1][1] != maxVal)
            {
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + cost[i]);
            }
          //  cerr << " The case 4 " << i <<  " "  << dp[i][0] << " " << dp[i][1] << endl;
        }
    }
    long long int res = min(dp[n - 1][0], dp[n - 1][1]);
    if(res == maxVal)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}

