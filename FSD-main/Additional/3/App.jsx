
import React, { useState } from "react";
import { Line } from "react-chartjs-2";
import "chart.js/auto";

function App() {
    const [temp, setTemp] = useState("");
    const [history, setHistory] = useState([]);

    async function getWeather() {
        const res = await fetch(
            "https://api.openweathermap.org/data/2.5/weather?q=Hyderabad&appid=YOUR_API_KEY&units=metric"
        );
        const data = await res.json();
        if (!res.ok) return alert("Error");
        setTemp(data.main.temp);
        setHistory([...history, data.main.temp]);
    }

    return (
        <div>
            <h1>Weather App</h1>
            <button onClick={getWeather}>Get Weather</button>
            <h2>Temperature: {temp}°C</h2>
            <Line data={{
                labels: history.map((_, i) => i + 1),
                datasets: [{ label: "Temperature", data: history }]
            }} />
        </div>
    );
}

export default App;
