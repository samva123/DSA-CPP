"use client"
import { useParams } from "next/navigation";


// export default({params})    =>{

//     const {id} = params;

//     return <>
//         <h1>Student Info Page  {id}</h1>
//     </>
// }


export default ()=>{
    //const router = useRouter();
    const {id} = useParams();

    return <>
        <h1>Student Info Page  {id}</h1>
    </>
}