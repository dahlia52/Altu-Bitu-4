// 균형잡힌 세상
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    string x;
    while (true){
        stack<int> s; // 괄호 저장
        getline(cin, x); // 입력
        if (x == "."){ // 종료 조건
                return 0;
        }
        for (int i = 0; i < x.size(); i++){
            if (x[i] == '.'){
                if (s.empty()){
                    cout << "yes\n";
                }
                else{
                    cout << "no\n";
                }
                break;
            }
            if (x[i] == '(' or x[i] == '['){
                s.push(x[i]);
            }
            else if (x[i] == ')'){
                if (s.size()>=1 and s.top() == '('){
                    s.pop();
                }
                else{
                    cout << "no\n";
                    break;
                }
            }
            else if (x[i] == ']'){
                if (s.size()>=1 and s.top() == '['){
                   s.pop(); 
                }
                else{
                    cout << "no\n";
                    break;
                }
            }
        }
    }
}