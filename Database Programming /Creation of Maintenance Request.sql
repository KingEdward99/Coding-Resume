/*
	Creating a new table called Maintenance request where 
    the user can put in a maintenance request 
*/

-- Checking to see which database I can use 
SHOW DATABASES;

-- Using the database: CMRC 
USE CMRC;

-- Checking to see which tables I can use 
SHOW tables;

-- Creating a table for the maintenance requests 

CREATE TABLE Maintenance_Request (
requestID int(23),
roomNumber varchar(255),
requestDate varchar(255),
issueDescription varchar(255),
requestStatus varchar(255),
resolvedDate int(23)
);


-- Inserting info into the table 
-- Date is MMDDYY format

INSERT INTO Maintenance_Request (requestID, roomNumber, requestDate, issueDescription, requestStatus, resolvedDate)
VALUES (01, '1A', '09152024', "toilet is clogged", 'open', NULL),
		(02, '3A', '08122024', "AC does not blow cold air", 'closed', 09102024),
        (03, '4C', '08012024', "Need an exterminator for rats", 'closed', 08072024),
        (04, '1C', '09152024', "Stovetop does not work", 'closed', 09162024);


-- Checking to see if the maintenance request has been created 
SELECT *
FROM Maintenance_Request;  