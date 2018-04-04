#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define ll long long int

using namespace std;
const ll MAX = 1e12;
ll id[MAX], nodes, edges;
pair <ll, pair<ll, ll> > p[MAX];

void initialize()
{
    for(ll i = 0;i < MAX;++i)
        id[i] = i;
}

ll root(ll x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(ll x, ll y)
{
    ll p = root(x);
    ll q = root(y);
    id[p] = id[q];
}

ll kruskal(pair<ll, pair<ll, ll> > p[])
{
    ll x, y;
    ll cost, minimumCost = 0;
    for(ll i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    ll weight, cost, minimumCost;
    initialize();
    cin >> nodes;
    for (ll i = 0; i < nodes; i++) {
      for (ll j = i + 1; j < nodes; j++) {
	weight = i ^ j;
	p[edges] = make_pair(weight, make_pair(i, j));
	edges++;
      }
    }
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost;
    return 0;
}
