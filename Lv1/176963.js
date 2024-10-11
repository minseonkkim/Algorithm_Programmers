function solution(name, yearning, photo) {
    return photo.map((ele) => ele.reduce((sum, val) => sum += yearning[name.indexOf(val)] ?? 0, 0));
}
