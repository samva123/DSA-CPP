const mongoose = require("mongoose");

const productSchema = new mongoose.Schema({
    name:{
        type:String,
        required:true,
        trim:true
    },
    description:{
        type:String,
        //required:true
    },
    price:{
        type:Number,
        min:9,
        required:true
    },

},{
    timestamps:true
})

const Product = mongoose.model("Product",productSchema);

module.exports = Product;