// 트리
#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
vector<bool> cycle;

int findParent(int node){
    if (parent[node] <= 0){
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionTree(int x, int y, int n){
    int px = findParent(x); // 부모 노드 찾기
    int py = findParent(y);
    
    if (px == py){ // 부모 노드가 같으면
        cycle[px] = true; // 사이클 발생
        return;
    }
    if (cycle[px] or cycle[py]){ // 사이클이 합쳐지면
        cycle[px] = cycle[py] = true;
    }
    if (parent[px] < parent[py]){ // px집합이 더 크면
        parent[px] += parent[py];
        parent[py] = px;
    }
    else{ // py집합이 더 크면
        parent[py] += parent[px];
        parent[px] = py;
    }
}

void isTree(int i, int n){
    cout << "Case " << i << ": ";
    if (!n){
        cout << "No trees.\n";
    }  
    else if (n == 1){
        cout << "There is one tree.\n";
    }
    else{
        cout << "A forest of " << n << " trees.\n";
    }
}

void countTree(int i){
    int cnt = 0;
    for (int i = 1; i<=parent.size(); i++){
        if (parent[i] < 0 and !cycle[i]){ // 루트 노드이고 사이클이 없으면
            cnt++;
        }
    }
    isTree(i, cnt);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b, i = 1;
    while (true){
        cin >> n >> m;
        if (n == 0 and m == 0){
            break;
        }
        parent.assign(n+1,-1);
        cycle.assign(n+1, false);
        while (m--){
            cin >> a >> b;
            unionTree(a,b,n);
        }
        countTree(i++);
    }
    return 0;
}