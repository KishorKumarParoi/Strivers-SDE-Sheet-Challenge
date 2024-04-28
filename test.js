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

function printPattern(n) {
  /*
 * * * * * 
 * * * * * 
 * * * * * 
 * * * * * 
 * * * * * 
 */

  // for (let i = 0; i < n; i++) {
  //     let stars = "";
  //     for (let j = 0; j < n; j++) {
  //         stars += "* ";
  //     }
  //     console.log(stars);
  // }

  /*
  * 
  * * 
  * * * 
  * * * * 
  * * * * * 
  */

  // for (let i = 0; i < n; i++) {
  //     let stars = "";
  //     for (let j = 0; j <= i; j++) {
  //         stars += "* ";
  //     }
  //     console.log(stars);
  // }

  /*
  1 
  1 2 
  1 2 3 
  1 2 3 4 
  1 2 3 4 5 
  */

  // for (let i = 0; i < n; i++) {
  //     let val = 1;
  //     let stars = '';
  //     for (let j = 0; j <= i; j++) {
  //         stars += `${val++} `;
  //     }
  //     console.log(stars);
  // }

  /*
  1 
  2 2 
  3 3 3 
  4 4 4 4 
  5 5 5 5 5 
  */

  // let val = 1;
  // for (let i = 0; i < n; i++) {
  //     let stars = '';
  //     for (let j = 0; j <= i; j++) {
  //         stars += `${val} `;
  //     }
  //     val++;
  //     console.log(stars);
  // }

  /*
  * * * * * 
  * * * * 
  * * * 
  * * 
  * 
  */

  // for (let i = 0; i < n; i++) {
  //     let stars = "";
  //     for (let j = n - 1; j >= i; j--) {
  //         stars += "* ";
  //     }
  //     console.log(stars);
  // }

  /*
  1 2 3 4 5 
  1 2 3 4 
  1 2 3 
  1 2 
  1 
  */

  // for (let i = 0; i < n; i++) {
  //     let val = 1;
  //     let stars = '';
  //     for (let j = n; j > i; j--) {
  //         stars += `${val++} `;
  //     }
  //     console.log(stars);
  // }

  /*
      * 
     * * 
    * * * 
   * * * * 
  * * * * * 
  
  */

  // for (let i = 0; i < n; i++) {
  //     let spaces = "";
  //     for (let j = n - i - 1; j > 0; j--)
  //         spaces += " ";

  //     let stars = spaces;
  //     for (let j = 0; j <= i; j++)
  //         stars += "* ";
  //     console.log(stars);
  // }

  /*
          * 
        * * * 
      * * * * * 
    * * * * * * * 
  * * * * * * * * * 
  
  */

  // for (let i = 0; i < n; i++) {
  //     let spaces = "";
  //     for (let j = n - i - 1; j > 0; j--)
  //         spaces += "  ";

  //     let stars = spaces;
  //     for (let j = 0; j < 2 * i + 1; j++)
  //         stars += "* ";
  //     console.log(stars);
  // }

  /*
    * * * * * * * * * 
      * * * * * * * 
        * * * * * 
          * * * 
            * 
  */


  // for (let i = 0; i < n; i++) {
  //     let spaces = "";
  //     for (let j = 0; j <= i; j++)
  //         spaces += "  ";

  //     let stars = spaces;
  //     for (let j = n * 2 - i - 1; j > i; j--)
  //         stars += "* ";
  //     console.log(stars);
  // }

  /*
            * 
          * * * 
        * * * * * 
      * * * * * * * 
    * * * * * * * * * 
  * * * * * * * * * * * 
    * * * * * * * * * 
      * * * * * * * 
        * * * * * 
          * * * 
            * 
  */

  // for (let i = 0; i <= n; i++) {
  //     let spaces = "";
  //     for (let j = n - i - 1; j >= 0; j--)
  //         spaces += "  ";

  //     let stars = spaces;
  //     for (let j = 0; j < 2 * i + 1; j++)
  //         stars += "* ";
  //     console.log(stars);
  // }

  // for (let i = 0; i < n; i++) {
  //     let spaces = "";
  //     for (let j = 0; j <= i; j++)
  //         spaces += "  ";

  //     let stars = spaces;
  //     for (let j = n * 2 - i - 1; j > i; j--)
  //         stars += "* ";
  //     console.log(stars);
  // }

  /*
  * 
  * * 
  * * * 
  * * * * 
  * * * * * 
  * * * * * 
  * * * * 
  * * * 
  * * 
  * 
  */

  // for (let i = 0; i < n; i++) {
  //   let stars = "";
  //   for (let j = 0; j <= i; j++) {
  //     stars += "* ";
  //   }
  //   console.log(stars);
  // }
  // for (let i = 0; i < n; i++) {
  //   let stars = "";
  //   for (let j = n - 1; j >= i; j--) {
  //     stars += "* ";
  //   }
  //   console.log(stars);
  // }

  /*

  1 
  0 1 
  1 0 1 
  0 1 0 1 
  1 0 1 0 1 
  
  */

  // let val = 1;
  // for (let i = 0; i < n; i++) {
  //   let stars = '';
  //   for (let j = 0; j <= i; j++) {
  //     if (val & 1)
  //       stars += (j & 1 ? '0 ' : '1 ');
  //     else
  //       stars += (j & 1 ? '1 ' : '0 ');
  //   }
  //   val++;
  //   console.log(stars);
  // }


  /*
  1 
  2 3 
  4 5 6 
  7 8 9 10 
  11 12 13 14 15 
  */

  // let val = 1;
  // for (let i = 0; i < n; i++) {
  //   let stars = '';
  //   for (let j = 0; j <= i; j++) {
  //     stars += `${val++} `;
  //   }
  //   // val++;
  //   console.log(stars);
  // }


  /*
  
  A
  AB
  ABC
  ABCD
  ABCDE
  
  */

  // for (let i = 0; i < n; i++) {
  //   let val = 65;
  //   let stars = '';
  //   for (let j = 0; j <= i; j++) {
  //     stars += String.fromCharCode(val);
  //     val++;
  //   }
  //   console.log(stars);
  // }

  /*
  
  ABCDE
  ABCD
  ABC
  AB
  A
  
  */

  for (let i = 0; i < n; i++) {
    let val = 65;
    let stars = '';
    for (let j = n; j > i; j--) {
      stars += String.fromCharCode(val);
      val++;
    }
    console.log(stars);
  }

}


const main = () => {
  // Start your code from here 
  let n = parseInt(readline());
  printPattern(n);
}