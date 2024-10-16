import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import React from 'react'
import App from './App.jsx'



function MyApp(){
  return(
    <div>
      <h1>hello ji</h1>
    </div>
  )
}


// const reactElement = {
//   type: 'a',
//   props:{
//       href: 'https://google.com',
//       target: '_blank'
//   },
//   children: 'CLick me to visit google'
// } // this code is not running because we wrote it for our custom rendering 


const anotherElement = (
  <a href="https://google.com" target='_blank'>Visit us</a>

) // and this worked becuase this is according to react rendering

const anotherUser = "chai hai ji"


const reactElement = React.createElement(
  'a',
  {href: "https://google.com",
    target: "_blank"
  },
  'CLick to visit google',
  anotherUser
) // this will also work because it is react syntax




createRoot(document.getElementById('root')).render(
  
   
    // reactElement
    // anotherElement
    <App/>
    
    
    
  
)
