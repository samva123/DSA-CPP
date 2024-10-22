import React, { useState } from 'react';
import './Todo.css'; // Importing the CSS file

function ToDoApp() {
  const [tasks, setTasks] = useState([]);
  const [taskText, setTaskText] = useState('');

  const addTask = (e) => {
    e.preventDefault();
    if (taskText.trim() === '') return;
    setTasks([...tasks, { text: taskText, completed: false }]);
    setTaskText('');
  };

  const deleteTask = (index) => {
    const newTasks = tasks.filter((_, i) => i !== index);
    setTasks(newTasks);
  };

  const toggleComplete = (index) => {
    const newTasks = tasks.map((task, i) =>
      i === index ? { ...task, completed: !task.completed } : task
    );
    setTasks(newTasks);
  };

  return (
    <div className="container">
      <div className="left-pane">
        <h2>Task List</h2>
        <ul>
          {tasks.map((task, index) => (
            <li key={index} className={task.completed ? 'completed' : ''}>
              <input
                type="checkbox"
                checked={task.completed}
                onChange={() => toggleComplete(index)}
              />
              {task.text}
              <button onClick={() => deleteTask(index)}>✖</button>
            </li>
          ))}
        </ul>
      </div>

      <div className="right-pane">
        <h2>I need to...</h2>
        <form onSubmit={addTask}>
          <input
            type="text"
            value={taskText}
            onChange={(e) => setTaskText(e.target.value)}
            placeholder="Enter a task"
          />
          <button type="submit">Add Task</button>
        </form>
      </div>
    </div>
  );
}

export default ToDoApp;
