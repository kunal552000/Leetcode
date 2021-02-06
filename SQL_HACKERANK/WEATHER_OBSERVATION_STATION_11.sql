/*

Query the list of CITY names from STATION that either do not start with vowels or do not end with vowels. Your result cannot contain duplicates.

*/

//code

select distinct CITY from STATION where CITY REGEXP "^[qwrtyplkjhgfdszxcvbnm]" or CITY REGEXP "[qwrtyplkjhgfdszxcvbnm]$";