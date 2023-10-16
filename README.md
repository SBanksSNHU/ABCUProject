So when I first started this project I knew that I wanted it to be a project 
for me to practice function pointers. I've done something similar before but since
I love learning, I wanted to solidify my knowledge on the topic a bit.

So starting out, I knew that the menu and courses would be represented by a class.
So I started making those. The first hurdle came when making the menu class.
I wanted the methods of this class to be method pointers in a vector so you could
call the methods by using indices instead of if/switch statements. The problem came 
when the 'ideal program was meant' to have options 1, 2, 3 and 9. This gap in options 
would create a problem with indexing, especially if there were multiple gaps so I 
made the executive decision to change the option from 9 to 4.

At this point, none of the code was really 'made' it was just boiler plate with 
no functionality before the first refactor. Also, I knew that I couldn't test the code
at this point without having created the objects to store. So I began creating a csv parser.

I created a simple readFile() function that gets the relative path of the file and opens it.
One problem I had was reading the files, I wanted the file to skip the first line because
it was just the header of the csv. As it happens to be, getline() 'discards' lines 
entirely or returns the line upto but excluding the delimiter, which is just too perfect.
Reading the file line by line normally(with a csv twist) and storing the values.
When then create objects.

The original code, had 3 classes to represent this, one actualy create the course objects,
which would store the as example, ID(MAT-210), Name(Applications of Calculus), and the Prerequisites(MAT-101, MAT-140).
An intermediate class that would create a node object sort of like a wrapper class. And Finally, a Tree structure that would
store the root and the operations for the possible on the tree.


