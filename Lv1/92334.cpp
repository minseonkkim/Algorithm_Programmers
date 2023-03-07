#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    // 한 유저가 같은 유저를 여러 번 신고한 경우는 신고 횟수 1회 처리
    // -> report에서 같은 값 제거 
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    map<string, int> m;  // <사용자, 신고 당한 횟수>
    map<string, bool> stop;  // <사용자, 게시판 이용 정지 유무>
    for(int i = 0; i < report.size(); i++){
        int n = report[i].find(" ");
        m[report[i].substr(n + 1)] += 1;
    }
    for(int i = 0; i < id_list.size(); i++){
        if(m[id_list[i]] >= k) stop[id_list[i]] = true;
        else stop[id_list[i]] = false;
    }
    for(int i = 0; i < report.size(); i++){
        int n = report[i].find(" ");
        if(stop[report[i].substr(n + 1)]){
            answer[find(id_list.begin(), id_list.end(), report[i].substr(0, n)) - id_list.begin()] += 1;
        }
    }
    return answer;
}
