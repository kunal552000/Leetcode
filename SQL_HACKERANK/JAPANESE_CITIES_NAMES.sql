/*

Query the names of all the Japanese cities in the CITY table. The COUNTRYCODE for Japan is JPN.
The CITY table is described as follows:

*/

/* CODE */

select NAME from CITY where COUNTRYCODE = "JPN";