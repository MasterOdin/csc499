csc499 - Mentored Research Project
Fall 2012, Matthew Peveler
======

Bayesian Network Application for Criminology Based Research

Compiled using GCC Compiler and the Code::Blocks (10.05) IDE

Data format:
Murder/Rape/Robbery column order:
1. Population
2. Lighting
3. Time of Day
4. Drugs
5. Location At
6. Location From

All Others:
Go from high risk (1) to low risk (3,5,5,5,6,6)

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
1. Add proper method to do the above calculation. What would it return though? (array? string?)
2. Add proper definitions for what high risk and low risk mean (low importance though)
3. Add proper function documentation to better understand code
