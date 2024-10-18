#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {    
    vector<int> finish;
    
    for(int i = 0; i < progresses.size(); i++){
        int left = 100 - progresses[i];
        int fns = left / speeds[i];
        if(left % speeds[i] != 0) fns += 1;
        finish.push_back(fns);
    }
    
    
    vector<int> answer;
    int maxnum = finish[0];
    int maxcnt = 1;
    for(int i = 1; i < finish.size(); i++){
        if(finish[i] > maxnum){
            answer.push_back(maxcnt);
            maxnum = finish[i];
            maxcnt = 1;
        } else{
            maxcnt++;
        }
    }
    answer.push_back(maxcnt);
    return answer;
}
