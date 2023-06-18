// 별자리 만들기 - Prim 
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

typedef pair<double, int> ci;
const int INF = 1e5;

double prim(int n, int start, vector<vector<ci>> &graph){
    double sum = 0; // 간선 비용의 합
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<bool> visited(n, false); // 정점 방문 여부
    vector<double> dist(n, INF); // 각 정점에서 선택한 간선의 가중치
    
    // 초기화
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()){
        auto[curr_w, curr] = pq.top();
        pq.pop();
        
        if (visited[curr]){ // 이미 방문한 정점이라면
            continue;
        }
        visited[curr] = true;
        sum += curr_w; // MST 간선 가중치 총합에 더해줌
        
        for (auto[next_w, next]: graph[curr]){
            // 미방문 정점이면서 & 현재 기록된 간선보다 작은 가중치가 나왔을 경우
            if (!visited[next] && next_w < dist[next]){
                pq.push({next_w, next});
                dist[next] = next_w;
            }
        }
    }
    return sum;
}

int main(){
    int n;
    double x, y;
    cin >> n;
    
    vector<pair<double, double>> star; // 별들의 위치 정보 저장
    vector<vector<ci>> graph(n, vector<ci>(0));
    
    for (int i = 0; i < n; i++){
        cin >> x >> y;    
        for (int j = 0; j < i; j++){
            // 임의의 두 별에 대한 거리(간선) 모두 구하기
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            double dist = sqrt(dx*dx + dy*dy);
            graph[i].push_back({dist, j});
            graph[j].push_back({dist, i});
        }
        star.push_back({x,y});
    }
    cout << fixed; // 고정 소수점 출력 방식 선택
    cout.precision(2);
    cout << prim(n, 0, graph);
    
    return 0;
}