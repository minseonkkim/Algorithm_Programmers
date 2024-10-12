function solution(s) {
    let result = [];
    let map = new Map();
    s.split('').forEach((el, idx) => {
        if(map[el] == undefined) result.push(-1);
        else result.push(idx - map[el]);
        map[el] = idx;
    });
    return result;
}
