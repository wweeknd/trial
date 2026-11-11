
import React, { useState } from "react";

function App() {
    const [task, setTask] = useState("");
    const [tasks, setTasks] = useState([]);

    function addTask() {
        if (task === "") return;
        setTasks([...tasks, task]);
        setTask("");
    }

    function deleteTask(i) {
        setTasks(tasks.filter((_, index) => index !== i));
    }

    return (
        <div>
            <h1>TODO App</h1>
            <input value={task}
                onChange={e => setTask(e.target.value)} />
            <button onClick={addTask}>Add</button>

            {tasks.map((t, i) => (
                <p key={i}>
                    {t}
                    <button onClick={() => deleteTask(i)}>
                        Delete
                    </button>
                </p>
            ))}
        </div>
    );
}

export default App;


// GitHub Deployment
// First push the project to GitHub:
// git init
// git add .
// git commit -m "TODO App"
// git branch -M main
// git remote add origin https://github.com/USERNAME/todo-app.git
// git push -u origin main