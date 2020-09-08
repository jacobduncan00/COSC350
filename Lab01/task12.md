# Task 12

### Write down what happens when you invoke rmdir ~/Foo. 

rmdir ~/Foo
rmdir: /Users/jake/Foo: Directory not empty

### Write down a sequence of rmdir commands that would allow removal of the ~/Foo directory and its subdirectory Bar.

rmdir ~/Foo/Bar
rmdir ~/Foo/

### Invoke a single rm command to remove the ~/Foo directory and all its contents (check the man page). 

rm -rf ~/Foo 

