/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-02-03
Time: 18:46:11
Problem: Set-Matrix-Zeroes
Link: Leetcode
*/
"use strict"
process.stdin.resume()
process.stdin.setEncoding("utf-8")
const printLine = (x) => {
    console.log(x);
}
const print = (x) => {
    process.stdout.write(x);
}
let inputString = "";
let currentLine = 0;
process.stdin.on("data", (inputStdin) => {
    inputString += inputStdin;
})
process.stdin.on("end", () => {
    inputString = inputString.split("\n");
    main();
})
const readline = () => {
    return inputString[currentLine++];
}

let setZeroes = function (matrix) {
    const row = matrix.length;
    const col = matrix[0].length;

    let col0 = 1;
    // const dummyCol = matrix[0][...];
    // const dummyRow = matrix[...][0];

    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (matrix[i][j] === 0) {
                if (j === 0) {
                    col0 = 0;
                } else {
                    matrix[0][j] = 0;
                }

                matrix[i][0] = 0;
            }
        }
    }

    for (let i = 1; i < row; i++) {
        for (let j = 1; j < col; j++) {
            if (matrix[0][j] === 0 || matrix[i][0] === 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] === 0) {
        for (let j = 0; j < col; j++) {
            matrix[0][j] = 0;
        }
    }

    if (col0 === 0) {
        for (let i = 0; i < row; i++) {
            matrix[i][0] = 0;
        }
    }


    for (let i = 0; i < matrix.length; ++i) {
        console.log(matrix[i]);
    }
    console.log("");
}

const main = () => {
    // Start your code from here 
    let testKase = parseInt(readline());
    while (testKase--) {
        // row col
        let input = readline().split(" ").map(Number);
        let [row, col] = input;

        let matrix = [];

        for (let i = 0; i < row; ++i) {
            input = readline().split(" ").map(Number);
            matrix.push(input);
        }
        setZeroes(matrix);
    }
}