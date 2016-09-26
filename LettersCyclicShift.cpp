#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;


int main() { 
    char s[100001];
    cin >> s;
    int size = strlen(s);
    bool found = false;
    for(int i = 0; i < size; i++)
    {
        if(s[i] == 'a')
            continue;
        else
        {
            found = true;
            for(int j = i; j < size; j++)
            {
                if(s[j] == 'a')
                {
                    break;
                }
                else
                {
                    s[j]--;
                }
            }
            goto end;
        }
    }
    end:
        if(found == false)
            s[size - 1] = 'z';
        cout << s << endl;
    return 0;
}

