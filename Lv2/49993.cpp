#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill_trees.size(); i++){
        string cskill = skill_trees[i];
        int skill_idx = 0;
        bool possible = true;
        for(int j = 0; j < cskill.length(); j++){
            int idx = skill.find(cskill[j]);
            if(idx == -1) continue;
            if(idx == skill_idx) skill_idx++;
            else {
                possible = false;
                break;
            }
        }
        if(possible) answer++;
    }
    return answer;
}
