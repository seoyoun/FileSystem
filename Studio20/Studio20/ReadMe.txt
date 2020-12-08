Studio 20 ReadMe.txt
1. Ziwen Wang, Yanpeng Yuan, Sally Lee
2. Since the PasswordProxy object is the only handle to a file, we need to delete the file object it's pointing to when we destruct the PasswordProxt object, making sure it will not be used anymore.
4. We set the password to be "123". We first call write() and read() to write some contents and print it out. In the terminal we are asked to enter the password twice, and then output:X   X   X   X   X, as expected.
Then we try the accept() to display. After entering the password twice, we have this output on the terminal:
X X
 X
X X
as expected.