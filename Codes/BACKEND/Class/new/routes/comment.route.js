const express = require('express');
const router = express.Router();
const prisma = require('../prisma/client');

router.post('/create', async (req, res) => {
    try {
        const { comment , postId , userId } = req.body;
        const post = await prisma.comment.create({
            data: {
                comment,
                PostId: postId,
                authorId: userId,
            },
        });
        res.status(201).json(post);
    } catch (error) {
        console.error('Error creating comment:', error);
        res.status(500).json({ error: 'An error occurred while creating the comment.' });
    }
});
module.exports = router;