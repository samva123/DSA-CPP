const User = require("../models/user.model");

async function verifyGold(req,res,next){
    try{
        const userId = req.user.id;
        const user = await User.findById(userId);
        if(!user || user.package !== "gold" && user.package !== "platinum"){
            return res.status(403).json({
                success:false,
                message:"Access denied"
            });
        }
        next();
    }catch(err){
        console.error(err);
        res.status(500).json({
            success:false,
            message:"Internal Server Error"
        });
    }
}


async function verifyplatinum(req,res,next){
    try{
        const userId = req.user.id;
        const user = await User.findById(userId);
        if(user.package !== "platinum"){
            return res.status(403).json({
                success:false,
                message:"Access denied"
            });
        }
        next();
    }catch(err){
        console.error(err);
        res.status(500).json({
            success:false,
            message:"Internal Server Error"
        });
    }
}


module.exports = {
    verifyGold,
    verifyplatinum
};
