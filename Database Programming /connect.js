var mysql = require('mysql');

var con = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "Jumpman17!",
  database: "todoapp"
});

con.connect(function(err) {
  if (err) throw err;
  console.log("Connected!");
});