#include <string>
#include <vector>

using namespace std;

vector<int> solution(string command) {
    vector<int> answer(2, 0);
    int dir = 1; // 1: 위, 2: 오, 3: 아래, 4: 왼
    for(int i = 0; i < command.length(); i++){
        char c = command[i];
        if(c == 'R'){
            dir++;
            if(dir == 5) dir = 1;
        } else if(c == 'L'){
            dir--;
            if(dir == 0) dir = 4;
        } else if(c == 'G'){
            if(dir == 1) answer[1]++;
            else if(dir == 2) answer[0]++;
            else if(dir == 3) answer[1]--;
            else if(dir == 4) answer[0]--;
        } else if(c == 'B'){
            if(dir == 1) answer[1]--;
            else if(dir == 2) answer[0]--;
            else if(dir == 3) answer[1]++;
            else if(dir == 4) answer[0]++;
        }
    }
    return answer;
}
