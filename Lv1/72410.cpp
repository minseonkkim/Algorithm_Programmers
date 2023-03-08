#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    bool flag = false;
    for(int i = 0; i < new_id.length(); i++){
        // 1단계
        new_id[i] = tolower(new_id[i]);
        
        // 2단계
        if(!isdigit(new_id[i]) && !isalpha(new_id[i]) && new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.'){
            new_id.erase(i, 1);
            i--;
            continue;
        }
        
        // 3단계
        if(new_id[i] == '.' && flag){
            new_id.erase(i, 1);
            i--;
        } else if(new_id[i] == '.' && !flag){
            flag = true;
        } else{
            flag = false;
        }
    }
    
    // 4단계
    if(new_id.front() == '.') new_id.erase(0, 1);
    if(new_id.back() == '.') new_id.erase(new_id.length() - 1, 1);
    
    // 5단계
    if(new_id.empty()) new_id = "a";
    
    // 6단계
    if(new_id.length() >= 16){
        new_id.erase(15);
        while(new_id.back() == '.'){
            new_id.pop_back();
        }
    }
    
    // 7단계
    while(new_id.length() <= 2){
        new_id.push_back(new_id.back());
    }
    
    return new_id;
}
