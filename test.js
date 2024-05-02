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
  const n = Number(readline());
  const arr = readline().split(" ").map(Number);
  console.log('Before Selection Sort: ', arr);

  for (let i = 0; i < n - 1; i++) {
    let minIndex = i;
    for (let j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex !== i) {
      let temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }

  console.log('After Selection Sort: ', arr);
  printLine(process);
}