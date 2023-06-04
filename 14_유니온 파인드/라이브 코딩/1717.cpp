// 집합의 표현
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int findParent(int node){
    if (parent[node] < 0){ // 루트 노드이면 반환
        return node;
    }
    return parent[node] = findParent(parent[node]); // 그래프 압축하며 루트 정점 찾기
}

void unionSet(int x, int y){
    int xp = findParent(x); // x의 집합의 대표 노드 저장
    int yp = findParent(y); // y의 집합의 대표 노드 저장
    
    if (xp == yp){ // 이미 같은 집합에 있는 경우
        return;
    }
    if (parent[xp] < parent[yp]){ // xp의 집합이 더 크면
        parent[xp] += parent[yp];
        parent[yp] = xp; // yp의 부모 노드 변경
    }
    else{ // yp의 집합이 더 크면
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

void isSame(int a, int b){
    if (findParent(a) == findParent(b)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, c, a, b;
    cin >> n >> m;
    parent.assign(n+1,-1);
    
    while (m--){
        cin >> c >> a >> b;
        if (!c){ // c = 0이면
            unionSet(a,b);
        }
        else{ // c = 1이면
            isSame(a,b);
        }
    }
    return 0;
}