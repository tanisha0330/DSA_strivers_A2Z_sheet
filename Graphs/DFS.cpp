#include <bits/stdc++.h>
using namespace std; 

/*
Algorithm steps - 
1. pick a starting node - say 0 
2. mark it visited 
3. push it into result ( store in the dfs[] array).)
4. go to the unvisited neighbour , ->repeat step 2->4)
5. when (no unvisited neighbors) --> backtrack and try next ; 

*/



void dfs(int node, vector<int> adj[], vector<int> &vis, vector <int> &res)
{
  vis[node]=1; 
  res.push_back(node); 

  for (auto it: adj[node])
  {
    if (!vis[it])
    {
      dfs(it, adj, vis, res); 
    }
  }
}


vector <int> dfsofGraph(int v, vector<int> adj[])
{
  vector <int> vis(v,0); 
  vector <int> res; 

  dfs(0, adj, vis, res); 
  return res;
}


int main() {
    int v = 4;
    vector<int> adj[v];

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0};
    adj[3] = {1};

    vector<int> res = dfsofGraph(v, adj);

    cout << "DFS Traversal: ";
    for (int node : res)
        cout << node << " ";
}