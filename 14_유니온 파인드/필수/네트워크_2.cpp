#include <string>
#include <vector>
#include <queue>
using namespace std;

void DFS(int start, int n, vector<bool> &visited, vector<vector<int>> computers){
    visited[start] = true;
    for (int i = 0; i < n; i++){
        if (computers[start][i] == 1 and !visited[i]){
            DFS(i, n, visited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            DFS(i, n, visited, computers);
            answer++;
        }
    }
    return answer;
}