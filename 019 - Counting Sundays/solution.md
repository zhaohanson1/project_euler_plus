## Determining Day of the Week

We can use modular arithmetic to determine the day of the week. If we index each day as the distance from the current week's Sunday, then we can quickly calculate the day of the week any number of days before or after the current day. 

For example, if our current day is Monday, then the day of the week 100 days after today would be 

<div align='center'>(1 + 100) = 101 mod 7 &equiv; 3</div>
    
which is a Wednesday.

## Leap Years

A leap year occurs when the year is divisible by 4, unless it is a century year (multiple of 100), then it must be divisible by 400. 

Checking if a year is a leap year is a simple matter of conditional statements. 

To getting the number of leap years before a certain year, we can get the number of years divisible by 4 (our potential leap years), subtract the number of years divisible by 100 (the non-leap century years), then add the number of years divisible by 400 (the leap century years).
We form our statements into the following equation:
    
<div align='center'>
    <a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;\left&space;\lfloor&space;\frac{Y}{4}&space;\right&space;\rfloor&space;-&space;\left&space;\lfloor&space;\frac{Y}{100}&space;\right&space;\rfloor&space;&plus;&space;\left&space;\lfloor&space;\frac{Y}{400}&space;\right&space;\rfloor" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\left&space;\lfloor&space;\frac{Y}{4}&space;\right&space;\rfloor&space;-&space;\left&space;\lfloor&space;\frac{Y}{100}&space;\right&space;\rfloor&space;&plus;&space;\left&space;\lfloor&space;\frac{Y}{400}&space;\right&space;\rfloor" title="\left \lfloor \frac{Y}{4} \right \rfloor - \left \lfloor \frac{Y}{100} \right \rfloor + \left \lfloor \frac{Y}{400} \right \rfloor" /></a> (1)
</div> 

## Full Picture
To get the number of Sundays on the first of a month between two dates, we will iterate through the months between the two dates by starting on the 1st of M1, and add the required number of days to get to the 1st of M1+1, and so on. For each month, we want to check if the day is a Sunday. 

To start, we want to get the day of the week of the month of our first date. To do so, we can count the number of days from 1 Jan 1900 to our date.
    Start by counting the number of leap and non-leap years from 1900 to Y1-1.
    We can do so in constant time from equation (1). Then, calculate the number of days, which is given by
    
    (366 * # of leap years) + (365 * (Y1-1-1900 - # of leap years))
    
We know 1 Jan 1900 is a Monday, so add the above number of days (mod 7) to get the day of the week of 1 Jan Y1.

Then, we will add the days in months up to M1.
We are given Sept, Apr, June, and November has 30 days, the rest have 31 days, except Feb which has 28 days except on leap years where it has 29 days. We can store this information in an array so that we can simply lookup the days in a month by indexing the array.

Iterate through the months from Jan to M1, lookup the number of days, and add those days to our current day of the week (mod 7). Add 1 more day if the month is Feb and the current year is a leap year.

Then, iterate through all months from M1 Y1 to M2 Y2 and add the days as before. During each iteration, we check if the our current day is Sunday and increment our answer count.

At the end of our loop, we can return the count.

## Edge Cases
Two cases we need to be careful
* the first day of the first month not included 
    * In this case, we do not count the 1st month regardless if it starts with as Sunday or not.
* the first month is the same as the last month.
    * In this case, we make sure we end our loop correctly while make sure we count if the month starts on a Sunday.

## Miscellaneous
    
[Zeller's Congruence](https://en.wikipedia.org/wiki/Zeller%27s_congruence) is a formula that calculates the day of week for any calendar date. This can be used instead of counting leap years to get the firs date.

***

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/019%20-%20Counting%20Sundays/solution.py)
