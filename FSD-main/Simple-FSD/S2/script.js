
function validate() {
    var name = document.getElementById("name").value;
    var email = document.getElementById("email").value;
    var password = document.getElementById("password").value;
    var confirm = document.getElementById("confirm").value;

    if (name == "") {
        alert("Please enter your name");
        return false;
    }

    if (email == "" || !email.includes("@") || !email.includes(".")) {
        alert("Please enter a valid email");
        return false;
    }

    if (password.length < 6) {
        alert("Password must contain at least 6 characters");
        return false;
    }

    if (password != confirm) {
        alert("Passwords do not match");
        return false;
    }

    document.getElementById("message").innerHTML =
        "Registration Successful, " + name + "!";

    return false;
}
