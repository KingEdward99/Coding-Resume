//Learning to create servers in javascript with Node.js

const express = require('express');
const app = express();
app.use(express.json());

//Synthetic database
const Database = {
    "user101" : {id:"user101", name: "Wale", height: 68, weight: 150},
    "user102" : {id:"user102", name: "Dave", height: 72, weight: 180}
};

//Authentication mock
const authenticate = (req,res,next) => {
    //simulating that the requestors is currently logged in 
    req.currentUser = {id:"user101", role: "patient"};
    next();
};

//Access control guard
const enforceAccessControl = (req, res, next) => {
    const requestRecordID = req.params.userID;
    const requestedID = req.currentUser.id

    //IF user is not requesting their own record AND is not admin -> block
    if (requestRecordID !== requestedID && req.currentUser.role !== "admin") {
        return res.status(403).json({
            error: "HTTP 403 Forbidden: Access Control Violation."
        });
    }

    next();
};

//Secure endpoint: The request must pass both authenticate and access control
app.get('api/healthdata/userID', authenticate, enforceAccessControl, (req,res) =>{
    const data = Database[req.params.userID];
    
    if(!data) {
        return res.status(404).json({error: "Record not found."});
    }
    
    res.json(data);

});

app.listen(3000, ()=> console.log('Secure server running on port 3000'));