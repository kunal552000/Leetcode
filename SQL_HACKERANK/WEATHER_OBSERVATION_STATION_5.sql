/*

Query the two cities in STATION with the shortest and longest CITY names, as well as their respective lengths (i.e.: number of characters in the name). If there is more than one smallest or largest city, choose the one that comes first when ordered alphabetically.
The STATION table is described as follows:

*/

/* code */

select CITY, length(CITY) from STATION  order by length(CITY), city asc limit  1;
select CITY, length(CITY) from STATION  order by length(CITY) desc limit  1;