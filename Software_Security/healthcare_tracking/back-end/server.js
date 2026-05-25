//Learning to create servers in javascript with Node.js

const express = require('express');
const app = express();
app.use(express.json());

//timeout middleware
app.use((req, res, next) => {
    req.setTimeout(30000, () => {
        res.status(504).send('Request Timeout');
    });
    next();
});
//Synthetic database
const Database = {
    "user101" : {id:"user101", name: "Wale", role:"patient", height: 68, weight: 150},
    "user102" : {id:"user102", name: "Dave", role:"admin",  height: 72, weight: 180}
};

//Server wide timeout
const server = app.listen(3000, () => console.log('Secure server running on port 3000'));
server.setTimeout(30000);

//Authentication mock
const authenticate = (req,res,next) => {
    //simulating that the requestors is currently logged in 
    req.currentUser = Database["user101"];
    next();
};

//Access control guard
const enforceAccessControl = (req, res, next) => {
    const requestRecordID = req.params.userID;

    //Checking if recordID exists
    const record = Database[requestRecordID];
    if(!record) {
        return res.status(404).json({error: "Record not found."});
    }

    //Check if user is authenticated
    if (!req.currentUser) {
        return res.status(401).json({error: "Not authenticated."})
    }

    //If user is requesting their record AND they are not admin -> block
    if (requestRecordID !== req.currentUser.id && req.currentUser.role !== "admin") {
        return res.status(403).json({
            error: "HTTP 403 Forbidden: Access Control Violation."
        });
    }
    next();
};

//Secure endpoint: The request must pass both authenticate and access control
app.get('/api/healthdata/:userID', authenticate, enforceAccessControl, (req,res) =>{
    const data = Database[req.params.userID];
    if(!data) return res.status(404).json({ error: "Record not found."});
    res.json(data);
});

app.post('/login', (req, res) => {
    const {id} = req.body;

    if (!Database[id]) {
        return res.status(401).json({error: "Invalid credentials. "});
    }
    
    return res.json({message: "Login successful", user: Database[id]});
});

//Global error handler
app.use((err, req, res, next) => {
    console.error(err);
    res.status(500).json({ error: "Internal server error." });
});