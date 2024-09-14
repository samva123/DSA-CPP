
// const express = require('express');
// const app = express();

// app.listen(8000,() => {
//     console.log("server started heloo ")
// });

// app.get('/',(req,res) => {
//     res.send("hello jee kya haal chaal");
// })  

// app.post('/api/cars',(req,res) =>{
//     const{name,brand} = request.body;
// console.log(name);
// console.log(brand);
// response.send("car submitted");

// })

//const mongoose = require('mongoose');

// const connectDB = ()=>{
//     // mongoose.set('strictquery' ,true);
// // mongoose.set('useNewUrlParser', true);
//  mongoose.connect('mongodb://127.0.0.1:27017'
//     // useNewUrlParser : true,
//     // useUnifiedTopology:true,

// )
// .then(() => {console.log("connection s ");
// })
// .catch((err) => {console.log("error");
// });
// }

// module.exports = connectDB;
// const mongoose = require('mongoose');
// const url = "mongodb://127.0.0.1:27017/mydatabase";

// mongoose.connect(url).then(() => {
//     console.log(" DB connection successful");
// }).catch((err) => {
//     console.log("Not Connected to Database ERROR! ", err);
// });

//app create
const express = require("express");
// const cors = require('cors');
const app = express();

// access environment variables 
require("dotenv").config();
const PORT = process.env.PORT || 3000;

//adding middleware
app.use(express.json());
// app.use(cors());

const fileupload = require("express-fileupload");
app.use(fileupload({
    useTempFiles : true,
    tempFileDir : '/tmp/'
}));



//connect to the database
const dbConnect = require("./config/database");
dbConnect();



// connecting to Cloudinary
const cloudinary = require("./config/cloudinary");
cloudinary.cloudinaryConnect();

// Mounting Routes
const Upload = require("./routes/FileUpload");
app.use('/api/v1/upload', Upload);

// Activating Server
app.listen(PORT, () => {
    console.log(`App is running at PORT ${PORT}`);
})







