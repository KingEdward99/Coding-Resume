 /*
 Name: Eddy Koundjou Yem 
 Date: 10/07/2024
 
 This sql script uses the database Movie to create two tables, Movie and Song. It then displays different 
 data based on the various select statements 

 Note: Make sure to comment out the appropriate lines in order for the program to work 
 */
 
 Use Movie; 
 
 -- Creating the table movie 
 create table Movie (
	ID INT AUTO_INCREMENT,
    Title VARCHAR(100),
    Rating CHAR(5) CHECK (Rating IN ('G', 'PG', 'PG-13', 'R')),
    ReleaseDate DATE,
    PRIMARY KEY (ID)
);

-- Inserting movies into the table
INSERT INTO Movie (Title, Rating, ReleaseDate) VALUES

  ('Rogue One: A Star Wars Story', 'PG-13', '2016-12-16'),

  ('Casablanca', 'PG', '1943-01-23'),

  ('The Dark Knight', 'PG-13', '2008-07-18'),

  ('Hidden Figures', 'PG', '2017-01-06'),

  ('Toy Story', 'G', '1995-11-22'),

  ('Rocky', 'PG', '1976-11-21'),

  ('Crazy Rich Asians', 'PG-13', '2018-08-15'),

  ('Bridget Jones\'s Diary', 'PG-13', '2001-04-13'),

  ('Avengers: Endgame', 'PG-13', '2019-04-26');

-- Modifying the select statements to show different data
 
 -- Displaying all the movies
SELECT *
FROM Movie;
 
-- Displaying the total amount of movies in our table 
SELECT COUNT(*) AS total_movies
FROM Movie;

-- Displaying movies with a rating that is PG-13 
SELECT *
FROM Movie
WHERE rating = 'PG-13';

-- Displaying movies in the order of their rating 
SELECT title, rating
FROM Movie
ORDER BY rating;

-- Creating the table songs 
Create Table Song (
ID INT,
Title VARCHAR(60),
Artist VARCHAR(60),
ReleaseYear INT,
Genre VARCHAR(20),
PRIMARY KEY (ID)
);


-- Inserting Songs into the table 
INSERT INTO Song VALUES

  (100, 'Hey Jude', 'Beatles', 1968, 'pop rock'),

  (200, 'You Belong With Me', 'Taylor Swift', 2008, 'country pop'),

  (300, 'You\'re Still the One', 'Shania Twain', 1998, 'country pop'),

  (400, 'Need You Now', 'Lady Antebellum', 2011, 'country pop'),

  (500, 'You\'ve Lost That Lovin\' Feeling', 'The Righteous Brothers', 1964, 'R&B'),

  (600, 'That\'s The Way Love Goes', 'Janet Jackson', 1993, 'R&B'),

  (700, 'Smells Like Teen Spirit', 'Nirvana', 1991, 'grunge'),

  (800, 'Even Flow', 'Pearl Jam', 1992, 'grunge'),

  (900, 'Black Hole Sun', 'Soundgarden', 1994, 'grunge');




-- Displaying songs 
SELECT * 
FROM Song;


-- Displaying the title, artist and ordering it by genre

SELECT Title, Artist, Genre
FROM Song
ORDER BY Genre;



-- Displaying the newest song that came out 
SELECT Title, ReleaseYear
FROM Song
WHERE ReleaseYear = (SELECT MAX(ReleaseYear) FROM Song)