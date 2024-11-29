
![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/py43wyd25jfy01lk8ddk.png)

## Problem Statement

You are given an `m x n` grid grid where:

- '.' is an empty cell.

- '#' is a wall.

- '@' is the starting point.

Lowercase letters represent keys.
Uppercase letters represent locks.

You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some `1 <= k <= 6`, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys. If it is impossible, return `-1`.

## Example

**Example 1**

Input: grid = ["@.a..","###.#","b.A.B"]
Output: 8
Explanation: Note that the goal is to obtain all the keys not to open all 
the locks.

**Example 2**

Input: grid = ["@Aa"]
Output: -1

## Problem Explanation

In the problem we are given a maze 𝄜 which consists of some locks 🔒and their corresponding keys 🔑, some walls 🧱 , empty spaces ▫ and a starting point @. The walls are denoted by ‘#’ . Keys are lowercase letters (‘a’ to ‘f’) and locks are uppercase letters corresponding to keys. Empty spaces are denoted by ‘.’ and starting point is denoted by ‘@’.
 
Our task is to find all the keys in the minimum moves possible. We can’t go through a wall and if it not possible to collect all the keys then our answer will be -1.

Now the question is how we can take moves such that we can collect all the keys and the moves are minimum? ❓

To understand this let’s look at our Example 1 -:

Input: grid = ["@.a..","###.#","b.A.B"]
Output: 8
Explanation: Note that the goal is to obtain all the keys not to open all 
the locks.

![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/i6etj8d2w3q8kf0peebg.png)
Now you can see that our guy 👨 starts from (0,0) and as per our problem he can move in four different directions **_up_**, _**down**_, _**left**_ and **_right_**. We know that from (0,0) going in up and left direction is not possible 💁‍♂️ and he can’t go down as wall is there. So now he will just move in right direction. So his new position is (0,1). Now from this position again he can go in four different directions and **these different paths are going to give him different answers and our concern is to get minimum out of these also he is not going to visit the cells he has come from** because this can make him go round about and he will never be able to get keys.
So from (0,1) he will go to right cell (0,2), you know why 🙂.
Now you can see that he finds a key 🔑 so he will simply keep it with himself and will move forward. Again he will go to right cell i.e. (0,3). From this cell he can either go right or he can go down. If he goes to right (0,4) now he can’t go anywhere, so going right will not give any answer to us.
Let’s go down (1,3) and from here again he can go in four different directions.
So doing this again and again will surely lead to our answer.

But wait 😶, there’s a catch here it is not as easy as it seems here 🫨.

You can see that from a given cell we are going on four different cells (four directions) and each cell is giving us a different answer because each cell leads to different path. Now this is very important statement here “each cell leads to different path”. Why? 🤔

Suppose we have another grid -:
grid=["@...a",".###A","b.BCc"]

![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/kwsq8fno1fll474hc63f.png)
So here we have two different paths possible from (0,0) one from right and other from down. And also we can take key ‘a’ in two different ways.
One way is moving only in right direction from (0,0) and other path is ‘(0,0) -> (1,0) -> (2,0) -> (2,1) -> (2,0) -> (1,0) -> (0,0) -> (0,1) -> (0,2) -> (0,3) -> (0,4)’. Huh 😵? But we can’t trace the path we have visited before then how is this path possible 😵‍💫?

The path is possible because while returning our guy has one more thing with him and that is the ‘bth key’ and hence this makes all the difference 🤯.
Problem says to get all keys in minimum moves so following differnt paths will give us different number of moves and different number of keys.
For example following the below path will give us answer -1.

![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/hr6uqs01bia8cg19leud.png)
But following this path will give us 10 moves.
![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/9vx0amf8mvv8tgb68um1.png)
With each move guy’s position and keys he collected from a given path and total moves he took is associated. So this is why we are tracing back to the path which we followed earlier but this time with 1 key acquisition.

