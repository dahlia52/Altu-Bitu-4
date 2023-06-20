// 물대기 - Prim
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5+1;

void prim(int n, int start, vector<vector<int>> &edge){
    int sum = 0;
    vector<bool> visited(n, false);
    vector<int> dist(n, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;
    
    // 초기화
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()){
        auto[curr_w, curr] = pq.top();
        pq.pop();
        
        if (visited[curr]){
            continue;
        }
        visited[curr] = true;
        sum += curr_w;
        
        for (int i = 0; i < n; i++){
            if (!visited[i] and edge[curr][i] < dist[i]){
                pq.push({edge[curr][i], i});
                dist[i] = edge[curr][i];
            }
        }
    }
    cout << sum;
}

int main(){
    int n, c;
    cin >> n;
    vector<vector<int>> edge(n+1, vector<int>(n+1, 0)); 
    
    for (int i = 0; i < n; i++){
        cin >> edge[i][n];
        edge[n][i] = edge[i][n];
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> edge[i][j];
        }
    }
    prim(n+1, n, edge);
    return 0;
}