// 요세푸스 문제
#include <iostream>
#include <queue>
using namespace std;

void josephus(int n, int k){
    queue<int> q;
    
    for (int i = 1; i<=n; i++){
        q.push(i); // 원 초기화
    }
    cout << "<";
    while (!q.empty()){
        for (int i = 0; i < k-1; i++){ // k-1번 pop & push
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        
        if (q.size()>=1){
            cout << ", ";
        }
    }
    cout << ">";
}

int main(){
    int n, k;
    cin >> n >> k;
    josephus(n,k);
    
    return 0;
}