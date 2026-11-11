// Arrow Function
const add = (a, b) => a + b;
console.log("Sum = " + add(10, 20));

// Callback
function display(name, callback) {
    callback(name);
}

function message(name) {
    console.log("Welcome " + name);
}

display("Mahesh", message);

// Promise
let p = new Promise((resolve, reject) => {
    resolve("Operation Successful");
});

p.then(result => {
    console.log(result);
});

// Async/Await
function getMessage() {
    return new Promise(resolve => {
        setTimeout(() => resolve("Welcome to ES6"), 1000);
    });
}

async function showMessage() {
    let msg = await getMessage();
    console.log(msg);
}

showMessage();

//Run using command -> node server.js
//Output : 
// Sum = 30
// Welcome Mahesh
// Operation Successful
// Welcome to ES6