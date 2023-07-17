// 패션왕 신해빈
#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef pair<int, int> pi;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t, n;
    string a, b;
    cin >> t;
    while (t--){
        cin >> n;
        map<string, int> m;
        for (int i = 0; i < n; i++){
            cin >> a >> b;
            m[b] += 1;
        }
        int ans = 1;
        for (auto [item, num]: m){
            ans*=(num+1);
        }
        cout << ans -1 << '\n';
    }

    return 0;
}