#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct File{
    int index;
    string head;
    int number;
};

vector<File> v;

bool cmp(File a, File b){
    if(a.head == b.head) {
        if(a.number == b.number) return a.index < b.index;
        else return a.number < b.number;
    } 
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(int i = 0; i < files.size(); i++){
        vector<int> idx;
        for(int j = 0; j < files[i].length(); j++){
            if(files[i][j] >= '0' && files[i][j] <= '9'){
                idx.push_back(j);
            }
        }
        
        string head = "";
        for(int j = 0; j < idx[0]; j++){
            head += tolower(files[i][j]);
        }
        int number = stoi(files[i].substr(idx[0], idx.size()));
        
        File f;
        f.index = i;
        f.head = head;
        f.number = number;
        v.push_back(f);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < v.size(); i++){
        answer.push_back(files[v[i].index]);
    }
    
    return answer;
}
