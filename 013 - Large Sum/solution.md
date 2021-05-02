The challenge in this problem comes from not be able to store the integers in a conventional number data type. 
Some language can now deal with these number sizes, but let's deal with the problem with our standard data types and structures.

Implement the standard addition algorithm that you would usually use on large numbers on paper. 
For each digit place, add the digits in the same place together plus any carry term from the previous place.
Put the digit in the ones place into the digit place in the final sum and carry the rest of the value to the next place.

Some sort of linear data structure will suffice, though the way you add and access elements will vary depending on your implementation.

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/013%20-%20Large%20Sum/solution.cpp)
