// 호텔 방 배정 - 메모리, 시간 초과
#include <string>
#include <vector>
using namespace std;

void findRoom(long long want, long long k, vector<long long> &min_room){
    long long assignRoom = min_room[want]; // 배정된 방
    for (long long i = assignRoom; i>0; i--){
        if (min_room[i] == assignRoom){
            min_room[i] = min_room[assignRoom+1]; // 배정된 방을 최솟값으로 하던 방들 업데이트
        }
        else{
            break;
        }
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer(room_number.size(),0);
    vector<long long> min_room(k+1, 0); // 가능한 방의 최솟값 저장
    
    for (long long i = 1; i<=k; i++){
        min_room[i] = i;
    }
    for (long long i = 0; i<room_number.size(); i++){
        answer[i] = min_room[room_number[i]];
        findRoom(room_number[i] , k ,min_room);
    }
    return answer;
}