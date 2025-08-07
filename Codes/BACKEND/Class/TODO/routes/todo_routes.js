const express = require("express");
const router = express.Router();
const {createTask,deleteTask , ToggleTaskStatus,getTask } = require("../controllers/todo_controllers");

router.post("/create",createTask);
router.delete("/delete/:id",deleteTask);
router.put("/update/:id",ToggleTaskStatus);
router.get("/search",getTask);

module.exports = router;