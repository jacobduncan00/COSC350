# Task 3

### What are the permissions on the file?

-rw-r--r-- 
This means there are read and write permissions on this file for users

### Who owns the file?

-rw-r--r--   1 jake  staff     0 Sep  8 14:08 foo
As stated above "jake" which is the hostname of my user owns the file

### What group is associated with the file?

-rw-r--r--   1 staff     0 Sep  8 14:08 foo
By using ls -lg I can see that the file belongs to the "staff" group

### Are you in the group?

groups jake
After running the command above and getting the output in the next question, you can see that I am indeed in the staff group

### Write down the name of all the groups you are in

staff everyone localaccounts _appserverusr admin _appserveradm _lpadmin _appstore _lpoperator _developer _analyticsusers com.apple.access_ftp com.apple.access_screensharing com.apple.access_ssh com.apple.access_remote_ae com.apple.sharepoint.group.1

### Make it to where the users group only has executable permissions, show your commands

chmod -rw foo
chmod +x foo

### Attempt to delete the file, write down the command you used and what happened

rm foo
override --x--x--x  jake/staff for foo? 

### Change permissions on ~/foo so you can delete it, then do so. 

chmod +w foo
rf foo


