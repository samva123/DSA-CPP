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
module.exports = router;