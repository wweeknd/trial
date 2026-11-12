[# trial](https://github.com/ksg848750-cyber/fsd)
weather
index.html
<!DOCTYPE html>
<html>
<head>
    <title>Weather App</title>

    <style>
        body {
            text-align: center;
            font-family: Arial;
            background: lightblue;
        }

        .box {
            background: white;
            margin: 50px auto;
            padding: 20px;
            width: 300px;
        }

        input, button {
            padding: 10px;
            margin: 5px;
        }
    </style>
</head>

<body>

    <div class="box">
        <h2>Weather App</h2>
        <input type="text" id="city" placeholder="Enter city">

        <button id="searchBtn">Search</button>

        <p id="status"></p>
        <h3 id="location"></h3>
        <p id="temp"></p>
        <p id="desc"></p>
        <p id="humidity"></p>
        <p id="wind"></p>
    </div>

    <script src="script.js"></script>

</body>
</html>





script.js
const API_KEY = "732a5f7185ae0fc059ef30bf861a4e6e";
const URL = "https://api.openweathermap.org/data/2.5/forecast";

async function getWeather() {

    let city = document.getElementById("city").value.trim();
    let status = document.getElementById("status");

    if (city == "") {
        status.innerHTML = "Enter city name!";
        return;
    }

    status.innerHTML = "Loading...";

    try {
        let response = await fetch(
            `${URL}?q=${encodeURIComponent(city)}&appid=${API_KEY}&units=metric`
        );

        if (!response.ok) {
            throw new Error("City not found!");
        }

        let data = await response.json();

        document.getElementById("location").innerHTML = data.city.name;
        document.getElementById("temp").innerHTML = Math.round(data.list[0].main.temp) + "°C";
        document.getElementById("desc").innerHTML = data.list[0].weather[0].description;
        document.getElementById("humidity").innerHTML = "Humidity: " + data.list[0].main.humidity + "%";
        document.getElementById("wind").innerHTML = "Wind: " + data.list[0].wind.speed + " m/s";

        status.innerHTML = "";

    } catch (error) {
        status.innerHTML = "Error: " + error.message;
    }
}

searchBtn.onclick = getWeather;
