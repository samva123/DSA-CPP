const  express = require("express");
const app = express();
const PORT = 5000;
const {MongoClient} = require("mongodb");
require("dotenv").config();

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

const client = new MongoClient(process.env.DB_URL);
let userCollection;

async function connectDB(){
  await client.connect();
  const db = client.db("G25");
  userCollection = db.collection("users");
  return 'done';
}

app.get("/", (req, res) => {"server is running"});

app.post("/",async (req,res)=>{
    try{
        const {name,email,password} = req.body;
        const result = await userCollection.insertOne({name,email,password});
        res.status(201).json({result});
    }
    catch(error){
        res.status(500).json({message:"hello ji "})
    }
})

app.listen(PORT, () =>{
  connectDB().then(()=>{
    console.log("db connected");
  }).catch((err)=>{
    console.log(err);
  })
  console.log("Server running on port " + PORT)
});