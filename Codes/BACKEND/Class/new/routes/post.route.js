const express = require('express');
const router = express.Router();
const prisma  = require('../prisma/client');
const { skip } = require('@prisma/client/runtime/library');
const e = require('express');

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
        },
                //orderBy: { createdAt: 'desc' }


        });
        
        res.status(200).json(allPosts);
    }catch(error){
        res.status(500).json({ error: "Internal Server Error" });
        console.error(error);
    }
})


router.get("/pagination", async(req,res)=>{
    try{
        const {page = 0, limit = 20} = req.query;
        const skipCount = (page-1) * limit;
        const posts  =  await prisma.post.findMany({
            include:{
                author: true,
                comments: true
            },
            take:Number(limit),
            skip: skipCount,
        })
        res.status(200).json(posts);

    }catch(error){
        res.status(400).json({message : error.message});
        console.error(error);

    }
})
module.exports = router;