# Plus

The problem is fairly straightforward. Read and sort N names. Then, print the value of each query. 

Converting a name to a score simply requires iterating through each letter, determining the value, and summing up all the values.

How should we deal with query, i.e., how to find the rank of a given name?

### Straightforward

Iterate through the sorted names to find the query name and return the index. O(n)

### Binary Search

Instead of iterating, we can binary search since the names are sorted. O(log n)

### Hashmap

Create a hashmap with the name as key and rank times score as value. Then, we can populate our hashmap by iterating through the sorted names.
```
#include <unordered_map>
...
unordered_map<string, int> name_scores;
for (int i = 0; i < N; i++) {
    int score = getNameScore(names[i]);
    name_scores[names[i]] = (i+1)*score;
}
```

This requires O(n) extra space, but achieves amortized O(1) time.

[Solution](https://github.com/zhaohanson1/project_euler_plus/blob/master/022%20-%20Names%20scores/solution-plus.cpp)

# Classic

Straightforward: read all names from file, sort, iterate and calculate rank times score, return sum
