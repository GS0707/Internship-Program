// 3. Create a function which counts how many lone 1s appear in a given number.
//  Lone means the number doesn't appear twice or more in a row.

// example: countLoneOnes(101) ➞ 2, countLoneOnes(1191) ➞ 1

let countLoneOnes = number => {
    let count = 0;

    for (let i = 0; i < number.length; i++) {

        if (number[i] !== '1')
            continue

        if ((number[i - 1] !== '1') && (number[i + 1] !== '1'))
            count++;
    }
    return count;
}

let number = '110112121';

console.log(`Lone 1s appear in a given number: ${countLoneOnes(number)}`);