So this was complete problem explanation. Now let’s head to solution of the problem.

## Solution

Now we know that the most important part of the problem is the state of each cell in path is (position,keys,steps). And our task is to find the minimum number of moves to collect all the keys.

So we can use **Breadth First Search** here. Why BFS?

Because BFS sees all the possible cells of a given cell first before moving to next level and this ensures shortest path possible.

We will make a queue that will contain {initial position of guy,keys he collected,total moves}. So for our example 1 the element in queue will be {0,0,0,0} (0th row, 0th column, bitmask for key, total moves).
Now you might be wondering why we have taken bitmask here? 🤔

Look at the problem carefully we have locks too of corresponding keys so using bitmask when we encounter a lock we can ensure that we have already collected the key related to that lock. **So in short bitmask will help us in identifying which key we have collected so far.**

So using queue we will see all the paths possible and will get answer when any one of the path gives us all the keys. 💁‍♂️

## Code

![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/q3reyh61sc1mc9vxielw.png)
Here ’n’ denotes the number of rows in grid and ‘m’ denotes the number of columns in grid. Also ‘dir’ denotes the directions we can move in.

![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/d257m7ggywdkyj9i2ifk.png)
So here I have defined a ‘vis’ vector it will keep track of visited path. Note that here we have stored position (row,col) and bitmask in visited array. We have taken size of this array as n*m*64. We have taken 64 because our bitmask can go upto 2⁶-1 as our keys are represented by 6 different letters.
Then I traversed the grid to get the starting position of guy and total number of keys. After this I have made a queue in which I pushed starting position of guy, bit mask and total moves.

`while(q.size() > 0)
{
     int row = q.front()[0];
     int col = q.front()[1];
     int mask = q.front()[2];
     int steps = q.front()[3];

     q.pop();

     int req_ans = pow(2,keys);
     if(mask == (req_ans-1)) return steps;

     for(int i = 0 ; i < dir.size() ; i++){
         int r = dir[i][0]; int c = dir[i][1];
         if(isValid(row+r,col+c) == true)
         {
              if(grid[row+r][col+c] == '.'){
                   if(vis[row+r][col+c][mask] == false){
                        vis[row+r][col+c][mask] = true;
                        q.push({row+r,col+c,mask,steps+1});   
                   }
              }
              else if(grid[row+r][col+c] == '#'){
                   continue;
              }
              else if(grid[row+r][col+c] == '@'){
                   if(vis[row+r][col+c][mask] == false){
                        vis[row+r][col+c][mask] = true;
                        q.push({row+r,col+c,mask,steps+1});   
                   }
              }
              else if(grid[row+r][col+c] >= 'a' and grid[row+r][col+c] <= 'z'){
                   if(vis[row+r][col+c][mask] == false){
                        vis[row+r][col+c][mask] = true;
                        int updated_mask = mask | (1 << (grid[row+r][col+c]-'a'));
                        q.push({row+r,col+c,updated_mask,steps+1});    
                   }
              }
              else{
                   if(vis[row+r][col+c][mask] == false){
                       char lock = (grid[row+r][col+c]);
                       char key = tolower(lock);
                       int found = (mask & (1 << (key - 'a'))); 
                       if(found > 0) q.push({row+r,col+c,mask,steps+1});   

                       vis[row+r][col+c][mask] = true;
                   } 
              } 
         }
     }
}`
Here we have our code for BFS. We take the front entry of queue if this entry has all keys then we return the steps. Otherwise we go in different directions. Now going in different directions can possibly lead us to a wall, empty space, lock, key or out of grid. So we have to check each of the case. Also we need to ensure that the next state we are visiting is not seen before.

- When we encounter a lock we will check our bitmask is having its key or not. If present we will push this entry in queue.

- When we encounter a key we will update our mask and we will push this entry in our queue.
Note that following the steps we can visit some cells again but these cells must have different state.

![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/2mg9iede3irkllc87tae.png)
