#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;
int maxD = numeric_limits<int>::max();
int minD = maxD;
class Node
{
    public:
        bool visited;
        bool store;
        vector< pair<int, int> >adj;
        int prev;
        int dist;
        int id;
        Node(int id):id(id), prev(-1), dist(maxD), store(false),visited(false){}
        Node(){}
};
class comp
{
public:
  bool operator() (pair<int, int > a, pair< int, int > b) const
  {
        return (a.second > b.second);
  }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n = 0, m = 0, k = 0;
    scanf("%d%d%d", &n, &m, &k);
    Node nodes[n + 1];
    for(int i = 1; i < (n + 1); i++)
    {
        nodes[i] = Node(i);
    }
    for(int i = 0; i < m; i++)
    {
        int s = 0, d = 0, dist = 0;
        scanf("%d%d%d", &s, &d, &dist);
        nodes[s].adj.push_back(make_pair(d,dist));
        nodes[d].adj.push_back(make_pair(s,dist));
    }
    for(int i = 0; i < k; i++)
    {
        int s = 0;
        scanf("%d", &s);
        nodes[s].store = true;
    }
    typedef priority_queue< pair<int, int> ,vector< pair<int, int> >, comp> pq;
    pq Q;
    nodes[1].dist = 0;
    Q.push(make_pair(1, 0));
    while(!(Q.empty()))
    {
        pair<int , int> curr = Q.top();
        Q.pop();
        int s = curr.first;
        if(nodes[s].visited == false)
        {
            nodes[s].visited = true;
            int size = nodes[s].adj.size();
            for(int i = 0; i < size; i++)
            {
                int d = nodes[s].adj[i].first;
                int dist = nodes[s].adj[i].second;
                if(nodes[d].visited == false && dist < nodes[d].dist)
                {
                    nodes[d].prev = s;
                    nodes[d].dist = dist;
                    Q.push(make_pair(d, dist));
                }
            }
        }
    }
   // printf(" Got through prim \n");
    for(int i = 1; i < n + 1; i++)
    {
        if(nodes[i].prev != -1)
        {
            int s = nodes[i].prev;
            if((nodes[s].store != nodes[i].store))
            {
                minD = min(minD, nodes[i].dist);
            }
        }
    }
    if(minD == maxD)
        printf("%d\n", -1);
    else
        printf("%d\n", minD);
    return 0;
}
