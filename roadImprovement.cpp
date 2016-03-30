#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Edge
{
    public:

        int u;
        int v;
        bool used;
        void setUV(int u, int v)
        {
            this->u = u;
            this->v = v;
            used = false;
        }
};

void clearCities(int cities[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cities[i] = 0;
    }
}
int main() {
    int n = 0;
    cin >> n;
    Edge roads[(n-1)];
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            roads[i].used = true;
            continue;
        }
        int u = 0;
        int v = 0;
        cin >> u >> v;
        roads[i].setUV(u,v);

    }
    int cities[n+1];
    vector< list<int> > res;
    int setAm = 0;
    int day = 0;
    list<int> locRes;
    for(int i = 0; i < n; i++)
    {
        locRes.clear();
        clearCities(cities,(n+1));
        setAm = 0;
        if(roads[i].used == false) 
        {
            roads[i].used = true;
            cities[roads[i].u]++;
            cities[roads[i].v]++;
            locRes.push_front(i);
            setAm++;
        }
        for(int j = 0; j < n; j++)
        {
            if(roads[j].used == false)
            {
                if(cities[roads[j].u] == 0 && cities[roads[j].v] == 0)
                {
                    roads[j].used = true;
                    cities[roads[j].u]++;
                    cities[roads[j].v]++;
                    locRes.push_front(j);
                    setAm++;
                }

            }
        }
        if(locRes.size() != 0)
        {
            locRes.push_front(setAm);
            res.push_back(locRes);
            day++;
        }
    }
    cout << day << endl;
    vector< list<int> >:: iterator it = res.begin();
    vector< list<int> >:: iterator ven = res.end();

    for(; it != ven; it++)
    {
        list<int>::iterator lit = (*it).begin();
        list<int>::iterator len = (*it).end();

        for(;lit != len; lit++)
        {
            cout << (*lit) << " ";
        }
        cout << endl;
    }
    return 0;
}
