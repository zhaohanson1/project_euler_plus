### Naive
We can use the code from our "plus" solution and iterate through all numbers from 1 to 1000; modify the code so instead of "hundred", we append "hundred and".  Then, simply count the number of characters for all words.
    
### Improved
We can treat this as a combinatorial problem. Observe the following statements.
    
* The sum of all words from "one" to "nine" is 36.
* The sum of all words from "ten" to "nineteen" is 70.
* The sum of the "-ty" words from "twenty" to "ninety" is 46.
* "hundred" is 7 characters and "thousand" is 8 characters

Then, the following statements follow.
* The sum of all numbers from 1 to 19 is 106.
* The sum of all numbers from 20 to 99 is as follows:
    * Each "-ty" appears 10 times, one for each single digit and one for by itself.
        * (46 * 10) = 460 characters make up all "-ty" words in this range.
    * Each "single digit" word shows up 8 times, which is the number of "-ty" words
        * (36 * 8) = 288 characters make up the "single digit" words in this range
    * A total of 460+288 = 748 characters make up this range
* The sum of all numbers from 0 - 999 is as follows:
    * The last two digits 01 - 99 show up 10 times, one for each "hundred" and one for no "hundred".
           * (748+106) * 10 = 8540 characters
    * For the hundreds place,
        * "single digit" + "hundred" has 9 instances
        * This suffix appears in all numbers from "X00 - X99" => 100 times
        * (36 + 7*9) * 100 = 9900 characters make up this pattern
    * The word "and" shows up in each number larger than 100 and when the number is not divisible by 100.
            * (3 * 99) * 9 = 2673
    * 8540+9900+2673 = 21113 characters
* Finally, add "One Thousand" which is 11 characters.
    * 21113+11 = 21124, which is our answer.
      
