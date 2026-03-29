/*
    This is a server for our banking application
*/

//Using the http library from JS
const http = require('http')
const fs = require ('fs') // file handling import
const port = 3000 //listening to port 3000

//creating the server 
const server = http.createServer(function(req,res) {
    res.writeHead(200, {'Content-Type': 'text/html'})
    fs.readFile('index.html', function(error, data) {
        if (error) {
            res.writeHead(404)
            res.write('Error: File Not Found')
        }
        else {
            res.write(data)
        }
        res.end()
    })
})

//Telling our server to listen to port and tell us if there's an error 
server.listen(port, function(error) {
    if (error) {
        console.log("Something went wrong", error)
    }
    else {
        console.log('Server is listening on port ' + port)
    }
})