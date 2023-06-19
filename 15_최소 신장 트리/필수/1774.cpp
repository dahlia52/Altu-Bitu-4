// 우주신과의 교감 
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;
typedef tuple<double, int, int> tp;
typedef pair<double, double> ci;

vector<int> parent;

int findParent(int node){
    if (parent[node] < 0){
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

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
    else {
		parent[py] += parent[px];
		parent[px] = py;
	}
	return true;
}

double kruskal(int v, vector<tp> &edge){
    double sum = 0;
    int cnt = 0;
    
    for (auto[w, n1, n2] : edge){
        if (!unionNodes(n1, n2)){ // 사이클이 생기는 경우
            continue;
        }
        sum += w;
        cnt++;
        if (cnt == v-1){
        return sum;
        }
    }
    return sum;
}

int main(){
    // 입력
    int n, m, x, y, v = 0; // 연결된 정점 수
    cin >> n >> m;
    vector<ci> spaceGod(n+1);
    parent.assign(n+1, -1); // parent 벡터 초기화
    
    for (int i = 1; i <= n; i++){
        cin >> spaceGod[i].first >> spaceGod[i].second;
    }
    
    // 우주신 사이의 거리 계산
    vector<tp> edge;
    
    for (int i = 1; i<=n; i++){
        for (int j = 1; j < i; j++){
            double dx = spaceGod[i].first - spaceGod[j].first;
            double dy = spaceGod[i].second - spaceGod[j].second;
            double dist = sqrt(dx*dx + dy*dy);
            edge.push_back({dist, i, j});
        }
    }
    
    // 이미 연결된 통로를 추가
    while (m--){
        cin >> x >> y;
        if (unionNodes(x,y)){
            v++;
        }
    }
    sort(edge.begin(), edge.end()); // dist 기준으로 정렬
    
    cout << fixed;
    cout.precision(2);
    cout << kruskal(n-v, edge);

    return 0;
}