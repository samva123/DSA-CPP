const mongoose = require("mongoose");
const User = require("../models/user.model");
const bcrypt = require("bcrypt");
const jwt = require("jsonwebtoken");

const createAccount = async(req,res)=>{
    try{
        let {name,email,password} = req.body;
        if(!name || !email || !password){
            throw new Error("All field are required");
        }
        const hashPass = await bcrypt.hash(password,10); // salt rounds = 10 (times a hash will happen on string)
        let user = await User.create({
            name:name,
            email:email,
            password:hashPass
        })
        res.status(201).json({message:"user account created successfully"});
    }
    catch(error){
        console.log(error);
        res.status(500).json({message:error.message});
    }
}

const adminSignup = async (req,res)=>{
    try{
        let {name,email,password} = req.body;
        if(!name || !email || !password){
            throw new Error("All field are required");
        }
        const hashPass = await bcrypt.hash(password,10); // salt rounds = 10 (times a hash will happen on string)
        let user = await User.create({
            name:name,
            email:email,
            password:hashPass,
            role:"admin"
        })
        res.status(201).json({message:"user account created successfully"});
    }
    catch(error){
        console.log(error);
        res.status(500).json({message:error.message});
    }
}

const loginAccount = async(req,res)=>{
    try{
        const {email,password} = req.body;
        const user = await User.findOne({email:email}).select("+password"); // bcz in models password is set to select:false
        if(!user){
            throw new Error("Invalid email or password");
        }
        const isMatched = await bcrypt.compare(password,user.password);
        if(!isMatched){
            throw new Error("Invalid email or password");
        }

        const token = jwt.sign({id:user._id,name:user.name,email:user.email},
            process.env.JWT_SECRET,  // secret key 
            {expiresIn:"2h",algorithm:"HS256"}
        );  // creates token
        res.cookie("token",token,{httpOnly:true,secure:false,domain:"localhost",path:"/",maxAge:24*60*60*1000});
        res.status(200).json({message:"User login successfull",token:token});
    }   
    catch(error){   
        res.status(400).json({message:error.message});
    }
}


const userLoggedIn = async(req,res)=>{
    try{
        // const authorization = req.headers.authorization;
        // const token = authorization.split(" ")[1];
        // const payload = jwt.verify(token,process.env.JWT_SECRET);
        res.status(200).json({message:"welcome user",user:req.user});
    }
    catch(error){
        res.status(501).json({message:error.message});
    }
}

const getAllUsers = async(req,res)=>{
    try{
        const user = await User.find({role:{$ne:"admin"}});
        res.status(201).json({user});
    }   
    catch(error){
        res.status(400).json({message:error.message});
    }
}

module.exports = {createAccount,loginAccount,userLoggedIn,adminSignup,getAllUsers};