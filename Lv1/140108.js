function solution(s) {
    let x = 0;
    let xcnt = 0;
    let answer = 0;
    [...s].forEach((el, idx) => {
        if(el == s[x]) xcnt++;
        else xcnt--;
        if(xcnt == 0){
            x = idx + 1;
            answer++;
        }
    });
    if(x !== s.length) answer++;
    return answer;
}
