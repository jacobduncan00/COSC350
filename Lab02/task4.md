# Task 4

### 1. Invoke ls with a non-existent filename. You should see the error output on the screen. Do it again, but redirect the error output to a file named bar. Write down exactly how you did this.

ls test 2> foo

### 2. Do it again, but redirect the error output to the "gone forever" file /dev/null. Write down exactly how you did this.

ls test 2> /dev/null

### 3. Create a file named foo by echo-ing the numbers 3,5,2,1 into it, one number per line. Write down exactly how you did this.

echo 3 >> foo | echo 5 > foo | echo 2 > foo | echo 1 > foo

### 4. Create a file named bar by cat-ing foo into it. Write down exactly how you did this. (Yes, cp would also work, but this lab exercise is about redirection.)

cat foo >> bar

### 5. Redirect input from foo (it contains numbers, right?) to the sort function. You should see the sorted numbers on the screen. Write down exactly how you did this. Did the numbers turn out sorted numerically? If not, explain how the sort was done.

sort < foo
Yes the numbers came out sorted numerically
Output:
1
2
3
5

### 6. Do it again, but redirect the output from the screen into the file bar. Write down exactly how you did this.

sort < foo > bar
