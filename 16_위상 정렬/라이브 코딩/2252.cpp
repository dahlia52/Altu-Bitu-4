// 줄 세우기 - 위상정렬
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph){
    queue<int> q; // 진입차수가 0인 정점들을 관리하는 컨테이너
    vector<int> result;
    
    for (int i = 1; i <= n; i++){
        if (!indegree[i]){ // 진입차수가 0이면
            q.push(i);
        }
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        
        result.push_back(node); //현재 정점 순서결과 배열에 삽입
        for (int i = 0; i < graph[node].size(); i++){
            int next_node = graph[node][i];
            indegree[next_node]--;
            if (!indegree[next_node]){ // 연결된 정점의 진입차수가 0이 되면
                q.push(next_node);
            }
        }
    }
    return result;
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<int> indegree(n+1, 0); //각 정점의 진입차수
    vector<vector<int>> graph(n+1, vector<int>(0)); // 인접 리스트 그래프
    
    while (m--){
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    
    vector<int> result = topologicalSort(n, indegree, graph);
    
    for (int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    return 0;
}