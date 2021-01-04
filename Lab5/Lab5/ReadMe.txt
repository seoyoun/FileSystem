Lab 5 Readme
Group members: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
Contributions: 
Yanpeng Yuan:
-Cat command
-Display command
-Bonus Grep command
Ziwen Wang:
Sally Lee:

Tests:
Cat command: Tested for appending, and overwriting to both image and text files. Special cases such as multiple consequtive newline characters(\n) and special symboles also tested. Image files are tested to make sure they can not be used for the append option.
Display command: Tested for both image and text files, with and without -d command. Files while special contents such as one with special characters are also tested and made sure to be working.








-------------------------
Bonus section:
Implemented grep command using the visitor pattern. Created the grep Visitor class. Essentially, each txt file is converted to string, and we match the query to see if its a substring of any of the files. The meta data of the matching files will be returned.
Some tests are: checking to see that the search works properly for regular inputs, and inputs with spaces. Image files are not searched. 
Note: grep will not work of the entry is on multiple lines in the text document, no instruction regarding this have been provided so I just left it as it is. 