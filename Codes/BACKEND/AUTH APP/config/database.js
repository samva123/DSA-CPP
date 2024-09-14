const mongoose = require("mongoose");

require ("dotenv").config();

const dbConnect = () =>{
    mongoose.connect(process.env.MONGOOB_URL)

    .then(() => {console.log("connection to hona hee tha  ");
})
.catch((error) => {console.log("error");
console.error(error.message);
process.exit(1);
});

}
module.exports = dbConnect;