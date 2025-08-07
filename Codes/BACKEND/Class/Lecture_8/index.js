const express = require("express");
const app = express();
const mongoose = require("mongoose");
require("dotenv").config();

app.use(express.json());
app.use(express.urlencoded({extended:true}));

async function connectDB(){
    mongoose.connect(process.env.DB_URI).then(()=>{
        console.log("done");
    });
    console.log("db connection done");
}

const userSchema = new mongoose.Schema({
    name:{
        type:String,
        maxLength:16,
        required:true
    },
    email:{
        type:String,
        required:true
    },
    age:{
        type:Number,
        min:1
    }

})

const User = mongoose.model("User",userSchema);

app.post("/",async (req,res)=>{
    try{
        const {name,email,age} = req.body;
        const user = await User.create({
            name,
            email,
            age
        })
        res.status(201).json({user});
    }
    catch(error){
        res.status(500).json({message:error.message});
    }
})



app.listen(3000,()=>{
    connectDB();
    console.log("server running");
})