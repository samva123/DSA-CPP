const express = require("express");
const connectDB = require("./db/connectDB");
const app = express();
const PORT = process.env.PORT ;
require("dotenv").config();
const routerPath = require("./routes/auth.route")

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.use("/",routerPath);

connectDB().then(() => {
  app.listen(3000, () => {
    console.log(`Server is running on port ${PORT}`);
  });
}).catch((error) => {
  console.error("Database connection failed:", error);
});
