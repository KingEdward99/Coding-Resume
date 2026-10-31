# CMRC Room-mate Matching System

A command-line application designed to match college students for potential roommates based on their major and classification.


## Features

-          Create Student Profiles: Interactively create new student profiles with built-in data validation

-          View All Students: Display a list of all students currently in the system

-          Ranked Matching: Calculate and display a ranked list of the best roommate matches for any given student

-          Command-Line Interface: All features are accessible through a simple and clear CLI

 

## Getting Started

 

### Prerequisites

To run this application, you will need the following installed on your system:

-          Python 3.9+

-          Git

 

## Setup and Installation

-          Git clone https://github.com/KingEdward99/Data\Structures\and\Algorithms/Room-mate

-          No further installation is necessary

 

## Usage

This application is run from the command line

 

### To add a new student:

This command will start an interactive prompt to guide you through creating a new profile

 

## Architecture

The system is designed using Object-Oriented principles and consists of two primary classes:

Student and Matcher

-          Student Class: a data class responsible for hold the information for a single student (name, major classification, and a unique ID)

-          Matcher Class: the main application engine. It manages the collection of all Student objects and contains the core matching algorithm