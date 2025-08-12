const mongoose  = require("mongoose");
const userSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true
  },
  email: {
    type: String,
    required: true,
    unique: true
  },
  password: {
    type: String,
    required: true,
    select: false
  }
},{
    timestamps: true
});

const User = mongoose.model("User", userSchema);
module.exports = User;

/*
    In the schema, `select: false` for the `password` field means that by default,
    when you query for a User document, the `password` field will not be included
    in the result unless you explicitly ask for it using `.select('+password')`.
*/