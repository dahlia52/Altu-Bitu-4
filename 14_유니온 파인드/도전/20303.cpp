// 할로윈의 양아치 - 시간 초과
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ci;
vector<ci> parent; // 첫번째 인자에는 parent, 두 번째 인자에는 속하는 아이들 수 저장
int max_cnt = 0; // 최대 뺏을 수 있는 사탕수

// 부모 노드 찾기
int findParent(int node){
    if (parent[node].first < 0){
        return node;
    }
    return parent[node].first = findParent(parent[node].first);
}
// x와 y 친구 만들기
void makeFriend(int x, int y){
    int px = findParent(x); // 부모(대표) 노드 찾기
    int py = findParent(y);
    
    if (px == py){ // 이미 친구이면
        return; 
    }
    if (parent[px].first < parent[py].first){
        parent[px].first += parent[py].first; // 사탕을 대표에게 합치기
        parent[py].first = px; // px와 py 연결
        parent[px].second += parent[py].second; // 인원 합치기
    }
    else{
        parent[py].first += parent[px].first;
        parent[px].first = py;
        parent[py].second += parent[px].second;
    }
}

// 백트랙킹 - 최대 뺏을 수 있는 사탕수 계산
void dfs(int cur_cnt, int child_cnt, int cur_node, int n, int k, vector<bool> &visited){
    // 종료 조건
    if (child_cnt - parent[cur_node].first >= k){ // 인원이 k명이 넘어가면
        return;
    }
    child_cnt -= parent[cur_node].first; // 인원수 추가
    cur_cnt += parent[cur_node].second; // 사탕 추가
    visited[cur_node] = true; // 현재 노드 방문
    max_cnt = max(max_cnt, cur_cnt); // 최대 사탕 수 갱신
    
    for (int next_node = 1; next_node <= n; next_node++){ // 다음 노드 선정
        if (!visited[next_node] and parent[next_node].first < 0){ // 아직 방문하지 않았고 부모 노드에 해당하면
            dfs(cur_cnt, child_cnt, next_node, n, k, visited);
        }
    }
    // 원상태로 되돌리기
    child_cnt += parent[cur_node].first;
    cur_cnt -= parent[cur_node].second;
    visited[cur_node] = false;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, a, b;
    cin >> n >> m >> k;
    parent.assign(n+1, {-1,0});
    vector<bool> visited(n+1,false);
    
    for (int i = 1; i <= n; i++){
        cin >> parent[i].second;
    }
    while (m--){
        cin >> a >> b;
        makeFriend(a,b);
    }
    parent[0].first = 0;
    dfs(0, 0, 0, n, k, visited);
    cout << max_cnt;
    return 0;
}