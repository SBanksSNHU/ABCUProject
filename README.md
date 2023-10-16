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

The original code, had 3 classes to represent this, one actualy creates the course objects,
which would store them as example, ID(MAT-210), Name(Applications of Calculus), and the Prerequisites(MAT-101, MAT-140).
An intermediate class that would create a node object sort of like a wrapper class (realized that this was useless). 
And Finally, a Tree structure that would store the root and the operations for the possible on the tree.

So why am I explaining this here? Because this is where most of the big problems occured(How fun!)
So In my current code, my readFile() didn't have a tree in it's scope so I couldn't access anything from the class. 
It took me a bit to realize that I just had to refactor but I did... still foolishly choosing to use a tree structure.

After the first refactor(soft refactor), the readFile() could now access members and perform operations. But then here came the other problem.
When within the readFile() function, after the course object is created(remember the high level ID(MAT-210), Name(Applications of Calculus), Prerequisites(MAT-101, MAT-140)?)
This had to be wrapped into a node object, which could then be inserted into the tree. The problem came when inside the insert method that was apart of the Tree class.
If I remember correctly, this is where the Big and Hard refactor came.

I got rid of the intermediate node class, started using more of a linked list approach(because searching for data with mutliple roots seemed like a pain from a tree).
I also initialized the tree within main() along with the menu and created a constructor that allowed, a tree object to be passed as into the menu object. This allowed
me to access the current tree from exactly where I need it, whethere it be from within the Menu scope or readFile() or even main(). At this point, it was mostly smooth sailing.

The only real problem that came after this point, was fixing whenever a node was needed to be added to the tree but all the prerequisites aren't found. Which had an interesting fix








