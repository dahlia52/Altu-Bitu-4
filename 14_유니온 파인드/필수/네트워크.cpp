#include <string>
#include <vector>

using namespace std;
vector<int> parent;

int findParent(int node){
    if (parent[node] < 0){
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionNetwork(int x, int y){
    int px = findParent(x);
    int py = findParent(y);
    if (px == py){
        return;
    }
    if (parent[px] < parent[py]){
        parent[px] += parent[py];
        parent[py] = px;
    }
    else{
        parent[py] += parent[px];
        parent[px] = py;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    parent.assign(n+1,-1);
    // i와 j가 연결되면 합치기
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (computers[i][j] == 1){
                unionNetwork(i+1, j+1);
            }
        }    
    }
    // 서로 다른 네트워크 수 세기
    for (int i = 1; i<=n; i++){
        if (parent[i] < 0){
            answer++;
        }
    }
    return answer;
}