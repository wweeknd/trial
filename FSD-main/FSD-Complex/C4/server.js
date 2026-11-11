const express = require("express");
const { MongoClient, ObjectId } = require("mongodb");

const app = express();
app.use(express.json());

async function start() {
    const client = new MongoClient("mongodb://localhost:27017");
    await client.connect();

    const db = client.db("studentDB");
    const students = db.collection("students");

    app.post("/add", async (req, res) => {
        await students.insertOne(req.body);
        res.send("Added");
    });

    app.get("/students", async (req, res) => {
        res.json(await students.find().toArray());
    });

    app.put("/update/:id", async (req, res) => {
        await students.updateOne(
            { _id: new ObjectId(req.params.id) },
            { $set: req.body }
        );
        res.send("Updated");
    });

    app.delete("/delete/:id", async (req, res) => {
        await students.deleteOne({
            _id: new ObjectId(req.params.id)
        });
        res.send("Deleted");
    });

    app.listen(4000);
}

start();


// 2. Execute
// npm init -y
// npm install express mongodb
// node server.js


// Ensure MongoDB is running.
// 3. Postman URLs
// Operation	Method	URL
// Add	POST	http://localhost:4000/add
// Read	GET	http://localhost:4000/students
// Update	PUT	http://localhost:4000/update/ID
// Delete	DELETE	http://localhost:4000/delete/ID

// For POST, select Body → raw → JSON: