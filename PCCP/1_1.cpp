#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string input_string) {
    string answer = "";
    vector<char> v;
    vector<char> ans;
    char last = '0';
    for(int i = 0; i < input_string.length(); i++){
        char cur = input_string[i];
        if(cur != last){
            if(find(v.begin(), v.end(), cur) == v.end())
                v.push_back(cur);
            else {
                if(find(ans.begin(), ans.end(), cur) == ans.end())
                    ans.push_back(cur);
            }
        }       
        last = cur;
    }
    if(ans.empty()) return "N";
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        answer += ans[i];
    }
    return answer;
}
