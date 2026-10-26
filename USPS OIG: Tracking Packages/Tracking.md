Using data analyst skills (Python, SQL, Oracle) to track packages

Will need to generate a database that use 20 addresses

Database structure
     Name, Address, City Zipcode


This project, "A Model-Based Systems Engineering Approach to Mitigating Porch Piracy," serves as a comprehensive case study in modern systems design and data analysis. It addresses the real-world challenge of package theft through a dual-pronged strategy: a proactive system design and a reactive data analysis pipeline.

I followed a formal MBSE lifecycle to structure this learning path:

System Architecture & Design (MBSE): Using SysML, I created a formal model for a secure smart locker network. This model includes requirements, system architecture (Block Definition Diagrams), and use cases to define a proactive solution for preventing theft.
Data Engineering & Persistence: To handle the reactive analysis of theft incidents, I designed and implemented a relational database schema using MySQL. This database serves as the central repository for incident reports.
Data Analysis & ETL: I developed an analysis pipeline using Python and the Pandas library. This script connects to the MySQL database, extracts the incident data via SQL queries, performs transformations, and runs analysis to identify key metrics and trends, such as theft hotspots by zip code.
Also include spark, Apache hop
This end-to-end project demonstrates a full-lifecycle approach to problem-solving, integrating formal systems design with practical data engineering and analysis.