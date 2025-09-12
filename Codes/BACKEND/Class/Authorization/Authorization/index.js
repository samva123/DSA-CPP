const express = require("express");
const app = express();
const connectDB = require("./db/connectdb");
require("dotenv").config();
const cors = require("cors");

const routerPaths = require("./routes/auth.routes");
const userRouter = require("./routes/user.routes");

const path = require('path');

app.use(cors());
app.set("view engine", "ejs");
app.set('views',path.join(__dirname,"views"));

app.use(express.json());
app.use(express.urlencoded({extended:true}));


app.get("/", (req, res) => {
    const name = "sam";
    const contacts = [{name:"conatact 1" , phone:1223342112} , {name:"contact 2" , phone:1223342112}]

    //res.render("index", { name, contacts });
    res.render("index", { username:name, contacts });
});


app.use("/auth",routerPaths);
app.use("/user",userRouter);

app.listen(5000,()=>{
    console.log("server started on port 3000");
    connectDB();
})