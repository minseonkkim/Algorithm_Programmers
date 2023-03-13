#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long quesum1 = 0, quesum2 = 0;
    queue<int> q1; queue<int> q2;
    for(int i = 0; i < queue1.size(); i++){
        quesum1 += queue1[i];
        q1.push(queue1[i]);
    }
    for(int i = 0; i < queue2.size(); i++){
        quesum2 += queue2[i];
        q2.push(queue2[i]);
    }
    
    if((quesum1 + quesum2) % 2 != 0) return -1;
    
    int n = 3 * quesum1;    
    while(n--){
        if(quesum1 > quesum2){
            int x = q1.front();
            quesum2 += x;
            quesum1 -= x;
            q2.push(x);
            q1.pop();
        } else if(quesum1 < quesum2){
            int x = q2.front();
            quesum1 += x;
            quesum2 -= x;
            q1.push(x);
            q2.pop();
        } else{
            return answer;
        }
        answer++;
    }
    return -1;
}
