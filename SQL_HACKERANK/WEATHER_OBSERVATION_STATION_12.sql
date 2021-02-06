/*

Query the list of CITY names from STATION that do not start with vowels and do not end with vowels. Your result cannot contain duplicates.

*/

/*CODE*/

select distinct CITY from STATION where CITY REGEXP "^[QWRTYPLKJHGFDSZXCVBNM]" AND CITY REGEXP "[QWRTYPLKJHGFDSZXCVBNM]$" order by  CITY;