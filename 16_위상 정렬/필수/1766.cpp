// 문제집
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph){
    priority_queue<int, vector<int>, greater<>> q; // 가능하면 쉬운 문제부터 풀어야하므로 min heap 이용
    vector<int> result;
    
    for (int i = 1; i<=n; i++){
        if (!indegree[i]){
            q.push(i);
        }
    }
    while (!q.empty()){
        int node = q.top();
        q.pop();
        result.push_back(node);
        
        for (int i = 0; i < graph[node].size(); i++){
            int next_node = graph[node][i];
            indegree[next_node]--;
            
            if (!indegree[next_node]){
                q.push(next_node);
            }
        }
    }
    // 출력
    for (int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
}

int main(){
    int n, m, x, y;
    cin >> n >> m;
    vector<int> indegree(n+1, 0);
    vector<vector<int>> graph(n+1, vector<int>(0));
    
    while (m--){
       cin >> x >> y;
       graph[x].push_back(y);
       indegree[y]++;
    }
    topologicalSort(n, indegree, graph);
    return 0;
}