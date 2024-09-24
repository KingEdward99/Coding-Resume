/*
	Assignment: Create a database that stores 9 students and the three books they like 
    
    Using queries, your program should do the following:
    1. Produce the first names of the students who belong to the your group, and their group names
    2. Produce a report of students and their book preferences 
    3. Produce the books that the members of your group prefer
*/

-- Already created the database 'student books' that will store the names and books 
SHOW DATABASES;
USE student_books;
SHOW TABLES; 

-- creating the table for storing 
CREATE TABLE students_favorite_books(
	student_id INT,
    student_name VARCHAR(200),
    book_name1 VARCHAR(200),
    book_name2 VARCHAR (200),
    book_name3 VARCHAR (200),
    group_name VARCHAR(200)
); 

-- Inserting the data based on a previous survey 
INSERT INTO students_favorite_books (student_id, student_name, book_name1, book_name2, book_name3,group_name) 
VALUES (002, 'Precious Adewakun', 'Lord of the Flies','1984','The Alchemist', 'Group 2'),
		(003, 'Jared Robinson', 'The Water Dancer', 'The Watchers', 'The Giver', 'Group 3'),
        (004, 'Sydney Brutus', 'Percy Jackson', 'The Trials of Apollo', 'Goldie Vance', 'Group 1'),
        (005, 'Nidra Hayes','The Golden Compass', 'Tales of the Peculiar', 'Goosebumps Horrorland', 'Group 2'),
        (006, 'Eddy Koundjou Yem', 'Roll of Thunder, Hear My Cry', 'Frankenstein', 'The Count of Monte Cristo', 'Group 3'),
		(007, 'Jermia Travers', 'And Still I Rise', 'Love Poems', 'Assata: An Autobiography', 'Group 1'),
        (008, 'Aron Bishop', 'Roots: The Saga of an American Family', 'Aint I A Woman: Black Women and Feminism','The Salt Eaters', 'Group 2'),
        (009, 'Jada Danner' , 'Song of Solomon', 'The Fifth Season', 'Women, Race, & Class', 'Group 3');

-- #1 
SELECT student_name, group_name
FROM student_favorite_books
WHERE group_name = 'Group 3'; 

-- #2
SELECT student_name, book_name1, book_name2, book_name3
FROM student_favorite_books;

-- #3
SELECT student_name, book_name1, book_name2, book_name3, group_name
FROM student_favorite_books
WHERE group_name = 'Group 3'; 