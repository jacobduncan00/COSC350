# Task 5

### 1. Create a file named numbs that contains the integers 1 through 100, one integer per line. The file will have 100 lines. Write down a short description of how you did this. (You can do it any way you want, including dumb brute force. You might also want to consider the bash for loop or a small C++ program.)

I did this by using the seq command. The sequence command takes a starting number and an ending number and iterates through. Then I redirected that output and put it into a file called numbs.

Command: seq 1 100 > numbs

### 2. Run wc on the file numbs. Write down the output and your explanation of what it means. Check the man page for wc if you're not sure.

wc numbs
100 100 292 numbs

100 = number of words
100 = number of lines
292 = number of bytes
numbers = name of file

### 3. Use pipes and redirection to produce a second file named somenumbs that contains lines 25 through 38 of numbs. Write down exactly what you did.

sed -n '25,38p' numbs >> somenumbs
-n makes it to where it the numbers are not printed to the terminal

### 4. Run wc on the file somenumbs. Write down the output and your explanation of what it means.

wc somenumbs
14 14 42 somenumbs

14 = number of words
14 = number of lines
42 = number of bytes
somenumbs = name of file
