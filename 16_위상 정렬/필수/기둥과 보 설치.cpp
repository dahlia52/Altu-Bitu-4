#include <string>
#include <vector>

using namespace std;

// 미설치 - 0, 기둥 - 1, 보 - 2, 둘다 - 3 
// 2로 나누었을 때 나머지가 1이면 기둥 설치O, 2이상이면 보 설치O
// 설치 가능 조건 판별
bool isPossible(int x, int y, int a, int n, vector<vector<int>> &picture){
    if (a %2 == 1){ // 기둥을 설치하는 경우
        if (y == 0 or (picture[x][y-1] % 2) == 1 or (x>=1 and picture[x-1][y] >= 2) or picture[x][y] >= 2){
            return true;
        }
    }
    else if (a>=2){ // 보를 설치하는 경우
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
    int dx[] = {1,0,-1,-1,1};
    int dy[] = {0,1,0,1,1};
    
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
            picture[x][y] -= a;
            for (int i = 0; i < 4; i++){ // 주변
                if (x + dx[i]<0 or y+dy[i] < 0 or x+dx[i] > n or y+dy[i] > n){ // 사각형을 벗어나면
                    continue;
                }
                if (picture[x+dx[i]][y+dy[i]] >0 and !isPossible(x+dx[i], y+dy[i], picture[x+dx[i]][y+dy[i]], n, picture)){ // 주변의 기둥, 보가 설치가 안된다면
                    picture[x][y] += a;
                    break;
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