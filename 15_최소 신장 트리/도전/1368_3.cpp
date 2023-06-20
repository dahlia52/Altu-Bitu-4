// 물대기 - Kruskal
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;
typedef tuple<int, int, int> tp;
vector<int> parent;

int findParent(int x) {
    if (parent[x] < 0) { 
        return x;
    }
    return parent[x] = findParent(parent[x]); 
}

bool unionNodes(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px == py) {
        return false;
    }

    if (parent[px] < parent[py]) { 
        parent[px] += parent[py];
        parent[py] = px;
    } else {
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

int kruskal(int v, vector<tp> &edge){
    int sum = 0, cnt = 0;
    for (auto[w, n1, n2] : edge){
        if (!unionNodes(n1, n2)){
            continue;
        }
        sum += w;
        cnt++;
        
        if (cnt == v){
            return sum;
        }
    }
    return sum;
}

int main(){
    int n, c;
    cin >> n;
    parent.assign(n+1, -1);
    vector<tp> edge;
    
    for (int i = 0; i<n; i++){
        cin >> c;
        edge.push_back({c, i, n});
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<i; j++){
            cin >> c;
            edge.push_back({c, i, j});
        }
        for (int j = i; j<n; j++){
            cin >> c;
        }
    }
    sort(edge.begin(), edge.end());
    cout << kruskal(n, edge);
    return 0;
}