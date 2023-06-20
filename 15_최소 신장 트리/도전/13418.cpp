// 학교 탐방하기 - Kruskal
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef tuple<int, int, int> tp;
vector<int> parent;

int findParent(int node){
    if (parent[node] < 0){
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

bool unionNode(int x, int y){
    int px = findParent(x);
    int py = findParent(y);
    
    if (px == py){
        return false;
    }
    if (parent[px] < parent[px]){
        parent[px] += parent[py];
        parent[py] = px;
    }
    else{
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

int kruskal(int v, vector<tp> &edge){
    int sum = 0, cnt = 0;
    
    for (auto[w, n1, n2] : edge){
        if (!unionNode(n1, n2)){
            continue;
        }
        sum += w;
        cnt++;
        
        if (cnt == (v-1)){
            return sum;
        }
    }
    return sum;
}

int main(){
    int n, m, a, b, c, e1, e2, c1;
    cin >> n >> m;
    vector<tp> edge;
    cin >> e1 >> e2 >> c1;
    
    while (m--){
        cin >> a >> b >> c;
        edge.push_back({1-c,a,b}); // 오르막길을 1, 내리막길을 0으로
    }
    // 초기화
    parent.assign(n+1, -1);
    unionNode(e1, e2); // 입구 연결
    
    sort(edge.begin(), edge.end());
    int min_way = pow(kruskal(n, edge)+(1-c1),2); // 최적 경로
    
    // 초기화
    parent.assign(n+1, -1);
    unionNode(e1, e2); // 입구 연결
    
    sort(edge.begin(), edge.end(), greater<>());
    int max_way = pow(kruskal(n, edge)+ (1-c1),2); // 최악 경로

    cout << max_way - min_way;
    return 0;
}