// 웜홀
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e5;

struct Bus{
    int from;
    int to;
    int w;
};

void bellmanFord(int start, int n, vector<Bus> &ways){
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    
    // n-1회 실행 - 각 간선은 최대 n-1개의 정점에 의해 업데이트될 수 있음
    for (int i = 1; i<=n-1; i++){
        for (auto [from, to, w] : ways){
            if (dist[to] > dist[from] + w){
                dist[to] = dist[from] + w; // 갱신
            }
        }
    }
    // 1회 실행
    for (auto [from, to, w] : ways){
        if (dist[to] > dist[from] + w){ // 이후에도 계속 갱신된다면
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc, n, m , w, s, e, t;
    cin >> tc;
    
    while (tc--){
        cin >> n >> m >> w;
        vector<Bus> ways(m+w);
        
        // 도로의 정보
        for (int i = 0; i<=m-1; i++){
            cin >> s >> e >> t;
            ways.push_back({s,e,t});
            ways.push_back({e,s,t}); // 도로는 방향이 없음
        }
        // 웜홀의 정보
        for (int i = m; i<=m+w-1; i++){
            cin >> s >> e >> t; 
            ways.push_back({s, e, -t});
        }
        bellmanFord(0, n, ways);
    }
    return 0;
}