# include <bits/stdc++.h>

using namespace std;
void articulationPointAndBridge(int u);


vector<int> dfs_low;
vector<int> dfs_num;
vector<int> dfs_parent;
vector<vector<pair<int, bool> > > AL;
vector<bool> articulation_vertex;
unordered_set<long long> bridges;
int dfsRoot;
int dfsNumberCounter;
int UNVISITED = -1;
int rootChildren = 0;

long long bridge_value (long long u, long long v) {
   return u * 20000 + v; 
}
void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (auto &v: AL[u]) {
        if (dfs_num[v.first] == UNVISITED) {
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++;

            articulationPointAndBridge(v.first);

            if (dfs_low[v.first] >= dfs_num[u])
                articulation_vertex[u] = true;
            if (dfs_low[v.first] > dfs_num[u]) {
                // printf(" Edge (%d, %d) is a bridge\n", u, v.first);
                bridges.insert(bridge_value(u, v.first));
                bridges.insert(bridge_value(v.first, u));
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        }
        else if (v.first != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    }

}

int main()
{
    int V; scanf("%d", &V);
    int E; scanf("%d", &E);
    AL.assign(V, vector< pair<int, bool> > (0));
    for (int i = 0; i < E; i++) {
        int u, v; scanf("%d %d", &u, &v);
        AL[u].push_back({v, false});
        AL[v].push_back({u, false});
    }
    dfsNumberCounter = 0;
    dfs_num.assign(V, UNVISITED);
    dfs_low.assign(V, 0);
    dfs_parent.assign(V, 0);
    articulation_vertex.assign(V, 0);
    // printf("Bridges: \n");
    for (int i = 0; i < V; i++) {
        if (dfs_num[i] == UNVISITED) {
            dfsRoot = i;
            rootChildren = 0;
            articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1);
        }
    }

    /*
    printf("Articulation Points:\n");
    for (int i = 0; i < V; i++) {
        if (articulation_vertex[i]) {
            printf(" Vertex %d\n", i);
        }
    } */
    queue<int> q;
    q.push(0);
    vector<bool> visited(V, false);
    visited[0] = true;
    int count = 0;
    //perform bfs over here
    while(!q.empty()) {
        count++;
        int u = q.front();
        q.pop();
        for (auto &v: AL[u]) {
            if (visited[v.first]) continue;
            if (bridges.find(bridge_value(v.first, u)) != bridges.end())
                continue;
            visited[v.first] = true;
            q.push(v.first);
        }
    }
    printf("%d\n", count);
}