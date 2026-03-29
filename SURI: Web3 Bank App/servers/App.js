/*
    This is a server for our banking application
*/

//Using the http library from JS
const http = require('http')
const port = 3000 //listening to port 3000

//creating the server 
const server = http.createServer(function(req,res) {
    res.write("Hello Node")
    res.end()
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