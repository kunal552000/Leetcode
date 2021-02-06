/*

Query the list of CITY names from STATION that do not start with vowels. Your result cannot contain duplicates.

*/

/* CODE */

select distinct CITY from STATION where CITY REGEXP"^[bcdfghjklmnpqrstvwxyz]";