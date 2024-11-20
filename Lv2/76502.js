function solution(s) {
    var answer = 0;
    let n = s.length;
    for (let x = 0; x < n; x++) {
        let tmp = s[s.length - 1];
        s = s.substr(0, s.length - 1);
        s = tmp + s;
        
        let stack = []; 
        let isCur = true;
        for(let i = 0; i < s.length; i++){           
            
            if(s[i] === '(' || s[i] === '[' || s[i] === '{') stack.push(s[i]);
            else{
                if(stack.length === 0) {
                    isCur = false;
                    break;
                }
                else if((s[i] === ')' && stack[stack.length - 1] === '(') ||
                   (s[i] === ']' && stack[stack.length - 1] === '[') || 
                   (s[i] === '}' && stack[stack.length - 1] === '{')){
                    stack.pop();
                } 
                else {
                    isCur = false;
                    break;
                }
            }
        }
        if(isCur && stack.length === 0) answer++;   
    }
    return answer;
}
