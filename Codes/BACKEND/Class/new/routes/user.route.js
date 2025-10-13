const express = require('express');
const prisma = require('../prisma/client');
const router = express.Router();

router.post("/create", async (req, res) => {

    try{
        const {name, email} = req.body;
        // const user  = await prisma.user.create({
        //     data: {
        //         name,
        //         email
        //     }
        // });

        const user = await prisma.user.create({
            data: {
                name,
                email,
                posts:{
                    create:{ title: "My First Post", description: "This is the description of my first post"}
                }
            }
        });
        res.status(201).json(user);
    } catch (error) {
        console.error(error);
        res.status(500).json({ error: "Internal Server Error" });
    }
});


router.get("/all" , async (req,res)=>{
    try{
        const allUsers = await prisma.user.findMany({
            include: { posts: true },
            orderBy: { createdAt: 'asc' }
        });
        res.status(200).json(allUsers);
    }catch(error){
        res.status(500).json({ error: "Internal Server Error" });
        console.error(error);
    }
})
module.exports = router;
