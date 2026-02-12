-- This database is for our Apartment Database for CMRC . This tracks the name of the resident, their room number 
-- and how much they owe
-- The first iteration will be five resident 

-- Creating the Database
CREATE DATABASE CMRC;

-- Checking to see if the database was created
SHOW DATABASES;

-- Creating the necessary fields
CREATE TABLE Residents (
ResidentName varchar(255),
AmountOwed int,
RoomNumber varchar(5)
); 

