const http = require("http");

const host = 'localhost';
const port = 8000;

const books = JSON.stringify([
    {title: "Boulder", author: " Eva Baltasar", year: 2020 },
    {title: "Whale", author: "Cheon Myeong-kwan", year: 1923 },
    {title: "The Gospel According to the New World", author: "Maryse Conde", year: 2021},
    {title: "Standing Heavy",author: "Gauz" , year: 2014},
    {title: "Time Shelter", author: "Georgi Gospondinov", year: 2020},
    {title: "Is Mother Dead", author: "Vigdis Hjorth", year: 2020}
]);

const authors = JSON.stringify([
    { name: "Eva Baltasar", countryOfBirth: "Spain", yearOfBirth: 1978 },
    { name: "Kahlil Gibran", countryOfBirth: "South Korea", yearOfBirth: 1964},
    { name: "Maryse Conde", countryOfBirth: "Guadeloupe", yearOfBirth: 1934},
    { name: "Gauz", countryOfBirth: "Ivory Coast", yearOfBirth: 1971},
    { name: "Georgi Gospondinov", countryOfBirth: "Bulgaria", yearOfBirth: 1968},
    { name:  "Vigdis Hjorth", countryOfBirth: "Norway", yearOfBirth: 1959}
]);

const requestListener = function (req, res) {
    res.setHeader("Content-Type", "application/json");
    switch (req.url) {
        case "/books":
            res.writeHead(200);
            res.end(books);
            break
        case "/authors":
                res.writeHead(200);
                res.end(authors);
                break
        default:
                    res.writeHead(404);
                    res.end(JSON.stringify({error:"Resource not found"}));
    }
};

const server = http.createServer(requestListener);
server.listen(port, host, () => {
    console.log(`Server is running on http://${host}:${port}`);
});