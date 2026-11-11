
const express = require("express");
const jwt = require("jsonwebtoken");
const { MongoClient, ObjectId } = require("mongodb");

const app = express();
app.use(express.json());

const client = new MongoClient("mongodb://localhost:27017");
const secret = "abc";

async function start() {
    await client.connect();
    const db = client.db("studentDB");
    const students = db.collection("student");

    app.post("/login", (req, res) => {
        if (req.body.username == "admin" &&
            req.body.password == "1234") {
            res.send(jwt.sign({ user: "admin" }, secret));
        } else {
            res.status(401).send("Invalid login");
        }
    });

    function auth(req, res, next) {
        try {
            jwt.verify(req.headers.authorization.split(" ")[1], secret);
            next();
        } catch {
            res.status(401).send("Unauthorized");
        }
    }

    app.post("/add", auth, async (req, res) => {
        await students.insertOne(req.body);
        res.send("Added");
    });

    app.get("/students", auth, async (req, res) => {
        res.json(await students.find().toArray());
    });

    app.put("/update/:id", auth, async (req, res) => {
        await students.updateOne(
            { _id: new ObjectId(req.params.id) },
            { $set: req.body }
        );
        res.send("Updated");
    });

    app.delete("/delete/:id", auth, async (req, res) => {
        await students.deleteOne({ _id: new ObjectId(req.params.id) });
        res.send("Deleted");
    });

    app.listen(4000);
}

start();




// Execution steps
// 1. Install packages
// npm init -y
// npm install express jsonwebtoken mongodb


// 2. Start MongoDB and save the code as server.js.

// 3. Run the server
// node server.js


// Endpoints
// Method	URL	Purpose
// POST	/login	Generate JWT
// POST	/add	Add student
// GET	/students	View students
// PUT	/update/:id	Update student
// DELETE	/delete/:id	Delete student

// Testing in Postman
// 1. Login: POST http://localhost:4000/login
   
//    Body → raw → JSON:
//    {"username":"admin","password":"1234"}
// 2. Copy the returned token.
// 3. For all other endpoints, add this header:
   
//    Authorization: Bearer YOUR_TOKEN
// 4. For adding a student, use POST /add with:
//    {"name":"Ravi","course":"CSE"}
// Result: JWT authentication was implemented to protect MongoDB student CRUD endpoints.