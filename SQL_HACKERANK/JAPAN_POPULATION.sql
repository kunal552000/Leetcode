/*

Query the sum of the populations for all Japanese cities in CITY. The COUNTRYCODE for Japan is JPN.

*/

/* CODE */

select sum(population) from CITY where countrycode = "JPN";