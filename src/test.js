function main() {
    var str = stdin[0].split(' ').map(x => parseInt(x));
    var L = str[0];
    var P = str[1];
    var N = str[2];
    var F = N > 0 ? true : false;
    for (var i = 1; i <= Math.abs(N); i++) {
        if (F) {
            P += 1;
            P = P <= L ? P : 1;
        } else {
            P -= 1;
            P = P > 0 ? P : L;
        }
    }
    console.log(P);
}

const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin });
var stdin = [];
rl.on('line', function (line) { stdin.push(line); });
rl.on('close', main);