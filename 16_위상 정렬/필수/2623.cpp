// 음악프로그램
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph){
    queue<int> q;
    vector<int> result;
    
    for (int i = 1; i <= n; i++){
        if (!indegree[i]){
            q.push(i);
        }
    }
    
    while (!q.empty()){
        int node = q.front();
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
    if (result.size() < n){ // 사이클 발생 - 순서를 정할 수 없는 정점들은 진입차수가 0이 될 수 없어 result에 저장이 되지 않음
        cout << 0;
        return;
    }
    for (int i = 0; i < n; i++){
        cout << result[i] << '\n';
    }
}

int main(){
    int n, m, num, tmp, x;
    cin >> n >> m;
    vector<int> indegree(n+1, 0);
    vector<vector<int>> graph(n+1, vector<int>(0));
    while(m--){
        cin >> num;
        cin >> tmp;
        num--;
        while(num--){
            cin >> x;
            graph[tmp].push_back(x);
            indegree[x]++;
            tmp = x;
        }
    }
    topologicalSort(n, indegree, graph);
    return 0;
}