const express = require("express");
const app = express();
const connectDB = require("./db/connectdb");
require("dotenv").config();
const path = require("path")
const todoRouter = require("./routes/todo_routes");

app.use(express.json());
app.use(express.urlencoded({extender:true}));
app.use(express.static(path.join(__dirname,"public")));

app.use("/",todoRouter);

const port = 3000;
app.listen(port,()=>{
    console.log("Server Running on port 3000");
    connectDB();
})