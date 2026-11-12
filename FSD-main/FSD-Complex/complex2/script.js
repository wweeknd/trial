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
