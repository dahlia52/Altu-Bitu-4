// 줄 세우기 - DFS
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
stack<int> st; // 위상정렬 순서가 역순으로 들어감

void dfs(int node){
    if (visited[node]){ // 이미 방문한 정점이면
        return;
    }
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++){
        dfs(graph[node][i]);
    }
    st.push(node); // 더이상 탐색할 정점이 없으면 현재 정점 삽입
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<int> indegree(n+1, 0); //각 정점의 진입차수
    graph.assign(n+1, vector<int>(0));
    visited.assign(n+1, false);
    
    while (m--){
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    
    // 연산
    for (int i = 1; i <=n; i++){
        if (!indegree[i]){
            dfs(i);
        }
    }
    
    // 출력
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}