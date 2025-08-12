const express  = require("express");
const router = express.Router();

router.post("/signup",async (req,res)=>{
    try {
        const {name,email,password} = req.body;
        if(!name || !email || !password) {
            return res.status(400).json({
                success: false,
                error: "Please provide all required fields"
            });
        }
        const hash = await bcrypt.hash(password, 10);
        let user = await User.create({name:name,email:email,password:hash});
        res.status(201).json({
            success: true,
            data: user
        });
    } catch (error) {
        res.status(500).json({
            success: false,
            error: error.message
        });
    }
})

module.exports = router;
