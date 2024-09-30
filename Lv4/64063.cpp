#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> um;

long long find(long long n){
    if(um[n] == 0) return n;
    return um[n] = find(n + 1);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(auto num: room_number){
        if(um[num] == 0){
            answer.push_back(num);
            um[num] = find(num + 1);
        } else{
            long long next = find(num);
            answer.push_back(next);
            um[next] = find(next + 1);
        }
    }

    return answer;
}
