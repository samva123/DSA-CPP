const express = require("express");
const app = express();

//load config from env file
require("dotenv").config();
const PORT = process.env.PORT || 3000;


const cookieParser = require("cookie-parser");
app.use(cookieParser());

//middleware to parse json request body
app.use(express.json());

const user = require("./routes/user");
app.use("/api/v1",user);

//start server
app.listen(PORT, () => {
  console.log(`Server started successfully aatt ${PORT}`);
});

//connect to the database
const dbConnect = require("./config/database");
dbConnect();

//default Route
app.get("/", (req, res) => {
  res.send(`<h1> This is HOMEPAGE baby</h1>`);
});