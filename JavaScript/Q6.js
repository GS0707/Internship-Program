// 6. In JavaScript ES6 an arrow function expression is a syntactically 
// compact alternative to a regular function expression. 
// Create a function that takes a string representing a function and
//  converts between an arrow function and a regular function

// - If the input is a regular function, return an equivalent arrow function.

// - If the input is an arrow function, return an equivalent regular function.


// function to convert regular function to arrow function.
let convertRegularFunction = (obj) => {

    funcConverted = obj.split(" ")

    funcConverted.splice(0, 1, "let");

    let parenStart = funcConverted[1].indexOf("(");
    let parentEnd = funcConverted[1].indexOf(")")

    let funcName = funcConverted[1].substring(0, parenStart);
    let parameters = funcConverted[1].substring(parenStart, parentEnd + 1);

    funcConverted.splice(1, 1, funcName, " = ", parameters, " => ");
    console.log(funcConverted.join(' '));
}

// function to convert arrow function to regular function 
let convertExpression = (obj) => {
    funcConvert = obj.split(" ");

    funcConvert.splice(0, 5, "function", funcConvert[1] + funcConvert[3]);
    console.log(funcConvert.join(" "));
}

let regularFunc = `function hello(one) { let ob = "Hello"; }`;

let arrowFunc = `let hello = (one,two) => { let ob = "Hello"; }`;

convertExpression(arrowFunc);

convertRegularFunction(regularFunc);

