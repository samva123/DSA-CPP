
// const express = require('express');
// const app = express();

// app.listen(8000,() => {
//     console.log("server started heloo ")
// });

// app.get('/',(req,res) => {
//     res.send("hello jee kya haal chaal");
// })  

// app.post('/api/cars',(req,res) =>{
//     const{name,brand} = request.body;
// console.log(name);
// console.log(brand);
// response.send("car submitted");

// })

//const mongoose = require('mongoose');

// const connectDB = ()=>{
//     // mongoose.set('strictquery' ,true);
// // mongoose.set('useNewUrlParser', true);
//  mongoose.connect('mongodb://127.0.0.1:27017'
//     // useNewUrlParser : true,
//     // useUnifiedTopology:true,

// )
// .then(() => {console.log("connection s ");
// })
// .catch((err) => {console.log("error");
// });
// }

// module.exports = connectDB;
// const mongoose = require('mongoose');
// const url = "mongodb://127.0.0.1:27017/mydatabase";

// mongoose.connect(url).then(() => {
//     console.log(" DB connection successful");
// }).catch((err) => {
//     console.log("Not Connected to Database ERROR! ", err);
// });

const express = require("express");
const app = express();

//load config from env file
require("dotenv").config();
const PORT = process.env.PORT || 3000;

//middleware to parse json request body
app.use(express.json());

//import routes for TODO API
const todoRoutes = require("./routes/todo");

//mount the todo API routes
app.use("/api/v1", todoRoutes);

//start server
app.listen(PORT, () => {
  console.log(`Server started successfully aat ${PORT}`);
});

//connect to the database
const dbConnect = require("./config/database");
dbConnect();

//default Route
app.get("/", (req, res) => {
  res.send(`<h1> This is HOMEPAGE baba</h1>`);
});



// object 
// 1.) req - body . query params , param , headers , ip
// 2.) res - send(string only) , json (to send data in object form), status , redirect(to direct api to another api) , sendfile