class Solution {
public:

    vector<vector<int>> graph;
    vector<int> disc, low;
    vector<vector<int>> ans;
    int timer = 0;

    void dfs(int u, int parent) {

        disc[u] = low[u] = timer++;

        for (int v : graph[u]) {

            // Don't go back through the same edge
            if (v == parent)
                continue;

            // v is not visited
            if (disc[v] == -1) {

                dfs(v, u);

                // Update low[u]
                low[u] = min(low[u], low[v]);

                // Bridge condition
                if (low[v] > disc[u]) {
                    ans.push_back({u, v});
                }
            }

            // v is already visited
            else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections
    ) {

        graph.resize(n);
        disc.assign(n, -1);
        low.assign(n, -1);

        // Build graph
        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // DFS
        dfs(0, -1);

        return ans;
    }
};