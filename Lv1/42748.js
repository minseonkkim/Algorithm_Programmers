function solution(array, commands) {
    let answer = [];
    commands.forEach((command, idx) => {
        let arr = array.slice(commands[idx][0] - 1, commands[idx][1]);
        arr.sort((a, b) => a - b);
        answer.push(arr[commands[idx][2] - 1]);
    });
    return answer;
}
