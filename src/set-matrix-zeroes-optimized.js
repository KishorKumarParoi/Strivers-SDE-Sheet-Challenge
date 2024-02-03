const prompt = require("prompt-sync")();
console.log('set-matrix-zeroes-optimized.js');

let x = prompt('Enter val : ');
console.log(x);

let matrix = [
    [1, 1, 1],
    [1, 0, 1],
    [1, 1, 1]
];

console.log(matrix);

let setZeroes = function (matrix) {
    const row = matrix.length;
    const col = matrix[0].length;

    let col0 = 1;

    const dummyRow = new Array(row).fill(-1);
    const dummyCol = new Array(col).fill(-1);

    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                dummyRow[i] = 0;
                dummyCol[j] = 0;
            }
        }
    }

    for (let i = 0; i < row; ++i) {
        for (let j = 0; j < col; ++j) {
            if (dummyCol[j] == 0 || dummyRow[i] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
}

let optimum = function (matrix) {
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

    if (col0 === 0) {
        for (let i = 0; i < row; i++) {
            matrix[i][0] = 0;
        }
    }

    if (matrix[0][0] === 0) {
        for (let j = 0; j < col; j++) {
            matrix[0][j] = 0;
        }
    }
}