### Interpreting the input

The most straightforward data structure would be a tree. We create a node for each value and the children of each node is the bottom left and bottom right nodes.

We can build the tree top-down by storing the nodes from the previous, create all nodes for the current row, connect the previous row to the corresponding children of the current row, and setting current row to be the previous node. 

### Naive

Try every single path and return the longest path. This can be done with BFS, checking the path length when we reach the bottom.

The time required for this algorithm is O(# of nodes), which is O(n<sup>2</sup>); triangle shape tells us there are (n(n+1))/2 nodes.

### Improved

We can utilize dynamic programming to improve our runtime to O(depth of triangle) which is O(n). The relation to notice is that the longest path starting from some node is the max of the length of the left path and the length of the right path.

#### Top Down

##### Psudeocode

    function top_down(node):
        if node as been visited:
            return cached answer
        if node is leaf:
            return node.value
        return node.value + max(top_down(node.left), top_down(node.right))

In order for top down to work efficiently, we must cache the function calls that have already occured. There are many ways to do this,
* map each node to an integer and cache each node's return value according to the integer
* map the node object itself to it's return value
* In Python, use functools.lru_cache library

#### Bottom Up

##### Psudeocode
    
    function bottom_up(tree):
        for row := bottom row to root
          if row is bottom:
            each path length is node.value
          else:
            for each node in row:
              path length = node.value + max(node.left's path len, node.right's path len)
        return max path length (calculate in last step in root)

In order for this to work, we need to be able to store the path value somewhere and be able to traverse the tree from the bottom up. Some ways to do this,
* "Preprocess" the tree rows; BFS the tree to get each level and store somewhere
* Reverse the tree building procedure; the children of a node are now the parents
* Storing path value
  * create a new variable in node
  * external mapping for node to path value

#

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/018%20-%20Maximum%20path%20sum%20I/solution.py)
