-- This database is for our Scholarship Database. This tracks the name of the scholarship, the amount the scholarship offers, 
-- the date it opens, the date it closes
-- The first iteration will be five scholarships 

-- Creating the Database
CREATE DATABASE Scholarship;

-- Ensuring that it was created successfully 
SHOW DATABASES;

-- creating the needed fields for the database 
CREATE Table Scholarshiplist (
	Name varchar(255),
    Amount int,
    OpenDate varchar(255),
    CloseDate varchar(255)
    );
    
    