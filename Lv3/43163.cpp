#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer;
bool visited[50];

void dfs(string cur, string target, vector<string>& words, int cnt){
    if(cur == target){
        if(answer == 0) answer = cnt;
        else answer = min(cnt, answer);
        return;
    }
    for(int i = 0; i < words.size(); i++){
        if(visited[i]) continue;
        string word = words[i];
        int count = 0;
        for(int j = 0; j < word.length(); j++){
            if(cur[j] != word[j]) count++;
        }
        if(count == 1) {
            visited[i] = true;
            dfs(word, target, words, cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    return answer;
}
