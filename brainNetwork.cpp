#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int maxD = 1000000;
class comp
{
    public:
        bool operator() (pair<int, int> a, pair<int, int> b)
        {
            return (a.second > b.second);
        }
};
void clear(bool v[], int dist[], int n)
{
    for(int i = 0; i < (n + 1); i++)
    {
        v[i] = false;
        dist[i] = maxD;
    }

}
int dijk(bool v[], int dist[], vector< vector<int> >map, int source, int n)
{
    typedef priority_queue< pair<int, int> , vector< pair<int,int> >, comp> mypq_type;
    mypq_type Q;
    for(int i = 1; i < n + 1; i++)
        Q.push(make_pair(i, dist[i]));
    Q.push(make_pair(source, 0));
    while(!(Q.empty()))
    {
        pair<int, int> curr = Q.top();
        Q.pop();
        if(v[curr.first] == false)
        {
            v[curr.first] = true;
            dist[curr.first] = curr.second;
            int size = map[curr.first].size();
            for(int i = 0; i < size; i++)
            {
                int adj = map[curr.first][i];
                if(v[adj] == false && (curr.second + 1) < dist[adj])
                {
                    Q.push(make_pair(adj, (curr.second + 1)));
                }
            }
        }
    }
    int res = 0;
    int maxDist = 0;
    for(int i = 1; i < (n + 1); i++)
    {
        if(dist[i] > maxDist)
        {
            maxDist = dist[i];
            res = i;
        }
    }
    return res;
}
int main() 
{
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    vector< vector<int> >map;
    map.resize(n + 1);
    for(int i = 0; i < m; i++)
    {
        int s = 0, d = 0;
        scanf("%d%d", &s, &d);
        map[s].push_back(d);
        map[d].push_back(s);
    }
    int dist[n + 1];
    bool v[n + 1];
    clear(v,dist,n);
    int u = dijk(v,dist,map,1,n);
    clear(v,dist,n);
    int res = dijk(v,dist,map,u,n);
    printf("%d\n", dist[res]);
    return 0;
}
