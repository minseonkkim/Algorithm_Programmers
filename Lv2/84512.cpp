#include <string>
#include <vector>
using namespace std;

char alphabet[5] = {'A', 'E', 'I', 'O', 'U'};
int cnt = -1;
int answer = 0;

void dfs(string mwd, string target){
    cnt++;
    if(mwd == target) {
        answer = cnt;
        return;
    }
    if(mwd.length() >= 5) return;
    
    for(int i = 0; i < 5; i++){
        dfs(mwd + alphabet[i], target);
    }
}

int solution(string word) {
    dfs("", word);
    return answer;
}
