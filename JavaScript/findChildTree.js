// Tree is represented in Array.
// Find child Tree of Given parent.

let findChild = (parent) => {
    let child = tree.filter((node) => parent === node.parent)
    child.forEach((node) => {
        child.push(...findChild(node.id));
    })
    return child;
}
let tree = [
    { id: 0, value: "Zero", parent: -1 },
    { id: 1, value: "One", parent: 0 },
    { id: 2, value: "Two", parent: 1 },
    { id: 3, value: "Three", parent: 1 },
    { id: 4, value: "Four", parent: 1 },
    { id: 5, value: "Five", parent: 1 },
    { id: 6, value: "Six", parent: 4 },
    { id: 7, value: "Seven", parent: 4 },
    { id: 8, value: "Eight", parent: 5 },
    { id: 9, value: "Nine", parent: 5 },
    { id: 10, value: "Ten", parent: 7 },
    { id: 11, value: "Eleven", parent: 7 },
    { id: 12, value: "Twelve", parent: 5 },
    { id: 13, value: "Thirteen", parent: 6 },
    { id: 14, value: "Fourteen", parent: 8 },
]

let input = 1;
let result = findChild(input)
if (result.length) {
    let child = result.map((element) => element.id);
    console.log(`Child Tree of ${input} Node: ${child}`);
}
