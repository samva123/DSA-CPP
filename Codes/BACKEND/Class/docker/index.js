const express  =  require("express");
const app = express();
const client =  require("./client");
const PORT = 3000;

app.use(express.json());
app.use(express.urlencoded({extended:true}));


app.get("/" , async(req,res)=>{
    try{
        const res1 = await client.set("user:11","test 2","nx");
        console.log(res1);
        const data = await client.get("user:11");
        const datas = await client.mget()
        res.json({data});

    }catch(error){
        console.log(error);
    }
    
});

app.listen(PORT , ()=>console.log("chal pada"));
