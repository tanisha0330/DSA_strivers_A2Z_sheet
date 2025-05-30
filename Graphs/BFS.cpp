

#include <bits/stdc++.h>
using namespace std;


vector <int> bfsOfGraph(int v , vector <int> adj[])
{

  vector <int> vis(v,0); 
  vis[0]= 1; 
  queue <int> q; 
  q.push(0); 
  vector <int> bfs; 

  while (!q.empty())
  {
    int node = q.front(); 
    q.pop(); 
    bfs.push_back(node); 

     for (auto it: adj[node]) 
      {
        if (!vis[it])
        {
          vis[it]=1; 
          q.push(it); 
        }
      
      }
 }
 return bfs;

}
int main() {
    int v = 5;
    vector<int> adj[v];

    // Example graph:
    // 0 - 1 - 2
    // |
    // 3 - 4

    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1};
    adj[3] = {0, 4};
    adj[4] = {3};

    vector<int> res = bfsOfGraph(v, adj);

    cout << "BFS Traversal: ";
    for (int node : res)
        cout << node << " ";


  vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}}; 
  int cnt=0;
  cout<<endl;
  for (auto it: isConnected) cnt++;
  cout<<cnt;

}
