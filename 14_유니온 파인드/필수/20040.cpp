// 사이클 게임
#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
int ans = 0;

int findParent(int node){
    if (parent[node] < 0){
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionParent(int x, int y, int i){
    int px = findParent(x);
    int py = findParent(y);
    
    if (px == py){
        if (ans == 0){ // 아직 사이클이 발생하지 않았다면
           ans = i; 
        }
        return;
    }
    if (px < py){ // px 집합이 더 크면
        parent[px] += parent[py];
        parent[py] = px;
    }
    else{
        parent[py] += parent[px];
        parent[px] = py;
    }
}


int main(){
    int n, m, a, b;
    cin >> n >> m;
    parent.assign(n,-1); // 점 n개의 부모 노드 저장 
    for (int i = 1; i<=m; i++){
        cin >> a >> b;
        unionParent(a,b,i);
    }
    cout << ans;
    return 0;
}