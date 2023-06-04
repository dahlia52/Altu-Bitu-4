// 친구비
#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;

int findParent(int node){
    if (parent[node] < 0){
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionFriend(int v, int w, vector<int> &friends){
    int px = findParent(v);
    int py = findParent(w);
    
    if (px == py){ // 이미 서로 친구이면
        return;
    }
    parent[py] = px;
    friends[px] = min(friends[px], friends[py]);
}

void calCost(int n, int k, vector<int> &friends){
    int cost = 0;
    for (int i = 1; i<=n; i++){
        if (parent[i] == -1){
            cost += friends[i];
        }
    }
    (cost > k)? cout << "Oh no" : cout << cost;
}

int main(){
    int n, m, k, v, w;
    cin >> n >> m >> k;
    parent.assign(n+1, -1);
    vector<int> friends(n+1, 0);
    
    for (int i = 1; i<=n; i++){
        cin >> friends[i];
    }
    while (m--){
        cin >> v >> w;
        unionFriend(v, w, friends);
    }
    calCost(n, k, friends);
    return 0;
}