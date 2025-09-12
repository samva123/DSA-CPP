const express =require("express");
const router = express.Router();
const {createAccount,loginAccount,userLoggedIn ,adminSignup,getAllUsers} = require("../controllers/auth.controller");
const jwt = require("jsonwebtoken");
const verifyUser = require("../middleware/verify.middleware");
const verifyAdmin = require("../middleware/verifyAdmin");


router.post("/signup",createAccount);
router.post("/admin/signup",adminSignup);
router.post("/login",loginAccount);
router.get("/check",verifyUser,verifyAdmin,userLoggedIn);
router.get("/info",verifyUser,verifyAdmin,getAllUsers);

module.exports = router;