

# LAB 2 - 2D Linked List

## Instructions
To _complie_ the programs, use the following commandline:
`gcc -Wall -g -o programName programSource.c`

To _run_ the programs, use the following commandline:
`./programName`

## Program Details
#### Part 3: insert the node in the end of each sublist
- The main program will take multiple lines for inserting nodes in the format "Ins 2dNodeToInsertFrom NameOf1dNodeToInsert"
- Initialize the 2d node with `p2d = mkExConfig();` in the main(), this gives you some initial 2d nodes followed by 1d nodes
- In the `void insertCommand(struct node2d *p2d)` function line 84, use `insert(p2d, Name2d, Name1d);` to insert the node in the end of each sublist
- The program will terminate immediately when such errors occur:
  1. If the command does not beign with "Ins "
  2. The names are not alphanumeric characters
  3. Invalid format
- You may manually terminate the input by "control + d" in terminal, the program will print out all the configurations so far

#### Part 4: Insert the Node by alphabetical order
- Comment the original configuration and initialize the 2d node with `p2d = part4Config();` in the main(), this gives you 3 initial 2d nodes followed by 0 nodes
- In the `void insertCommand(struct node2d *p2d)` function line 85, use `insertAlphabetically(p2d, Name2d, Name1d);` instead of line 84`insert(p2d, Name2d, Name1d);` to insert the node in alphabetical order
- Warning: the UPPERCASE characters will always rank as smaller than the lowercase characters
- You may manually terminate the input by "control + d" in terminal, the program will print out all the configurations so far


## License
MIT
