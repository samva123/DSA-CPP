const express = require("express");
const app = express();
// const dateFunc = require("./utils/date-converter");
// const dateFunc = require("./utils/date-converter");

// const date = dateFunc.formatDate("01-01-2001");
// console.log(date);

// const date2 = dateFunc.anotherFormat("01-04-2001");
// console.log(date2);

const { formatDate,
  anotherFormat
} = require("./utils/date-converter");

const date = formatDate("01-01-2001");
console.log(date);

const date2 = anotherFormat("01-04-2001");
console.log(date2);

// app.get("/",(req,res)=>{
//     const date = dateFunc("01-01-2001");
//     res.send(date);
// })



app.listen(3000,(req,res)=>{
    console.log("server running on port 3000");
})