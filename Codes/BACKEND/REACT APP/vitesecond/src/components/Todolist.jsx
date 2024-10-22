import React from 'react';


const Todos = [

{
    task: "karle kam",
    iscompleted: "true",
},
{
    task: "karle kam",
    iscompleted: "true",
}
]

const Todolist = () => {
  return (
    <ul>
        {Todos.map((todo)=>(
            return <li>
                {todo.task}
            </li>
        ))}
    </ul>
    
  );
};

export default Todolist;