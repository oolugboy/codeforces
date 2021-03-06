#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector< vector< int > >comps;
int n = 0;
class Node
{
   
    public:
        int id;
        bool visited;
        vector<int> adj;
        Node(int id):id(id), visited(false){}
        Node(){}
};
void explore(int curr, Node nodes[], vector<int> &comp)
{
    nodes[curr].visited = true;
    comp.push_back(curr);
    int size = nodes[curr].adj.size();
    for(int i = 0; i < size; i++)
    {
       int ind = nodes[curr].adj[i];
       if(nodes[ind].visited == false)
       {
           explore(ind, nodes, comp);
       }
    }
}
int dfs(int former[], Node nodes[])
{
    for(int i = 1; i < n + 1; i++)
    {
        vector< int > comp;
        comp.clear();
        if(nodes[i].visited == false)
        {
           // cout << " The starting curr is " << i << endl;
            explore(i, nodes, comp);
          //  cerr << " The size of the just finished comp is " <<
           // comp.size() <<   endl;
            comps.push_back(comp);
        }
    }
  //  cout << " Done with all the exploring " << endl;
    int size = comps.size();
 //   cout << " The amount of components is " << size << endl;
    int am = 0;
    for(int i = 0; i < size; i++)
    {
    //    cout << " Executing the inner loop " << endl;
        int jSize = comps[i].size();
    //    cout << " The jSize is " << jSize << endl;
        bool cycle = true;
        for(int j = 0; i < jSize; j++)
        {
    //        cout << " about to get the s " << endl;
            int s = comps[i][j];
            if(former[s] == s)
            {
                cycle = false;
                if(i != 0)
                {
                    am++;
                    former[s] = comps[i - 1][0];
                }
                break;
            }
        }
        if(cycle && i != 0)
        {
            am++;
            former[comps[i][0]] = comps[i - 1][0];
        }
        else if(cycle && i == 0)
        {
            am++;
            former[comps[i][0]] = comps[i][0];
        }
    }
    return am;
}
int main() {
    cin >> n;
    Node nodes[n + 1];
    int former[n + 1];
    for(int i = 0; i < n + 1; i++)
    {
        nodes[i] = Node(i);
        former[i] = 0;
    }
    for(int i = 1; i < (n + 1); i++)
    {
        int p = 0;
        cin >> p;
        former[i] = p;
        nodes[i].adj.push_back(p);
        if(p != i)
            nodes[p].adj.push_back(i);
      //  cout << " working before the dfs " << endl;
    }
    int res = dfs(former, nodes);
    cout << res << endl;
    for(int i = 1; i < n + 1; i++)
        cout << former[i] << " ";
    cout << endl;
    return 0;
}
