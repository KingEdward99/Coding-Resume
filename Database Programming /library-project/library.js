// Import the mysql2 package
const mysql = require('mysql2');

// Create a connection to the MySQL database
const connection = mysql.createConnection({
    host: 'localhost',      // Your MySQL host (e.g., localhost)
    user: 'root',   // Your MySQL username
    password: '--',  // Your MySQL password
    database: 'student_books' // Your database name
});

// Connect to the database
connection.connect((err) => {
    if (err) {
        console.error('Error connecting to the database:', err);
        return;
    }
    console.log('Connected to the MySQL database.');
});

// Example query to fetch data
connection.query('SELECT * FROM Library_Test', (err, results) => {
    if (err) {
        console.error('Error executing query:', err);
        return;
    }
    console.log('Query results:', results);
});

// Close the connection
connection.end();