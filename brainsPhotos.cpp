#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n = 0, m = 0;
    cin >> n >> m;
    bool color = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //cerr << " In here " << endl;
            string s = "";
            cin >> s;
            if(s[0] != 'W' && s[0] != 'G' && s[0] != 'B')
            {
                color = true;   
            }
        }
    }
    if(color)
        cout << "#Color" << endl;
    else
        cout << "#Black&White" << endl;
    return 0;
}
