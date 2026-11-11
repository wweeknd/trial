
let chart;

function getWeather() {
    let city = document.getElementById("city").value;
    let key = "a95d303da7d48c0a112fb6c26718cd6c";
    let url = "https://api.openweathermap.org/data/2.5/forecast?q=" + city + "&appid=" + key + "&units=metric";

    fetch(url).then(function(response) {
        return response.json();
    }).then(function(data) {
        document.getElementById("weather").innerHTML =
            "City: " + data.city.name +
            "<br>Temperature: " + data.list[0].main.temp + " C";

        let labels = [];
        let temps = [];

        for (let i = 0; i < 5; i++) {
            labels[i] = data.list[i].dt_txt;
            temps[i] = data.list[i].main.temp;
        }

        if (chart) {
            chart.destroy();
        }

        chart = new Chart(document.getElementById("weatherChart"), {
            type: "line",
            data: {
                labels: labels,
                datasets: [
                    {
                        label: "Temperature",
                        data: temps
                    }
                ]
            }
        });
    });
}
