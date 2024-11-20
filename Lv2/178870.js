function solution(sequence, k) {
    var answer = [];
    let minLength = Number.MAX_SAFE_INTEGER;
    let ansleft = 0, ansright = 0;
    let left = 0, right = 0;
    let sum = sequence[0];
    while(right < sequence.length){
        if(sum < k) {
            right++;
            sum += sequence[right];
        }
        else if(sum > k){
            sum -= sequence[left];
            left++;
        }
        else{
            if(right - left + 1 < minLength){
                minLength = right - left + 1;
                ansleft = left;
                ansright = right;
            }
            right++;
            sum += sequence[right];
        }
    }
    answer.push(ansleft);
    answer.push(ansright);
    return answer;
}
