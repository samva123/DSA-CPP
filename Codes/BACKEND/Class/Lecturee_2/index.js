const express = require("express");
const app = express();
const port = 3000;

// app.get("/",(req,res)=>{
//     const result = {
//         name: "any",
//         work: null
//     }
//     console.log(req.query)
//     //res.status(200).json({result});
//     res.status(200).send("ok");

// })


// app.get("/user",(req,res)=>{
//     const result = {
//         name: "any",
//         work: null
//     }
//     console.log(req.query)
//     const uname = req.query.name;
//     const {name,degree} = req.query;
//     console.log(uname);
//     console.log(degree);
//     console.log(name);
//     //res.status(200).json({result});
//     res.status(200).send("ok");

// })

app.get("/user/sam/:id/:idd",(req,res)=>{
    const result = {
        name: "any",
        work: null
    }
    console.log(req.params)
    const id = req.params.id;
    const id2 = req.params.idd;
    console.log(id);
    console.log(id2);
    //res.status(200).json({result});
    res.status(200).send("ok");

})

const [num1 , num2] = [1,2,3,4];
console.log(num1);
console.log(num2);

app.listen(port,(req,res)=>{
    console.log("Server runnning on port 3000");
})  