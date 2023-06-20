// 학교 탐방하기 - Prim
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e3+1;

int min_prim(int n, int start, vector<vector<ci>> &edge){
    int sum = 0;
    vector<int> visited(n+1, false);
    vector<int> dist(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    // 초기화
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()){
        auto[curr_w, curr] = pq.top();
        pq.pop();
        
        if (visited[curr]){ // 이미 방문한 정점이면
            continue;
        }
        sum += curr_w;
        visited[curr] = true;
        
        for (auto[next_w, next] : edge[curr]){
            if (!visited[next] and next_w < dist[next]){
                dist[next] = next_w;
                pq.push({next_w, next});
            }
        }
    }
    return sum;
}

int max_prim(int n, int start, vector<vector<ci>> &edge){
    int sum = 0;
    vector<int> visited(n+1, false);
    vector<int> dist(n+1, -INF);
    priority_queue<ci, vector<ci>> pq;

    // 초기화
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()){
        auto[curr_w, curr] = pq.top();
        pq.pop();
        
        if (visited[curr]){ // 이미 방문한 정점이면
            continue;
        }
        sum += curr_w;
        visited[curr] = true;
        
        for (auto[next_w, next] : edge[curr]){
            if (!visited[next] and next_w > dist[next]){ // next_w가 dist에 저장된 값보다 더 크면 update
                dist[next] = next_w;
                pq.push({next_w, next});
            }
        }
    }
    return sum;
}

int main(){
    int n, m, a, b, c, e1, e2, c1;
    cin >> n >> m;
    vector<vector<ci>> edge(n+1, vector<ci>(0));
    cin >> e1 >> e2 >> c1;
    
    while (m--){
        cin >> a >> b >> c;
        edge[a].push_back({1-c, b}); // 오르막길을 1, 내리막길을 0으로
        edge[b].push_back({1-c, a});
    }
    
    int min_way = pow(min_prim(n, e2, edge)+(1-c1), 2); // 최적 경로
    int max_way = pow(max_prim(n, e2, edge)+ (1-c1), 2); // 최악 경로

    cout << max_way - min_way;
    return 0;
}