// 쿠키런 킹덤
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void topologicalSort(int n, int m, int t, vector<int> &indegree, vector<vector<int>> &graph, vector<vector<int>> &building){
    queue<pair<int, int>> q; // 건물, 시간
    vector<bool> check(n+1, false); // 현황
    vector<int> result;
    
    for (int i = 1; i <=n; i++){
        if (!indegree[i]){ // 이미 지어진 건물
            q.push({i, 0});
        }
    }
    while (!q.empty()){
        int node = q.front().first;
        int curr_t = q.front().second;
        q.pop();
        
        if (curr_t > t){
            break;
        }
        result.push_back(node);
        
        for (int i = 0; i < building[node].size(); i++){
            int b = building[node][i]; // 건물이 생산한 자원
            if (check[b]){
                continue;
            }
            check[b] = true;
            for (int j = 0; j < graph[b].size(); j++){
                indegree[graph[b][j]]--;
                
                if (!indegree[graph[b][j]]){
                    q.push({graph[b][j], curr_t + 1});
                }
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, t, x, num, a;
    cin >> n >> m >> t;
    
    vector<int> indegree(n+1, 0); // 각 건물마다 필요한 자원수
    vector<vector<int>> graph(n+1, vector<int>(0)); // 각 자원이 필요한 건물목록
    vector<vector<int>> building(n+1, vector<int>(0)); // 각 건물이 생산하는 자원목록
    
    for (int i = 0; i < m; i++){
        cin >> x;
    }
    for (int i = 1; i<=n; i++){
        cin >> num;
        while (num--){
            cin >> x;
            building[i].push_back(x); // i번 건물에서 생산할 수 있는 자원
        }
    }
    for (int i = 0; i < n-m; i++){
        cin >> x >> num;
        indegree[x] = num; // x번 건물을 짓는데 필요한 자원수
        while (num--){
            cin >> a;
            graph[a].push_back(x); // 자원a가 필요한 건물 목록 저장
        }
    }
    topologicalSort(n, m, t, indegree, graph, building);
    return 0;
}