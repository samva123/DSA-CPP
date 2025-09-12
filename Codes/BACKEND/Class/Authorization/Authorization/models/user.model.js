const mongoose = require("mongoose");

const userSchema = new mongoose.Schema({
    name:{
        type:String,
        required:true
    },
    email:{
        type:String,
        required:true,
        unique:true
    },
    password:{
        type:String,
        required:true,
        select:false // this field will not be found in .find()
    },
    role:{
        type:String,
        enum:["user","admin"],  //  possible values of attribute type string
        default:"user",
        select:false
    },
    package:{
        type:String,
        enum:["Free","gold","platinum"],
        default:"Free"

    },
    credits:{
        type:Number,
        default:0
    }
},{
    timestamps:true
});

const User = mongoose.model("User",userSchema);

module.exports = User;