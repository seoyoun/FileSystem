Lab 5 Readme
----------------------------------------------------------------------------------------------------------------------------------------------
Group members: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
----------------------------------------------------------------------------------------------------------------------------------------------
Contributions: 
Yanpeng Yuan:
-Cat command
-Display command
-Bonus Grep command
Ziwen Wang:
-LS command
-Remove command
-Password Touch command
-Readme
Sally Lee:
-Copy command
-Macro command
-Rename command
----------------------------------------------------------------------------------------------------------------------------------------------
Erros and bugs:
No erros or bugs
----------------------------------------------------------------------------------------------------------------------------------------------
Tests:
LS command: We added 3 files, 1.txt, 1.img and 2.txt in advance. Both "ls" and "ls -m" are tested. Output:
$ ls
1.img               1.txt
2.txt
$ ls -m
1.img               image     9
1.txt               text      4
2.txt               text      10

Remove command: We tried to remove 1.img and used "ls" to show the file is removed successfully. Output:
$ ls
1.img               1.txt
2.txt

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ rm 1.img

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls
1.txt               2.txt

Password: We created a new file, pass.txt, by using "touch pass.txt -p". Output:
$ touch pass.txt -p
What is the password?
1234

Cat command: Tested for appending, and overwriting to both image and text files. Special cases such as multiple consequtive newline characters(\n) and special symboles also tested. Image files are tested to make sure they can not be used for the append option.

Display command: Tested for both image and text files, with and without -d command. Files while special contents such as one with special characters are also tested and made sure to be working.

Copy command: We first created a file and wrote to it. Then we made a copy of that file. There was the same content in the copy and writing to the copy did not affect the original file. Output:








----------------------------------------------------------------------------------------------------------------------------------------------
Bonus section:
Implemented grep command using the visitor pattern. Created the grep Visitor class. Essentially, each txt file is converted to string, and we match the query to see if its a substring of any of the files. The meta data of the matching files will be returned.
Some tests are: checking to see that the search works properly for regular inputs, and inputs with spaces. Image files are not searched. 
Note: grep will not work of the entry is on multiple lines in the text document, no instruction regarding this have been provided so I just left it as it is. 