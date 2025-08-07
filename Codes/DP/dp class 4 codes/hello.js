// function delay5sec(){
//     let prevTime = new Date().getTime();
//     while(prevTime + 5000 !== new Date().getTime()){}
// }

// delay5sec();
// console.log("Hello, World!");


// setTimeout(() => {
//     console.log("Hello, World!");
// }, 2000);

// setTimeout(() => {
//     console.log("This will run after 3 seconds.");
// }, 3000);

// console.log("This will run immediately.");


// let timer  = setInterval(() => {
//     console.log("This will run every 2 seconds.");
// }, 2000);

// setTimeout(() => {
//     clearInterval(timer);
// }, 5000);

// console.log("This will run immediately.");

// let xhr = new XMLHttpRequest();
// let url  = "https://potterapi-fedeperin.vercel.app";
// xhr.onload = function(data){
//     console.log("Data uploaded successfully.");
//     console.log(JSON.parse(data.target.response));
// }

// xhr.onerror = function(error){
//     console.log("Error uploading data:", error);
// }

// xhr.open("GET", url);

// xhr.send();
// console.log("This will run immediately.");

// let url = "https://potterapi-fedeperin.vercel.app";
// fetch(url)
//     .then(response => {
//         if (!response.ok) {
//             throw new Error("Network response was not ok");
//         }
//         return response.json();
//     })
//     .then(data => {
//         console.log("Data uploaded successfully.");
//         console.log(data);
//     })
//     .catch(error => {
//         console.error("Error uploading data:", error);
//     });



// let url = "https://potterapi-fedeperin.vercel.app";

// axios.get(url)
//     .then(response => {
//         console.log("Data uploaded successfully.");
//         console.log(response.data);
//     })
//     .catch(error => {
//         console.error("Error uploading data:", error);
//     })


const city = "Delhi";
const state = "DL";
const country = "IN";
const limit = 1;
const apiKey = "2b6037a6ffbd66c7689a525c3cd0ffe1";  

const url = `http://api.openweathermap.org/geo/1.0/direct?q=${city},${state},${country}&limit=${limit}&appid=${apiKey}`;

fetch(url)
  .then(response => response.json())
  .then(data => {
    console.log("Geo data:", data);
  })
  .catch(error => {
    console.error("Error fetching geo data:", error);
  });




