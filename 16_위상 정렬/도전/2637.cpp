// 장난감 조립
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

void topologicalSort(int n, vector<int> &indegree, vector<int> &outdegree, vector<vector<ci>> &graph){
    queue<int> q;
    vector<int> dp(n+1, 0); // 부품별 필요한 개수 저장
    
    dp[n] = 1;
    q.push(n); // 최종 부품 넣기
    
    while (!q.empty()){
        int node = q.front();
        q.pop();
        
        for (int i = 0; i < graph[node].size(); i++){
            int mid = graph[node][i].first; // node를 구성하는 중간부품
            int cnt = graph[node][i].second; // 중간 부품 필요한 개수
            dp[mid] += dp[node]*cnt;
            outdegree[mid]--;
            if (!outdegree[mid]){ // 더이상 mid를 필요로 하는 부품이 없으면 (dp값에 변경이 없으면)
                q.push(mid);
            }
        }
    }
    
    for (int i = 1; i <= n; i++){
        if (!indegree[i]){
            cout << i << " " << dp[i] << '\n'; // 기본부품이면
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, x, y, k;
    cin >> n >> m;
    vector<vector<ci>> graph(n+1);
    vector<int> indegree(n+1, 0);
    vector<int> outdegree(n+1, 0);
    
    while (m--){
        cin >> x >> y >> k;
        graph[x].push_back({y, k}); // 부품x를 만들기 위해 부품y가 k개 필요
        indegree[x]++; // 기본부품인지 판별 여부
        outdegree[y]++; // y를 필요로 하는 부품 종류수
    }
    
    topologicalSort(n, indegree, outdegree, graph);
    return 0;
}