"use strict";
process.stdin.resume();
process.stdin.setEncoding("utf-8");

function print(x) {
    console.log(x);
}
let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
    inputString += inputStdin;
});
process.stdin.on("end", () => {
    inputString = inputString.split("\n");
    main();
});
function readline() {
    return inputString[currentLine++];
}

function main() {
    let n; let m;
    [n, m] = readline().split(' ').map(x => parseInt(x));
    let map = {};
    for (let i = 1; i <= m; ++i) {
        map[i] = [];
    }

    for (let i = 0; i < n; ++i) {
        let input = readline().split(' ');
        let name = input[0];
        let reg_no = parseInt(input[1]);
        let score = parseInt(input[2]);
        map[reg_no].push({
            name: name,
            score: score
        });
    }
    for (let no in map) {
        map[no].sort((a, b) => b.score - a.score);
        if (map[no].length > 2 && map[no][1].score == map[no][2].score) {
            console.log('?');
        }
        else {
            console.log(map[no][0].name + " " + map[no][1].name);
        }
    }

}