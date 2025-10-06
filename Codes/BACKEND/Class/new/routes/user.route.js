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
module.exports = router;
