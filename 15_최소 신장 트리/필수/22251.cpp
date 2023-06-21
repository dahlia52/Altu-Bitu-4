// 빌런 호석
#include <iostream>
#include <vector>

using namespace std;
vector <int> number = {0b1111110, 0b0110000, 0b1101101,0b1111001,0b0110011,0b1011011, 0b1011111, 0b1110000,0b1111111, 0b1111011};
// x와 n의 다른 비트 수 계산
int calcDiff(vector<int> &start_number, int n, int k){
    int cnt = 0;
    for (int i = 0; i < k; i++){ // k자리에 대해 반복
        unsigned char diff = (start_number[i]^number[n%10]); // xor연산
        for (int j = 0; j < 7; j++){ // 각 자리마다 비교 
            cnt += (diff & 1);
            diff >>= 1; // 오른쪽으로 shift
        }
        n /= 10;
    }
    return cnt;
}

int solution(int n, int k, int p, int x){
    vector<int> start_number(k); // x(현재 숫자) bit를 저장
    int tmp_x = x; // 현재 숫자 저장
    for (int i = 0; i < k; i++){ // k자리에 대해 반복
        start_number[i] = number[tmp_x % 10]; // 일의 자리부터 bit 저장
        tmp_x /= 10;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){ // 1층부터 N층까지 중 반전시킬 LED 계산
        if (i == x){
            continue;
        }
        int diff = calcDiff(start_number, i, k);
        if (diff > 0 and diff <= p){
            ans++;
        }
    }
    return ans;
}

int main(){
    int n, k, p, x;
    cin >> n >> k >> p >> x;
    cout << solution(n, k, p, x);
    return 0;
}