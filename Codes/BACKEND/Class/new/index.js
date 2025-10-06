const express = require('express');
const app = express();
const PORT =  3000;

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

const userRouter = require('./routes/user.route');
const postRouter = require('./routes/post.route');
const { post } = require('./prisma/client');

app.use('/user', userRouter);
app.use("/post",postRouter);

app.get('/', (req, res) => {
    res.send('Welcome to the User Management API');
});

app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});