studio 19 answers here
1. Ziwen Wang, Yanpeng Yuan, Sally Lee
2. We first create an img file object and print out its contents using "read" function, it prints out nothing because the contents is empty. Then we write a vector containing a string of Xs into the object and print
it again, it prints out:
X   X   X   X   X
as expected.
3. We call "accept" method on a file object passing a pointer to a visitor as a parameter. Inside "accept" method, we call "visit_xxx" (specific file type) on the visitor. Then "read" method is called on the object and its contents is printed out.
4. The member function is "read" and the receiver is the file object, the sender is the visitor.
5. We need to define a "visit_xxx" method for every single type of file. Thus if we have too many types of file, it would be redundent to define all corrosponding visit methods in each concrete visitor class.