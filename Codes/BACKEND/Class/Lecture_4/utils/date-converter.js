// function formatDate(date){
//     let formatedDate = new Date(date).toLocaleDateString();
//     return formatedDate;
// }

// function anotherFormat(date){
//     let formatedDate = new Date(date).toLocaleDateString("en-US", {
//         year: 'numeric',
//         month: '2-digit',
//         day: '2-digit'
//     });
//     return formatedDate;


// }

// module.exports = {formatDate, anotherFormat};


module.exports.formatDate = function (date) {
    let formatedDate = new Date(date).toLocaleDateString();
    return formatedDate;
}

module.exports.anotherFormat = function (date) {
    let formatedDate = new Date(date).toLocaleDateString("en-US", {
        year: 'numeric',
        month: '2-digit',
        day: '2-digit'
    });
    return formatedDate;
}