// 호텔 방 배정 - 유니온 파인드
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
/*
 * 투숙객이 원하는 방이 비어 있다면 방 배정
 * 방 배정 후, 해당 방의 다음 방을 집합의 루트 정점으로 설정 (다음 빈 방을 바로 찾을 수 있음)
 * 벡터로 parent를 선언하면 전체 방 개수(k)의 최대가 10^12이기 때문에 메모리 초과
 * 필요한 방의 parent 정보 저장을 위해 map 사용 (key: 방 번호, value: 문제의 조건 4를 만족하는 방의 번호)
 * 그냥 map 사용시 시간초과, 키 값을 정렬하지 않는 unordered_map 사용
 */

ll findRoom(ll node, unordered_map<ll, ll> &parent){
    if (parent[node] == 0){ // 방이 비어 있는 경우 즉시 배정
        parent[node] = node + 1; // 방이 배정되었으므로 다음 방으로 업데이트
        return node;
    }
    return parent[node] = findRoom(parent[node], parent);
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    unordered_map<ll, ll> parent; // 가능한 방의 최솟값 저장
    
    for (ll i : room_number){    
        ll room = findRoom(i, parent); // 방 배정
        answer.push_back(room);
    }
    
    return answer;
}