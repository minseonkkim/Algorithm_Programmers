function solution(n) {
    return String(n).split('').reduce((sum, val) => sum + Number(val), 0);
}
