// 큰 수 A+B
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void cal(string a, string b){ // b가 길이가 더 긴 문자열
    int len_a = a.size(), len_b = b.size();
    a = '0' + a, b = '0' + b;
    vector<int> ans(b.size(),0); // 정답 저장
    for (int i = len_b; i>len_b-len_a; i--){
        ans[i] += a[i+len_a-len_b] - '0' + b[i] - '0';
        ans[i-1] += (ans[i] / 10);
        ans[i] %= 10;
    }
    for (int i = len_b - len_a; i>0; i--){
        ans[i] += b[i] - '0';
        ans[i-1] += (ans[i] / 10);
        ans[i] %= 10;
    }
    // 출력
    for (int i = 0; i < ans.size(); i++){
        if (i == 0 and !ans[i]){
            continue;
        }
        cout << ans[i];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;
    
    if (a.size() <= b.size()){
        cal(a,b);
    }
    else{
        cal(b,a);
    }
    return 0;
}