const mongoose = require("mongoose");

async function connectDB(){
    await mongoose.connect(process.env.DB_URI).then(()=>{
        console.log("MongoDB Connected Succesfully");
    }).catch((err)=>{
        console.error("Attemp Failed: "+ err.message);
    })
}

module.exports = connectDB;