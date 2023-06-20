// 도시 건설 - Prim
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e6 + 1;

void prim(long long tot_sum, int n, int start, vector<vector<ci>> &edge){
    long long sum = 0;
    int cnt = 0;
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<bool> visited(n+1, false);
    vector<long long> dist(n+1, INF);
    
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
        cnt++;
        
        for (auto[next_w, next] : edge[curr]){
            if (!visited[next] and next_w < dist[next]){
                pq.push({next_w, next});
                dist[next] = next_w;
            }
        }
    }
    if (cnt != n){
        cout << -1;
        return;
    }
    cout << tot_sum - sum;
}

int main(){
    int n, m, a, b, c;
    long long tot_sum = 0;
    cin >> n >> m;
    vector<vector<ci>> edge(n+1, vector<ci>(0)); // 도로 저장
    
    while(m--){
        cin >> a >> b >> c;
        edge[a].push_back({c, b});
        edge[b].push_back({c, a});
        tot_sum +=c;
    }
    prim(tot_sum, n, 1, edge);
    
    return 0;
}