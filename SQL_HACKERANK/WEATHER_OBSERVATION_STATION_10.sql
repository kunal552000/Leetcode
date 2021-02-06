/*

Query the list of CITY names from STATION that do not end with vowels. Your result cannot contain duplicates.

*/

/*CODE*/

select distinct CITY from STATION where CITY REGEXP "[qwrtyplkjhgfdszxcvbnm]$";