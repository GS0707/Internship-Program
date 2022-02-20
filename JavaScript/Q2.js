// 2. Create a function that takes an array of strings and
//  returns an array with only the strings that have numbers in them. 
//  If there are no strings containing numbers, return an empty array.

let filterStrings = (input) => {
    
    return input.filter(str => /[0-9]+/.test(str));
};

let arrayStrings = ["Gajanan", "123", "Hello", "11", "12A","a23"];

let filterArray = filterStrings(arrayStrings)
console.log(`Array with only the strings that have numbers:`);
console.log(filterArray);

