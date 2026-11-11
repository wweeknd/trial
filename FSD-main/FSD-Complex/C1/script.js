let products = [
    { name: "Mobile", price: 100 },
    { name: "Laptop", price: 500 }
];

let total = 0;

products.forEach(function(p) {
    document.querySelector(".catalog").innerHTML +=
        `<div>
            <h3>${p.name}</h3>
            <p>$${p.price}</p>
            <button onclick="addToCart('${p.name}', ${p.price})">
                Add to Cart
            </button>
        </div>`;
});

function addToCart(name, price) {
    document.getElementById("items").innerHTML +=
        `<p>${name} - $${price}</p>`;

    total += price;
    document.getElementById("total").innerHTML = total;
}

function checkout() {
    alert("Thank you for shopping!");
}
