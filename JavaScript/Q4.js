// 4. Create a function that takes one, two or more numbers as arguments and 
// adds them together to get a new number. The function then repeatedly multiplies
//  the digits of the new number by each other, yielding a new number, 
//  until the product is only 1 digit long. Return the final product.


let finalProduct = (...elements) => {
    let initial = 0;
    let sum = elements.reduce((prev,curr)=>prev+curr,initial);
    sum = sum.toString();

    while (sum > 9) {
        let num = 1;
        for (let i = 0; i < sum.length; i++) {
            num = num * sum[i];
        }
        sum = num.toString();
    }
    return sum;

}
console.log(`Final Product is: ${finalProduct(90,8,41)}`);