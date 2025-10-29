const express = require("express");
const app = express();
const http = require("http");
const server  = http.createServer(app);
const socket  = require("socket.io");
const io = socket(server);
const PORT  = 5000;


app.use(express.json());
app.use(express.urlencoded({extended : true}));

io.on("connection" , (client)=>{
    console.log("user 1 cnnected ->",client.id);
})

app.get("/" , (req, res) => {
    res.send("server running");
});

app.listen(PORT , ()=>console.log("running" + PORT));