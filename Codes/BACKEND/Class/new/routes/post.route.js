const express = require('express');
const router = express.Router();
const prisma  = require('../prisma/client');

router.post('/create', async (req, res) => {
    try {
        const { title, description, authorId } = req.body;
        const post = await prisma.post.create({
            data: {
                title,
                description,
                author: {
                    connect: { id: authorId }
                }
            }
        });
        res.status(201).json(post);
    } catch (error) {
        console.error(error);
        res.status(500).json({ error: "Internal Server Error" });
    }
});


router.get('/all' , async(req,res)=>{
    try{
        const allPosts = await prisma.post.findMany({
             include:{
                author: true,
                comments: {include: { author: true }}
        }

        });
        
        res.status(200).json(allPosts);
    }catch(error){
        res.status(500).json({ error: "Internal Server Error" });
        console.error(error);
    }
})
module.exports = router;