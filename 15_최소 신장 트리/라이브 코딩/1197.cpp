// 최소 스패닝 트리 - Kruskal

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> tp;
vector<int> parent;

// Find 연산
int findParent(int node){
    if (parent[node] < 0){
        return node;
    } 
    return parent[node] = findParent(parent[node]);
}

// union 연산
bool unionNodes(int x, int y){
    int px = findParent(x);
    int py = findParent(y);
    
    if (px == py){
        return false;
    }
    if (parent[px] < parent[py]){
        parent[px] += parent[py];
        parent[py] = px;
    }
    else{
        parent[py] += parent[px];
        parent[px] = py; 
    }
    return true;
}

int kruskal(int v, vector<tp> &edges){
    int sum = 0, cnt = 0;
    
    for (auto[w, n1, n2]: edges){
        if (!unionNodes(n1, n2)){ // 사이클이 생기는 경우
            continue;
        }
        sum += w;
        cnt++;
        
        if (cnt == v-1){ // v-1 개의 간선을 선정하면 stop
            return sum;
        }
    }
    return 0; // MST 못 만든 경우
}

int main(){
    int v, e, a, b, c;
    cin >> v >> e;
    
    vector<tp> edges; // 간선 정보 저장
    parent.assign(v+1, -1); // parent 배열 초기화
    
    while (e--){
        cin >> a >> b >> c;
        edges.push_back({c,a,b}); 
    }
    sort (edges.begin(), edges.end()); // c를 기준으로 정렬
    cout << kruskal(v, edges);
    return 0;
}