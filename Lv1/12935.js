function solution(arr) {
    let answer = [];
    arr.splice(arr.indexOf(Math.min(...arr)), 1);
    arr.length == 0 ? answer = [-1] : answer = arr;  
    return answer;
}
