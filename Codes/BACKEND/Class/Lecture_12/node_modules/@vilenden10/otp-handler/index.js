let otp = "";

function generateOtp(len){
    try{
        let otp = "";
        for(let i = 0 ; i < len ; i++){
            otp += Math.floor(Math.random() * 10);

        }
        return otp;

    }catch(error){
        throw error;
        
    }

}


function verifyOtp(userOtp){

    try{
        if(userOtp == otp){
            return true;
        } 
        throw new Error("Invalid OTP");

    }catch(error){
        throw error;

    }

}

module.exports = {
    generateOtp,
    verifyOtp
}