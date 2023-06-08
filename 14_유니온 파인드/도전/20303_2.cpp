// 할로윈의 양아치
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;
vector<ci> parent; // 첫번째 인자에는 parent, 두 번째 인자에는 속하는 아이들 수 저장

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

// dp - k명 미만으로 최대 뺏을 수 있는 사탕수 저장
int knapsack(int n, int k){
    vector<ci> s;
    // 부모 노드만 저장
    for (int i = 1; i<=n; i++){
        if (parent[i].first < 0){
            s.push_back({-parent[i].first, parent[i].second});
        }
    }
    vector<int> dp(k,0);
    for (int i = 0; i < s.size(); i++){
        for (int j = k-1; j >= s[i].first; j--){
            dp[j] = max(dp[j], dp[j-s[i].first] + s[i].second); // i번째 집합으로 (k-1)명을 채우는 방법의 수
        }
    }
    return dp[k-1];
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
    cout << knapsack(n, k);
    return 0;
}