// 트리
#include <iostream>
#include <vector>
using namespace std;

void isTree(int i, int n, vector<int> &parent){
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

int findParent(int node, vector<int> &parent){
    if (parent[node] <= 0){
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

int unionTree(int x, int y, int n, vector<int> &parent){
    int px = findParent(x, parent); // 부모 노드 찾기
    int py = findParent(y, parent);
    
    if (px == py){ // 부모 노드가 같으면
        if (parent[px] != 0){ // 사이클이 아직 없으면
            parent[px] = 0; // 사이클 발생
            n--; // 트리 제외
        }
        return n;
    }
    if (!parent[px] or !parent[py]){ // 합치는 집합에 사이클이 있다면
        if (parent[px] ^ parent[py]){ // 둘 중 하나만 사이클이면
            n--;
        }
        parent[px] = 0, parent[py] = 0;
        return n;
    }
    if (parent[px] < parent[py]){ // px집합이 더 크면
        parent[px] += parent[py];
        parent[py] = px;
        n--;
    }
    else{ // py집합이 더 크면
        parent[py] += parent[px];
        parent[px] = py;
        n--;
    }
    return n;
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
        vector<int> parent(n+1,-1);
        while (m--){
            cin >> a >> b;
            n = unionTree(a,b,n,parent);
        }
        isTree(i++, n, parent);
    }
    return 0;
}