// 1. A boomerang is a V-shaped sequence that is either upright
//  or upside down. Specifically, a boomerang can be defined 
//  as: sub-array of length 3, with the first and last digits 
//  being the same and the middle digit being different.

// input: [3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2]

// output: 3 boomerangs in this sequence:  [3, 7, 3], [1, 5, 1], [2, -2, 2]

const input = [1,1,1,2,5,2];

let boomerang = [];

for (let i = 0; i <= input.length - 3; i++) {
    if (input[i] === input[i + 2])
        boomerang.push(input.slice(i, i + 3));
}
console.log(`${boomerang.length} boomerangs in this sequence:`);
console.log(boomerang);