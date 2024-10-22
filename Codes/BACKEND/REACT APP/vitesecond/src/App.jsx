
// import './App.css'
// import Card from './components/Card'

// function App() {

//   let myObj = {
//     username: "hitesh",
//     age: 21
//   }
//   let newArr = [1, 2, 3]

//   return (
//     <>
//       <h1 className='bg-green-400 text-black p-4 rounded-xl mb-4'>Tailwind test</h1>
      
      
//       <Card username="" btnText="click me" />
//       <Card username="hitesh" />
//     </>
//   )
// }


// export default App;



import './App.css'
import Card from './components/Card'

function App() {
  return (
    <>
      <h1 className='bg-green-400 text-black p-4 rounded-xl mb-4'>Tailwind test</h1>
      
      {/* Pass different images as props */}
      <Card 
        username="chaiaurcode" 
        btnText="click me" 
        imgSrc="https://images.unsplash.com/photo-1546961329-78bef0414d7c?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxzZWFyY2h8MTB8fHVzZXJ8ZW58MHx8MHx8&auto=format&fit=crop&w=800&q=60"
      />
      <Card 
        username="hitesh" 
        imgSrc= "https://upload.wikimedia.org/wikipedia/commons/3/3c/Tales_serial.jpg"/>
    </>
  )
}

export default App;






















// import { useState } from "react"


// function App() {
//   const [color, setColor] = useState("olive")

//   return (
//     <div className="w-full h-screen duration-200"
//     style={{backgroundColor: color}}
//     >
//       <div className="fixed flex flex-wrap justify-center bottom-12 inset-x-0 px-2">
//         <div className="flex flex-wrap justify-center gap-3 shadow-lg bg-white px-3 py-2 rounded-3xl">
//           <button
//           onClick={() => setColor("red")}
//           className="outline-none px-4 py-1 rounded-full text-white shadow-lg"
//           style={{backgroundColor: "red"}}
//           >Red</button>
//           <button
//           onClick={() => setColor("green")}
//           className="outline-none px-4 py-1 rounded-full text-white shadow-lg"
//           style={{backgroundColor: "green"}}
//           >Green</button>
//           <button
//           onClick={() => setColor("blue")}
//           className="outline-none px-4 py-1 rounded-full text-white shadow-lg"
//           style={{backgroundColor: "blue"}}
//           >Blue</button>
//         </div>
//       </div>
//     </div>
//   )
// }

// export default App