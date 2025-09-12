const express = require("express");
const verifyUser = require("../middleware/verify.middleware");
const User = require("../models/user.model");
const Product = require("../models/product.model");
const { verifyGold } = require("../middleware/verifyprem.middleware");
const router = express.Router();

const products = [
    {
    name:"toy",
    price:100,
    description:"A fun toy for kids"
    },
    {
    name:"book",
    price:15,
    description:"A thrilling adventure book"
    },
    {
    name:"bike",
    price:200,
    description:"A cool bike for kids"
    }

]

router.get("/create/products", async(req , res)=>{
    try{
        const Allproducts = await Product.insertMany(products);
        res.status(201).json({
            success:true,
            data:Allproducts,
            message:"Products created successfully"
        });
    }catch(err){
        console.error(err);
        res.status(500).json({
            success:false,
            message:"Internal Server Error"
        });
    }
});


router.post("/package/boy",verifyUser,async(req , res)=>{
    try{
        const {package} = req.query;
        if(!package){
            return res.status(400).json({
                success:false,
                message:"Package is required"
            });
        }
        const currUserId = req.user.id;
        const user  = await User.findById(currUserId);
        user.package = package;
        if(package === "gold"){
            user.credits += 100;
        }else if(package === "platinum"){
            user.credits += 200;
        }
        await user.save();
        res.status(200).json({
            success:true,
            message:"Package updated successfully"
        });

    }catch(err){
        console.error(err);
        res.status(500).json({
            success:false,
            message:"Internal Server Error"
        });
    }
})

router.get("/gold/discount/:productId",verifyUser ,verifyGold, async(req , res)=>{
    try{
        const{productId} = req.params;
        const userId= req.user.id;
        const [user , product] = await Promise.all([
            await User.findById(userId),
            await Product.findById(productId)
        ]);
        console.log(userId);
        if(user.credits - (product.price*0.1) < 0){
            throw new Error("Insufficient credits");
        }
        const discountedPrice = product.price-(product.price*0.1);
        user.credits -= (product.price*0.1);
        await user.save();
        res.status(200).json({
            success:true,
            data:{
                originalPrice:product.price,
                discountedPrice
            }
        });

    }catch(err){
        console.error(err);
        res.status(500).json({
            success:false,
            message:"Internal Server Error"
        });
    }


})



router.get("/platinum/discount/:productId", async(req , res)=>{
    try{
        const{productId} = req.params;
        const{userId} = req.user.id;
        const [user , product] = await Promise.all([
            await User.findById(userId),
            await Product.findById(productId)
        ]);

        if(user.credits - (product.price*0.2) < 0){
            return res.status(400).json({
                success:false,
                message:"Insufficient credits"
            });
        }
        const discountedPrice = product.price-(product.price*0.2);
        user.credits -= (product.price*0.2);
        await user.save();
        res.status(200).json({
            success:true,
            data:{
                originalPrice:product.price,
                discountedPrice
            }
        });

    }catch(err){
        console.error(err);
        res.status(500).json({
            success:false,
            message:"Internal Server Error"
        });
    }


})






module.exports = router;
