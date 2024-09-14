/*
	Working through queries I learned through Harvard CS50. 
    Commands should be to commented to  run the next commands
*/

-- Checking to see which database I can use 
SHOW DATABASES;

-- Using the database: CMRC 
USE CMRC;

-- Checking to see which tables I can use 
SHOW tables;

-- Querying everything from the table: Residents 
SELECT * 
FROM Residents;

 -- selecting a list of residents from residents
SELECT ResidentName 
FROM Residents;

-- Using the limit command 
SELECT ResidentName
FROM residents
LIMIT 3; 

-- Using the where command 
SELECT ResidentName, amountOWed
FROM residents
WHERE amountOWed > 0;

-- Using the NULL command 
SELECT residentName, amountOWed 
FROM residents 
WHERE amountOWed IS NOT NULL;

-- using the LIKE command
SELECT ResidentName, RoomNumer
FROM residents
WHERE RoomNumer LIKE '1%';

-- Using RANGES 
SELECT ResidentName, amountOWed
FROM residents
WHERE amountOWed BETWEEN 1000 AND 2000;

-- Using Order By
SELECT residentName, roomNumer
FROM residents
ORDER BY roomNumer 
ASC LIMIT 5;
 
-- Using MAX command
SELECT MAX(amountOWed) 
FROM residents; 