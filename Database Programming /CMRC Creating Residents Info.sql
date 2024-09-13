-- This database is for our Apartment Database for CMRC . This tracks the name of the resident, their room number 
-- and how much they owe
-- The first iteration will be five resident 
-- Adding five residents and querying them 

-- Accessing the database 
USE CMRC; 

-- Double checking my table does not exist 
SHOW TABLES; 

-- Creating the table that tracks resients Name, amount owed, and room number 
CREATE TABLE Residents (
	ResidentName varchar(255),
    AmountOWed int,
    RoomNumer varchar(5)
);

-- Adding residents to the table 
INSERT INTO Residents (ResidentName, AmountOwed, RoomNumer)
VALUES( 'Eddy Koundjou', '1865', '1A');

INSERT INTO Residents (ResidentName, AmountOwed, RoomNumer)
VALUES( 'Jermia Travers', '2000', '1B');

INSERT INTO Residents (ResidentName, AmountOwed, RoomNumer)
VALUES( 'Jada Danner', '0', '1C');

INSERT INTO Residents (ResidentName, AmountOwed, RoomNumer)
VALUES( 'Uzochi Anaele', '100', '4C');

INSERT INTO Residents (ResidentName, AmountOwed, RoomNumer)
VALUES( 'Aron Bishop', '1875', '3A');

-- Seeing how our table looks 
SELECT * FROM Residents; 
