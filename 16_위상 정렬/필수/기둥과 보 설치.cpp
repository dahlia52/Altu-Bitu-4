#include <string>
#include <vector>
using namespace std;

// 미설치 - 0, 기둥 - 1, 보 - 2, 둘다 - 3
// 설치 가능 조건 판별
bool isPossible(int x, int y, int a, int n, vector<vector<int>> &picture){
    if (a == 1){ // 기둥을 설치하는 경우
        if (y == 0 or (picture[x][y-1] % 2) == 1 or (x>=1 and picture[x-1][y] >= 2) or picture[x][y] >= 2){
            return true;
        }
    }
    if (a >= 2){ // 보를 설치하는 경우, 기둥과 보를 모두 설치하는 경우 => 보만 설치 가능하다면 기둥은 무조건 설치 가능
        if ((y>=1 and (picture[x][y-1] % 2) == 1) or (y>=1 and (picture[x+1][y-1] % 2) == 1) or (x>=1 and picture[x-1][y] >= 2 and picture[x+1][y] >= 2)){
            return true;
        }
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<int>> picture(n+1, vector<int>(n+1, 0));
    int x, y, a, b;
    int dx[] = {0,1,-1,0,0,1,-1}; // 이웃한 블록 탐색 방향
    int dy[] = {0,0,0,1,-1,-1,1};
    
    for (int i = 0; i < build_frame.size(); i++){
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2] + 1;
        b = build_frame[i][3];
        
        if (b == 1){ // 설치하면
            if (isPossible(x, y, a, n, picture)){
            picture[x][y] += a;
            }
        }
        else{ // 삭제하면
            picture[x][y] -= a; // 일단 제거
            for (int i = 0; i < 7; i++){ // 주변의 블록들이 설치가능한지 확인
                if (x + dx[i]<0 or y+dy[i] < 0 or x+dx[i] > n or y+dy[i] > n){ // 사각형을 벗어나면
                    continue;
                }
                if (picture[x+dx[i]][y+dy[i]] >0){ // 주변에 블록이 있을 때
                    int tmp = picture[x+dx[i]][y+dy[i]]; // 주변의 블록에 현재 설치된 목록
                    picture[x+dx[i]][y+dy[i]] -= tmp;
                    if (isPossible(x+dx[i], y+dy[i], tmp, n, picture)){ // 주변의 기둥, 보가 설치가능하면
                        picture[x+dx[i]][y+dy[i]] += tmp;
                        continue;
                    }
                    else{ // 설치 불가하다면
                        picture[x+dx[i]][y+dy[i]] += tmp;
                        picture[x][y] += a;
                        break;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i<=n; i++){
        for (int j = 0; j<=n; j++){
            if (picture[i][j] == 3){
                answer.push_back({i, j, 0});
                answer.push_back({i, j, 1});
            }
            else if (picture[i][j] > 0){
                answer.push_back({i, j, picture[i][j]-1});
            }
        }
    }
    return answer;
}