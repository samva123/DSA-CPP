const express = require('express');
const app = express();

app.use(express.json());




app.listen(4000,() => {
    console.log("server started");
});

app.get('/' , (req , res) => {
    res.send("hello ji");
})




































const mongoose = require('mongoose');
const url = "mongodb://127.0.0.1:27017/mydatabase";

mongoose.connect(url).then(() => {
    console.log("DB connection successful");
}).catch((err) => {
    console.log("Not Connected to Database ERROR! ", err);
});