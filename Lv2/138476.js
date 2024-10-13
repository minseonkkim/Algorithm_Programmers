function solution(k, tangerine) {
    var answer = 0;
    let map = new Map();
    tangerine.forEach(el => map.set(el, map.has(el) ? map.get(el) + 1 : 1));
    let sortedArr = [...map].sort((a, b) => b[1] - a[1]);
    sortedArr.forEach((el) => {
        if(k > 0){
            k -= el[1];
            answer++;
        }
    })
    return answer;
}
