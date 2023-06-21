// ACM Craft
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 위상정렬 + DP(동적계획법) 이용
int topologicalSort(int n, int w, vector<int> &delay, vector<int> &indegree, vector<vector<int>> &graph){
    queue<int> q;
    vector<int> dp(n+1, 0); // 현재 건물을 짓기까지 걸리는 최소 시간
    
    for (int i = 1; i<=n; i++){
        dp[i] = delay[i]; // dp배열 초기화
        if (!indegree[i]){
            q.push(i);
        }
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        
        for (int i = 0; i < graph[node].size(); i++){
            int next_node = graph[node][i];
            indegree[next_node]--;
            
            // 다음 정점의 최소 시간 계산 -> 현재 정점 node 중 가장 긴 시간의 건물을 선택
            dp[next_node] = max(dp[next_node], dp[node] + delay[next_node]);
            
            if (indegree[next_node]){
                continue;
            }
            // 연결된 정점의 진입차수가 0이 되었다면
            if (next_node == w){ // w와 연결된 전 정점이 더 이상 없음
                return dp[w];
            }
            q.push(next_node);
        }
    }
    return dp[w];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t, n, k, x, y, w;
    cin >> t;
    
    while (t--){
        cin >> n >> k;
        vector<int> indegree(n+1, 0); // 진입차수
        vector<vector<int>> graph(n+1, vector<int>(0)); // 인접 리스트
        vector<int> delay(n+1, 0); // 각 건물마다 건설에 걸리는 시간
        for (int i = 1; i <= n; i++){
            cin >> delay[i];
        }
        while (k--){
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }
        cin >> w; // 승리하기 위해 건설해야 할 건물의 번호
        cout << topologicalSort(n, w, delay, indegree, graph) << '\n';
    }
    
    return 0;
}