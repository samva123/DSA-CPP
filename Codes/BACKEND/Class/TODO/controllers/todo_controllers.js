const mongoose = require("mongoose");
const todo = require("../models/todo_models");

const createTask = async(req,res)=>{
    try{
        const {status,task} = req.body;
        const temp = new todo({
            status,
            task
        });
        await temp.save();
        res.status(201).json({
            message:"Task Created Successfully",
            temp
        })
    }
    catch(error){
        res.status(500).json({message:error.message});
    }
}

const deleteTask = async(req,res)=>{
    try{
        const {id} = req.params;
        await todo.findByIdAndDelete(id);
        res.status(201).json({
            message:"message deleted succesfully"
        })
    }
    catch(error){
        res.status(500).json({message:error.message});
    }
}

const ToggleTaskStatus = async(req,res)=>{
    try{
        const {id} = req.params;
        const temp = await todo.findById(id);
        todo.status = !todo.status;
        await temp.save();
        res.status(201).json({message:"todo updated"});
    }
    catch(error){
        res.status(500).json({message:error.message});
    }
}

const getTask = async(req,res)=>{
    try{
        const {task} = req.query;
        const matchedTodos = await todo.find({task:{$regex:task,$options:"i"}});
        res.status(201).json({todos:matchedTodos});
    }
    catch(err){
        res.status(500).json({message:err.message});
    }
}

module.exports = {createTask,deleteTask,ToggleTaskStatus,getTask};