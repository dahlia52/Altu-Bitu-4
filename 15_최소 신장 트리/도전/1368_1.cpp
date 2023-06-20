// 물대기 - Prim
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5+1;

void prim(int n, int start, vector<vector<ci>> &edge, vector<int> &cost){
    int sum = 0;
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;
    
    // 초기화
    pq.push({0, start});
    
    while (!pq.empty()){
        auto[curr_w, curr] = pq.top();
        pq.pop();
        
        if (visited[curr]){
            continue;
        }
        visited[curr] = true;
        sum += curr_w;
        
        for (auto[next_w, next] : edge[curr]){
            if (!visited[next] and next_w < dist[next]){
                pq.push({next_w, next});
                dist[next] = next_w;
            }
        }
    }
    cout << sum;
}

int main(){
    int n, c;
    cin >> n;
    vector<int> cost(n+1, 0); // 논에 우물을 팔 때 드는 비용
    vector<vector<ci>> edge(n+1, vector<ci>(0)); // 우물 연결 비용
    
    // n번째: 우물
    for (int i = 0; i < n; i++){
        cin >> c;
        edge[n].push_back({c, i});
        edge[i].push_back({c, n});
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            cin >> c;
            edge[i].push_back({c, j});
            edge[j].push_back({c, i});
        }
        for (int j = i; j<n; j++){
            cin >> c;
        }
    }
    // 우물은 적어도 한번 지나야하므로 우물에서 start
    prim(n, n, edge, cost);
    return 0;
}