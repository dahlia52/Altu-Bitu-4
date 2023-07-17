// 신입 사원 - 시간 초과
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;

// 각 부문별 1등은 무조건 합격

int countWorker(vector<pi> &worker, int n){
    int cnt = 1; // 서류성적 1등 선발
    for (int i = 1; i<n; i++){ // i등 선발여부 결정
        bool flag = true; // 선발여부
        for (int j = 0; j < i; j++){
            if (worker[i].second > worker[j].second){
                flag = false;
                break;
            }
        }
        if (flag){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        vector<pi> worker(n,{0,0});
        for (int i = 0; i < n; i++){
            cin >> worker[i].first >> worker[i].second;
        }
        sort(worker.begin(), worker.end()); // 서류성적이 높은 순으로 정렬
        cout << countWorker(worker, n) << '\n';
    }

    return 0;
}