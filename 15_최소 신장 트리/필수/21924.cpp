// 도시 건설 - Kruskal
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> tp;

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

void kruskal(int v, vector<tp> &edge, long long tot_sum){
    long long sum = 0; // 총 길이
    int cnt = 0; // 연결한 정점 수
    
    for (auto[w, n1, n2] : edge){
        if (!unionNodes(n1, n2)){
            continue;
        }
        sum += w;
        cnt++;
        if (cnt == v-1){
            cout << tot_sum - sum;
            return;
        }
    }
    cout << -1; // 모든 건물을 연결할 수 없는 경우
}

int main(){
    int n, m, a, b, c;
    long long tot_sum = 0;
    cin >> n >> m;
    parent.assign(n+1, -1);
    
    vector<tp> edge; // 도로 저장
    while (m--){
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
        tot_sum += c;
    }
    sort(edge.begin(), edge.end()); // dist 기준으로 정렬
    kruskal(n, edge, tot_sum);
    
    return 0;
}