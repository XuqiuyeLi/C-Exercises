# LAB 1 - C programs

## Instructions
To _complie_ the programs, use the following commandline:
`gcc -Wall -g -o programName programSource.c`

To _run_ the programs, use the following commandline:
`./programName`

## Program Details
#### Q1
- This program takes **3 numbers** as arguments "start", "end", and "increment"
- It prints out all numbers from "start" to "end" by "increment"

#### Q2
- This programs takes **two arguments** "low", "high" and calls isPrime(x) for each low <= x <= high
- For each x, main() prints one line which states either
 	- x is invalid
	- x is prime
	- x is not prime

#### Q3
- A main program that reads characters from the terminal and writes characters on the screen
	- if not a letter, print as it is
	- if upper case letter, print as lower case
	- if lower case letter, print as upper case

#### Q4
- This program sorts an array of integers it reads from terminal

#### Q5
- This function takes a 3x3 matrix and returns a new matrix by following rule:
 	- First,for each cell in generation 0, count how many of its neighbors are 1  
 	- If that count gives 2 or 3, the cell is 1 in next generation
 	- If the count is neither 2 nor 3, the cell is 0 in next generation

## License
MIT


