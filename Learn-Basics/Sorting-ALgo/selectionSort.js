/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-02
Time: 12:35:14
Problem: Selection-Sort
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
    const t = readline();
    const k = readline();
    const p = readline();
    console.log(t);
    console.log(k);
    console.log(p);

}