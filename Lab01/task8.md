# Task 8

### Copy the file ~/.bash_history to the file ~/dotbashhistory. Write down the exact command you used. Copy the file ~/.bash_history to the file ~/dotbashhistory. Write down the exact command you used. 

cp ~/.bash_history ~/dotbashhistory

### Write down the file and directory permissions necessary to successfully copy a file in general. 

A file and directory must have:

- source directory: execute and read permission
- source file: read permission.
- target directory: execute and write permission.
- target file: you don't need any permission since it doesn't exit before you copy it. or write permission if the file exists.

### Invoke the exact command again in an attempt to copy the "source" to the now-existing "destination." Write down how the system handled this. 

Nothing happened, the system handled it by printing no output and continued to copy over already existing information.

### Compare the permissions and date on the original file and the copy. Write down if and how they differ. 

-rw-------   1 jake  staff   7036 Sep  8 10:37 .bash_history
-rw-------   1 jake  staff   7036 Sep  8 18:05 dotbashhistory
They have the exact same permissions

### Write down the cp command you would use to insure that the copy has the same permissions and date as the original. 

You would use the --preserve flag on the cp command
