import {useState} from 'react'
import "./App.css"

function App() {

  let [counter , setCounter] = useState(15)

  const username = "Counter Upto 20"
  // let counter = 15

  const addValue = () =>{
    console.log("value added" , counter)
    // counter = counter+1
    if(counter < 20){
      setCounter(counter+1);  

    } 

  }

  const removeValue = () =>{
    console.log("value added" , counter)
    // counter = counter+1
    
  
      if(counter > 0){
        setCounter(counter-1);  
      }

    

  }

  


  return (
    <>
    <h1>Chai aur React |  {username}</h1>
    <h2>Counter Value: {counter} </h2>

    <button onClick={addValue}>ADD {counter}</button>
    <br />
    <br />
    <button onClick= {removeValue}>REMOVE {counter}</button>

    </>
  )// we can not write logic in curly brackets
}







export default App
