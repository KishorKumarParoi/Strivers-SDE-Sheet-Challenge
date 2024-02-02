const { inputReader } = require('competitive-programming-js');

// To read Number from console
let noOfTestCases = inputReader.readNumber();
console.log(noOfCase, typeof noOfCase);
while (noOfTestCases--) {
    // To read generic array separated by space
    let tmp = inputReader.readArray();
    console.log(tmp, typeof tmp);

    // To read boolean value i.e. 'true' or 'false' (It's case insensitive)
    tmp = inputReader.readBoolean();
    console.log(tmp, typeof tmp);

    // To read a single character
    tmp = inputReader.readChar();
    console.log(tmp, typeof tmp);

    // to read a line
    tmp = inputReader.readLine();
    console.log(tmp, typeof tmp);

    // To read a numeric array
    tmp = inputReader.readNumberArray();
    console.log(tmp, typeof tmp);
}