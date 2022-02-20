// 5. Given an array, write a function to calculate it's depth. 
// Assume that a normal array has a depth of 1.

// example:

//                 depth([1, 2, 3, 4]) ➞ 1

//                 depth([1, [2, 3, 4]]) ➞ 2

//                 depth([1, [2, [3, 4]]]) ➞ 3

//                 depth([1, [2, [3, [4]]]]) ➞ 4


const depth = (arr, count) => {
    arr.forEach(element => {
        if (typeof element == 'object')
            count = depth(element, count = count + 1);
    });
    return count;
}
console.log(`Depth of Given Array is: ${depth([1,[2, [3, 4]]],1)}`);