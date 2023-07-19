// 요세푸스 문제
#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    deque<int> dq;
    
    for (int i = 1; i<=n; i++){
        dq.push_back(i);
    }
    cout << "<";
    int idx = k-1;
    
    while (n >= 2){
        cout << dq[idx];
        dq.erase(dq.begin() + idx);
        n--;
        idx = (idx + k-1) % n;
        cout << ", ";
    }
    cout << dq.front() << ">";
    
    return 0;
}