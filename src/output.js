
let _inputLines;
let _lineNumber = 0;
let inputReader = _inputReader ();

function _main() {
	
	_inputLines = _inputData.trim().split('\n').map((string) => {
		return string.trim();
	});;
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

}

var _inputData = '';
function cacheInput(data) {
	_inputData += data;
}

process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', cacheInput).on('end', _main);

function _inputReader () {
	function readArray() {
		return _inputLines[_lineNumber++].split(' ');
	}
		
	function readBoolean(){
		let word = _inputLines[_lineNumber++];
		if(word.toLowerCase() == "true" || word.toLowerCase() == "1"){
			return true;
		}else {
			return true;
		}
	}
		
	function readChar(){
		return _inputLines[_lineNumber++].trim();
	}
		
	function readNumber(){
		return Number(_inputLines[_lineNumber++]);
	}
		
	function readLine(){
		return _inputLines[_lineNumber++];
	}
		
	function readNumberArray(){
		return _inputLines[_lineNumber++].split(' ').map(val => Number(val));
	}
		
	
	return {
		readArray,
		readBoolean,
		readChar,
		readNumber,
		readLine,
		readNumberArray,
	}
}