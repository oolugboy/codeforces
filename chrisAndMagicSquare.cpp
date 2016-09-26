#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int vals[500][500];
int n = 0;
pair<bool,bool> isDiag()
{
    for(int i = 0; i < n; i++)
    {
        if(0 == vals[i][i])
            return make_pair(0,true);
    }
    int i = 0;
    for(int j = (n - 1); j >= 0; j--)
    {
        if(vals[i][j] == 0)
            return make_pair(1,true);
        i++;
    }
    return make_pair(0,false);
}   
long long int getTot()
{
    long long int tot = 0;
    bool found;
    long long int prev = -1;
    for(int i = 0; i < n; i++)
    {
        tot = 0;
        found = true;
        for(int j = 0; j < n; j++)
        {
            tot += vals[i][j];
            if(vals[i][j] == 0)
            {
                found = false;
            }
        }
        if(found)
        {
            if(prev != tot && prev != -1)
            {
                return -1;
            }
            else
                prev = tot;
        }
    }
    for(int j = 0; j < n; j++)
    {
        tot = 0;
        found = true;
        for(int i = 0; i < n; i++)
        {
            tot += vals[i][j];
            if(vals[i][j] == 0)
                found = false;
        }
        if(found)
        {
            if(prev != tot && prev != -1)
            {
                return -1;
            }
        }
    }
    tot = 0;
    found = true;
    for(int i = 0; i < n; i++)
    {
        tot += vals[i][i];
        if(vals[i][i] == 0)
            found = false;
    }
    if(found)
    {
        if(tot != prev && prev != -1)
        {
            return -1;
        }
    }
    tot = 0;
    found = true;
    int j = 0;
    for(int i = (n - 1); i >= 0; i--)
    {
        tot += vals[i][j];
        if(vals[i][j] == 0)
            found = false;
         j++;
    }
    if(found)
    {
        if(tot != prev && prev != -1)
        {
            return -1;
        }
    }
    return prev;
}
long long int getVal(pair<bool, bool>diag, int r, int c)
{
    if(n == 1)
        return 0;
    long long int tot = getTot();
    if(tot == -1)
        return -1;
    long long int res1 = 0, res2 = 0, res3 = 0, res4 = 0;
    int i = r;
    long long int lTot = 0;
    for(int j = 0; j < n; j++)
        lTot += vals[i][j];
    res1 = tot - lTot;
    //  cerr << " The res 1 " << res1 << endl;
    int j = c;
    lTot = 0;
    for(int i = 0; i < n; i++)
        lTot += vals[i][j]; 
    res2 = tot - lTot;
    if(res1 <= 0)
        return -1;
    if(res1 == res2 && diag.second == false)
        return res1;
    else if(res1 != res2 && diag.second == false)
        return -1;
    else if(res1 == res2 && diag.second == true)
    {
        lTot = 0;
        if(!(diag.first))
        {
            for(int i = 0; i < n; i++)
                lTot += vals[i][i];
            res3 = tot - lTot;
            // cerr << " The res 3 " << res3 << endl;
        }
        else
        {
            int k = 0;
            for(int i = (n - 1); i >= 0; i--)
            {
                lTot += vals[i][k];
                k++;
            }
            res3 = tot - lTot;
        }
        if(res3 == res1)
            return res1;
        else
            return -1;
    }
    else
        return -1;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    cin >> n;
    pair<int, int> cood;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> (vals[i][j]);
            if(vals[i][j] == 0)
                cood = make_pair(i,j);
        }
    }
    pair<bool,bool> diag = isDiag();
    long long int res = getVal(diag,cood.first, cood.second);
    if(res == 0)
        cout << 1 << endl;
    else
        cout << res << endl;
    return 0;
}
