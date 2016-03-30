#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int am = 0;
    cin >> am;
    int alph[26];
    for(int i = 0; i < 26; i++)
    {
        alph[i] = 0;
    }
    while(am--)
    {
        string curr = "";
        cin >> curr;
        for(int i = 0; i < curr.size(); i++)
        {
            int index = (int)curr[i] - 97;
            alph[index]++;
        }
    }
    string res = "";
    for(int i = 0; i < 26; i++)
    {
        if(alph[i] != 0)
        {
            res = res + (char)(i + 97);
        }    
    }
    cout << res << endl;
    return 0;
}
