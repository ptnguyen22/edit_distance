Peter Nguyen

Developed in Ubuntu using the G++ GNU compiler.
Dependencies: SFML --to install: sudo apt-get install libsfml-dev

**********************************************************************

Uses input redirection.
Implemented the concept of dynamic programming to create a program
that can read in a text file of two characters/DNA sequences and compare them to find the edit distance,
a measurement of how similar they are.The program uses a matrix/table filled with the costs from aligning the
characters from each sequence. It first fills 2 other separate vectors with the characters from the text file
for comparing. The edit distance is then calculated using the values from the matrix representation. 
Included a few text files, each with 2 different genetic sequences for testing.

**********************************************************************

to run:
./EDistance < (input file)
example:
./EDistance < ecoli5000.txt
