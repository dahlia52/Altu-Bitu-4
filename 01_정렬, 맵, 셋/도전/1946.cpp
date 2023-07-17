// 신입 사원
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;

// 각 부문별 1등은 무조건 합격

int countWorker(vector<pi> &worker, int n){
    int cnt = 1; // 서류성적 1등 선발
    int highest_rank = worker[0].second; // 면접성적 최고등수
    for (int i = 1; i < n; i++){ // i등 지원자 선발여부 결정
        if (worker[i].second < highest_rank){ 
            highest_rank = worker[i].second; // 갱신
            cnt++; // 합격자 추가
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