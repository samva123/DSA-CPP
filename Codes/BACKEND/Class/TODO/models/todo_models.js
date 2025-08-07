const mongoose = require("mongoose");

const todoSchema = new mongoose.Schema({
    status:{
        type:Boolean,
        default:false
    },
    task:{
        type:String,
        required:true
    }
})

const todo = mongoose.model("todo",todoSchema);
module.exports = todo;