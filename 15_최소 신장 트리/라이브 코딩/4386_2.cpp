// 별자리 만들기 - Kruskal
#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> parent;

typedef tuple<double, int, int> tp;
const int INF = 1e5;

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

double kruskal(int n, vector<tp> &edge){
    double sum = 0;
    int cnt = 0;
    
    for (auto[w, n1, n2]: edge){
        if (!unionNodes(n1, n2)){ // 사이클이 생기는 경우
            continue;
        }
        sum += w;
        cnt++;
        
        if (cnt == n-1){
            return sum;
        }
    }
    // MST를 못 만든 경우
    return sum;
}

int main(){
    int n;
    double x, y;
    cin >> n;
    parent.assign(n, -1); // parent벡터 초기화
    
    vector<pair<double, double>> star; // 별들의 위치 정보 저장
    vector<tp> edge; // 별들 간 거리 저장
    
    for (int i = 0; i < n; i++){
        cin >> x >> y;    
        for (int j = 0; j < i; j++){
            // 임의의 두 별에 대한 거리(간선) 모두 구하기
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            double dist = sqrt(dx*dx + dy*dy);
            edge.push_back({dist, i, j});
        }
        star.push_back({x, y});
    }
    sort(edge.begin(), edge.end());
    
    // 출력
    cout << fixed; // 고정 소수점 출력 방식 선택
    cout.precision(2);
    cout << kruskal(n, edge);
    
    return 0;
}