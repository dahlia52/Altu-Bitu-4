// 아기상어
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;

// 이동 방향
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

// 최적의 물고기 한 마리를 찾아 먹고 시간 계산
pair<int, ci> eatFish(int n, int shark_size, ci &pos, vector<vector<int>> &arr){
    priority_queue<pair<int, ci>, vector<pair<int, ci>>, greater<pair<int, ci>>> pq; // min heap
    queue<ci> q; // 좌표 (y,x)
    vector<vector<int>> dist(n, vector<int>(n,0)); // 이동한 거리를 0으로 초기화
    dist[pos.first][pos.second] = 1; //  살아남은 시간
    q.push(pos);
    while (!q.empty()){
        ci curr = q.front(); // 현재 위치
        q.pop();
        for (int i = 0; i < 4; i++){ // BFS
            ci next = {curr.first + dy[i], curr.second + dx[i]}; // 다음 위치
            if (next.first >=0 and next.first < n and next.second >=0 and next.second < n){
                // 이미 지나간 길이면 -> 지나갈 수 없음
                if (dist[next.first][next.second]){
                    continue;
                }
                // 자신보다 큰 물고기가 있다면 -> 지나갈 수 없음
                if (arr[next.first][next.second] > shark_size){
                    continue;
                }
                // 먹이 후보 물고기를 우선순위 큐에 push
                if (arr[next.first][next.second] and arr[next.first][next.second] < shark_size){
                    pq.push({dist[curr.first][curr.second], next});
                    continue;
                }
                dist[next.first][next.second] = dist[curr.first][curr.second] + 1; // 현재 이동 거리 + 1
                q.push(next);
            }
        }
    }
    if (pq.empty()){
        return {-1, {-1, -1}};
    }
    arr[pq.top().second.first][pq.top().second.second] = 0; // 조건에 맞는 물고기 먹기
    return pq.top(); // 살아남은 시간, 상어의 좌표를 리턴
}

void survive(int n, ci &pos, vector<vector<int>> &arr){
    int shark_size = 2, cnt = 0, ans = 0;
    arr[pos.first][pos.second] = 0;
    while (true){
        pair<int, ci> target_fish = eatFish(n, shark_size, pos, arr);
        if (target_fish.first == -1){ // 엄마 상어에게 도움 요청
            break;
        }
        cnt++; // 물고기 먹기
        ans += target_fish.first; // 시간 증가
        if (cnt == shark_size){ // 상어의 크기와 같은 수의 물고기를 먹음
            cnt = 0;
            shark_size++; // 상어 크기 키우기
        }
        pos = target_fish.second; // 상어 위치 이동
    }
    cout << ans;
}

int main(){
    int n;
    ci pos;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n,0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 9){
                pos = {i, j}; // 아기 상어의 위치
            }
        }
    }
    survive(n, pos, arr);
    return 0;
}