// 최소 스패닝 트리 - Prim
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
const int INF = 1e6 + 1;

int prim(int n, int start, vector<vector<pi>> &graph){
    int sum = 0; // 간선 비용의 합
    priority_queue<pi, vector<pi>, greater<>> pq;
    vector<bool> visited(n+1, false); // 정점 방문 여부
    vector<int> dist(n+1, INF);
    
    // 초기화
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()){
        auto[curr_w, curr] = pq.top();
        pq.pop();
        
        if (visited[curr]){
            continue;
        }
        visited[curr] = true;
        sum += curr_w;
        
        for (auto[next_w, next]:graph[curr]){
            if (!visited[next] && next_w < dist[next]){
                pq.push({next_w, next});
                dist[next] = next_w;
            }
        }
    }
    return sum;
}

int main(){
    int v, e, a, b, c;
    cin >> v >> e;
    
    vector<vector<pi>> graph(v+1, vector<pi> (0));
    
    while (e--){
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    
    cout << prim(v, 1, graph);
    return 0;
}