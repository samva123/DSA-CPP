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



router.post("/transfer",async(req , res)=>{
    try{
        const {senderId , receiverId , amount} = req.body;
        const transaction  = await prisma.$transaction(async(tx)=>{
            const sender = await tx.user.findUnique({
                where : {id:senderId}
            })
            if(!sender || sender.balance <= amount){
                throw new Error("Insufficient balance")
            }
            await tx.user.update({
                where :{id:senderId},
                data:{balance:{decrement:amount}}
            })

            await tx.user.update({
                where:{id:receiverId},
                data:{balance:{increment:amount}}
            })
            const trns = await tx.transaction.create({
                data:{amount , senderId , receiverId}
            })
            return trns;
        })
        res.status(201).json({transaction});

        
    }catch(error){
        console.log(error);
        res.status(404).json({message:error.message})

    }
})

module.exports = router;
