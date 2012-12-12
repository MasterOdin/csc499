csc499 - Mentored Research Project
Fall 2012, Matthew Peveler
======

Bayesian Network Application for Criminology Based Research

Compiled using GCC Compiler and the Code::Blocks (10.05) IDE

Last Build: 12/12/2012 @ 2:11 PM

Last Update Notes:

	Added methods for getting probability for parent nodes and children nodes

Data format:

Murder/Rape/Robbery column order: \w
1. Population
2. Lighting
3. Time of Day
4. Drugs
5. Location At
6. Location From

Node ID is:
0. Population
1. Lighting
2. Time of Day
3. Drugs
4. Location At
5. Location From
6. Murder
7. Robbery
8. Rape

Probability nodes for 0-5 work as:
Go from high risk (1) to low risk (3,5,5,5,6,6) <- number of values to each of above elements respectively (Pop has 3, Lighting has 5, so on)

To get probability for nodes 0-5:
nodeArray[i]->getProbability(n); where i is the node id and n is the interested probability

for nodes 6-8, pass array of values for interested probability. For example, we want:
(Pop = 2, Lighting = 4; Time of Day = 4; Drugs = 1; Location At = 5; Location From = 3) for Murder, run:
nodeArray[6]->getProbability(array);

where:
int array[6];
array[0] = 2;
array[1] = 4;
array[2] = 4;
array[3] = 1;
array[4] = 5;
array[5] = 3;


// this would be an explanation of sort of what is going on in the code to convert array to actual probability table. Actual code doesn't use mod
// functionality, but uses multiplication of (array[i]-1)*parent[i]->getArity() to find how many elements each section would have, sort of
Given specific probability number (n), to find what it would correspond to, it would be:
n mod(6) -> result mod(6) -> result mod(5) -> result mod(5) -> result mod(5) -> result mod(3)
Continuing while result> 0. Use the remainder in previous steps to find offset from 0 (1 in human terms as values go up from 1 and not 0).

Ex: If we had the number 15:
15%6 = 2 R 3.
2%6 = 0 R 2.

That means we want 0+3 for Location From, and then 0+2 for Location At.
Giving us: 0,0,0,0,2,3. Converting to human terms,
we'd get 1,1,1,1,3,4.


To-Do:
2. Add proper definitions for what high risk and low risk mean (low importance though)
3. Add proper function documentation to better understand code
