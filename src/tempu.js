let input = "";
process.stdin.on('data', function (chunk) {
    input += chunk;
})

process.stdin.on("end", function () {
    main(input);
})

const prompt = require('prompt-sync');

function main(input) {
    // console.log(input);
    let val = prompt('Enter val : ');
    console.log(val * 10);
}