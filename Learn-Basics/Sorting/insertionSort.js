/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-02
Time: 12:35:14
Problem: Insertion-Sort
Link: 
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
const main = () => {
    // Start your code from here 
    const n = Number(readline());
    const arr = readline().split(" ").map(Number);
    console.log('Before Insertion Sort: ', arr);

    // Insertion sort
    for (let i = 0; i <= n - 1; i++) {
        let j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {
            let temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
    console.log('After Insertion Sort: ', arr);
    console.log('Time taken: ', process.uptime() + 's');
}