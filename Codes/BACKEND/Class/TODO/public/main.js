const filterButtons = document.getElementById("filter");

filterButtons.addEventListener("click", (e) => {
    const button =  e.target.id;
    if(!button) return;
    if(button == "all"){
        e.target.className = "active"
    }

    if(button == "active"){
        e.target.className = "active"
    }
    if(button == "completed"){
        e.target.className = "active"
    }
    console.log(button);

    const filterBtns = filterButtons.children;
    for(let btn of filterBtns){
        if(btn.id != button){
            btn.className = "";
        }
    }
})