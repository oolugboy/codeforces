#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


int getClosest(int start, int end, int towers[], int pos)
{
    int mid = ((end + start)/2);
    if(pos < towers[mid])
    {
        if(mid != start)
        {
            if(pos >= towers[mid - 1])
                return min(abs(towers[mid] - pos), abs(towers[mid - 1] -
                pos));  
            else
                return getClosest(start, mid, towers, pos);
        }
        else if(mid == start)
            return abs(towers[mid] - pos);
    }
    else
    {
        if(mid != end)
        {
            if(pos <= towers[mid + 1])
                return min(abs(towers[mid] - pos),abs(towers[mid + 1] -
                pos)); 
            else
            {
                return getClosest(mid + 1, end, towers, pos);
            }
        }
        else if(mid == end)
            return abs(towers[mid] - pos);
    }
}
int main() {
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    int cities[n];
    int towers[m];
    int closest[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &cities[i]);
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &towers[i]);
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        closest[i] = getClosest(0,(m - 1),towers,cities[i]);
       // printf("%s%d%s%d\n", " The closest for ",cities[i], " is ", closest[i]);
        res = max(res, closest[i]);
    }
    printf("%d\n", res);
    return 0;
}

