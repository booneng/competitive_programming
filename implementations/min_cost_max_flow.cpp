#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to, flow, cap, cost, rev;

    edge(int to, int flow, int cap, int cost, int rev)
        : to(to), flow(flow), cap(cap), cost(cost), rev(rev) {}
};


class MinCostMaxFlow {
    int n_;
    vector<int> potentials_;
    vector<pair<int, int>> path_;
    vector<vector<edge>> graph_;

    void AddEdge(int u, int v, int cap, int cost) {
        edge e1 = edge(v, 0, cap, cost, graph_[v].size());
        edge e2 = edge(u, 0, 0, -cost, graph_[u].size());

        graph_[u].push_back(e1);
        graph_[v].push_back(e2);
    }

    int SPFA(int s, int t) {
    queue<int> q;
    vector<bool> in_queue(n_, false);
    vector<int> dists(n_, INT_MAX);
    dists[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        in_queue[cur] = false;
        for (int i = 0; i < graph_[cur].size(); i++) {
        edge e = graph_[cur][i];
        int next = e.to;
        int cost = e.cost;
        if (e.flow < e.cap && dists[cur] + cost < dists[next]) {
            dists[next] = dists[cur] + cost;
            path_[next] = {cur, i};
            if (!in_queue[next]) {
            q.push(next);
            in_queue[next] = true;
            }
        }
        }
    }
    return dists[t];
    }

    void BellmanFord(int s) {
    queue<int> q;
    vector<int> in_queue(n_, false);
    fill(potentials_.begin(), potentials_.end(), INT_MAX);
    potentials_[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        in_queue[cur] = false;
        for (edge& e : graph_[cur]) {
            int next = e.to;
            int cost = e.cost;
            if (potentials_[next] > potentials_[cur] + cost) {
                potentials_[next] = potentials_[cur] + cost;
                if (!in_queue[next]) {
                in_queue[next] = true;
                q.push(next);
                }
            }
        }
    }
    }

    int Dijkstra(int s, int t) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>()> q;
        vector<int> dists(n_, INT_MAX);
        vector<int> flow(n_, 0);
        q.push({0, s});
        dists[s] = 0;
        flow[s] = INT_MAX;
        while (!q.empty()) {
            int cur = q.top().second;
            int dist = q.top().first;
            q.pop();
            if (dist != dists[cur]) continue;
            for (int i = 0; i < graph_[cur].size(); i++) {
                edge& e = graph_[cur][i];
                int next = e.to;
                if (e.flow >= e.cap) continue;
                int next_dist = dist + e.cost + potentials_[cur] - potentials_[next];
                if (next_dist < dists[next]) {
                    path_[next] = {cur, i};
                    flow[next] = min(flow[cur], e.cap - e.flow);
                    dists[next] = next_dist;
                    q.push({next_dist, next});
                }
            }
        }

        if (dists[t] == INT_MAX) {
            return -1;
        }
        for (int i = 0; i < n_; i++) {
            if (dists[i] < INT_MAX) potentials_[i] = dists[i];
        }
        return flow[t];

    }

    pair<int, int> MinCostFlow1(int s, int t) {
        int total_flow = 0;
        int total_cost = 0;
        int flow = Dijkstra(s, t);
        while (flow > 0) {
            total_flow += flow;
            int cur = t;
            while (cur != s) {
            edge& e = graph_[path_[cur].first][path_[cur].second];
            total_cost += e.cost * flow;
            e.flow += flow;
            graph_[cur][e.rev].flow -= flow;
            cur = path_[cur].first;
            }
            flow = Dijkstra(s, t);
        }
        return {total_flow, total_cost};
    }

    pair<int, int> MinCostFlow2(int s, int t) {
        int total_cost = 0;
        int total_flow = 0;
        while (SPFA(s, t) < INT_MAX) {
            int cur = t;
            int flow = INT_MAX;
            while (cur != s) {
                edge& e = graph_[path_[cur].first][path_[cur].second];
                flow = min(e.cap - e.flow, flow);
                cur = path_[cur].first;
            }

            cur = t;
            while (cur != s) {
                edge& e = graph_[path_[cur].first][path_[cur].second];
                e.flow += flow;
                total_cost += e.cost * flow;
                total_flow += flow;
                edge& e2 = graph_[cur][e.rev];
                e2.flow -= flow;
                cur = path_[cur].first;
            }
        }
        return {total_flow, total_cost};
    }
};


int main() {
    
}