#### Naive
Try out values for a and b with a nested for loop and if a<sup>2</sup> + b<sup>2</sup> = x = c<sup>2</sup> is square and a+b+c = N, compare abc. We should have an end condition, so a > N should be good.

```

a = 1
while a > N:
  for b := 1 to a:
    if sqrt(a^2 + b^2) is an integer:
      c = sqrt(a^2 + b^2)
      if a+b+c = N:
        store largest abc
   a++
```

#### Improvements
Euclid's formula gives a method for generating Pythagorean triples. 

For any arbitary pair of integers m and n, m > n > 0, 

- a = m<sup>2</sup> - n<sup>2</sup>, b = 2mn, c = m<sup>2</sup> + n<sup>2</sup> form a Pythagorean triple. 

By using this method of generation, we can skip all pairs (a,b) that will not form a Pythagorean triple with some integer c.

This formula does not generate all Pythagorean triple, but it will produce all primitive triples. 
(A primitve triple is one where m and n are coprime and both not odd)
To generate more Pythagoren triples, note that ka, kb, kc also form a triple, so we can multiple any primitive triple with any integer k to produce another triple.

Using this information, we want to check if the triple that we generate or any of its multiples sum to N, then we compare its product.

To check if a multiple of a triple sum to N, we can divide the sum of a triple from N and check if it divides evenly.
This is because, 
  <img src="https://latex.codecogs.com/png.latex?%5Cbg_white%20ka&plus;kb&plus;kc%20%3D%20k%28a&plus;b&plus;c%29%20%3D%20N%20%5CRightarrow%20%5Cfrac%7BN%7D%7Ba&plus;b&plus;c%7D%20%3D%20k"/>
  
 Then, the product we check is ka\*kb\*kc.

A bound of N > m > n is sufficient, but tighter bounds can be found.

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/009%20-%20Special%20Pythagorean%20triplet/solution.cpp)

#### Sources

https://en.wikipedia.org/wiki/Pythagorean_triple
