/*

Query the list of CITY names from STATION which have vowels (i.e., a, e, i, o, and u) as both their first and last characters. Your result cannot contain duplicates.

*/

/* CODE */

select CITY from STATION where CITY REGEXP "^[aeiou]" and CITY REGEXP"[aeiou]$";