# simpleInfluenceNetwork

The Stack is used to find the Influence Network. Each user has some people he/she knows and those people further know other people. So we can calculate how is the most influenced perosn. </br> 
## Input file syntax
1. default file name: test.txt </br>
2. the first line must contain the number of users present </br>
3. the user IDs must be listed in ascending numerical order </br>
4. the user id must be followed by a - </br>
5. friends are separated by commas </br>
6. no space are allowed </br>

## Sample file
9 </br>
1 – 2, 4 </br>
2 – </br>
3 –
4 – 2, 3, 5, 6 </br>
5 – </br>
6 – 7, 8 </br>
7 – 6, 9 </br>
8 – 9 </br>
9 – </br>

## To Compile:
<pre><code>g++ Source.cpp -o main </code></pre>

## To execute:
<pre><code>./main</code></pre>
