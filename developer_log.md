Your Developer Log must include:
- A dated entry every time you work on the assignment
- A description of what you worked on
- Any bugs, issues, or problems you encountered
- How you attempted to solve each issue
- A brief explanation of every commit you make
- A list of all files modified during each commit

Commit messages must also be descriptive, and the Developer Log must reflect the reasoning behind each commit.

12/06/25: My first time fully reading and opening this extra credit assignment. Started off with cloning the
repository and then reading the README.md file and the submission.md file. After this, I looked through the
tree.h file to see what I as a student need to add. Some parts were fairly new to me which was confusing at
first, but no issues or problems encountered so far. The commits and file modification was very minimal as
I was still setting up and mapping out everything.


12/07/25: I started writing code after reading and reviewing the requirements and rubric for this assignment.
I started from the top, in the Node class where I filled in the overloaded Node constructor. This is where I 
initialized id with nodeID and data with value. No errors so far, as this was pretty straight forward. Then, 
I moved onto the Tree class functions. I started with the default Tree constructor, which was simple because 
it was just initializing the root to nullptr. I found the next function, 
void createRoot(const string &id, const T &value), to be pretty straightforward as well. I feel like the TODO
instructions make it so much easier to understand. I did an edge case for if a root already existed, then I 
allocated memory with "new", assigned id and data, and set as the root. These were the only commits and files 
modified for this date; tree.h.


12/08/25: The next function I worked on was 
void addNode(const string &parentID, const string &childID, const T &value). This is where I encountered my
first bugs, issues, or problems so far with this assignment. The first edge case for this function was 
simple, whereas if the root is equal to nullptr, that means the root does not already exist, so we return.
Then, as the TODO instructions say, we find parent by calling on the findNode function. Same thing goes for 
child, but if not found, then we create child. But initially, I didn't realize that I forgot to check if 
parent was equal to nullptr. This would be a problem because I was not accounting for whether or not the
parent existed. Other than that, the most difficulty I had in this function was linking the parent to the 
child. I was trying different methods and researching the best way to do this, because at first it didn't
click to me to use the standard vector functions. I tried different ways to assign, but it did not go well
until I fixed the line with parent->children.push_back(child). Files commited and modified were
tree.h.


12/09/25: The next function I worked on was Node<T>* findNode(const string &id). Here, we are asked to use
DFS or BFS to search the tree and find the node. I chose to use a depth first search because I am able to
grasp and understand this better than a breadth first search. This fits the recursive structure of the tree
while using a stack. The first edge case I considered was an empty tree, where there are no nodes to search
for (return nullptr). Then, I set up a stack for DFS while using vector functionalities to push the root
node. Then I created a helper function called void printNode(Node<T>* node) that would help the void printAll()
function to print the entire structure in readable form. I chose to create and use a helper function
because I wanted to use recursion to print the tree, as void printAll() should just simply be set to 
print the tree simply. This is where and when I faced problems because I needed recursion to print the
roots, parents, children, etc, and I did not realize this at first. We would need arguments/parameters
to print the entire tree. Then I started working on the Tree destructor which frees all allocated memory. This function is used to
free dynamically allocated nodes. I tried simply deleting the root, but ran into problems as this was not
tracking deletion for nodes. I changed the approach to a DFS in order to do single-deletion for each node
without deletion errors or memory leaks. I implemented the playGame() function and initially ran into issues with invalid user input causing the game
loop to break. To fix this, I added input validation so that the user must enter a valid option. I also
corrected a bug where the current node wasn’t updating after a selection. The final version properly
navigates the story tree and ends when a node has no children. Files commited and modified were
tree.h.


12/10/25:
