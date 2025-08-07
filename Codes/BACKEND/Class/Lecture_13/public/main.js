const container  = document.getElementById("container");

async function getUser(){
    let res  = await axios.get("http://localhost:5000/user");
    let user = res.data.user;
    console.log(user);
    const h2 = document.createElement("h2");
    h2.innerText = `Name: ${user.name}`;


    container.innerHTML = ` <p>Email: ${user.email}</p> <p>Age: ${user.age}</p>`;
    //container.append(h2);
    container.prepend(h2);
}
getUser();