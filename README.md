# PSS Homework

This program takes a line of a text and a set of words as input and output separated sentences 

with uppercase words.

## A version of the program 1.0

# input

The file should be named "input.txt"

the first line is a text, that will be split on sentences

the second line is a number (n) of words, that need to be uppercase, after that there should be n lines with a word in each one.

# output

The file will be named "output.txt"

For each word, it will print the number of sentences, that has this word. If those sentences exist (at least one sentence has this word) after the number it will print all sentences that have this word with an uppercase version of that word.

Program will uppercase a word also if it is a part of another like in this example

> FEARless FEARful

The program would not uppercase words that start with an uppercase symbol, except the word from the input file has an uppercase symbol itself

---

Program has two functions (not counting main): splitting and upperCasting.

- splitting
    - splitting gets as a parameters string of text and reference to the vector of strings, where sentences will be stored
    - because we give as a parameter reference to the vector of string we don't need to return something, vector in main already changed

- upperCasting
    - upperCasting gets as a parameters reference to the vector of sentences and reference to a word(string type).
    - It search for a word in each sentence and if find it than uppercase this word in sentence. and add edited sentence to new special vector of string, created in that function
    - It is always writes in output file number of sentences with this word, even if 0
    - if number of sentences more than 0 (assume $**n**$ sentences) it prints $n$ lines with edit sentence in each one.

In main function program just read a text, number of words and words. After that it calls splitting and upperCasting functions.

---

Here you can see some examples of outputs for a given inputs

### input

> some text, text. another one text. That should be also a text
3
text
innopolis
some

### output

> 3
some TEXT, TEXT.
another one TEXT.
That should be also a TEXT
0
1
SOME text, text.

### input

> war is peace. freedom is slavery. ignorance is strength.
3
war
is
slavery

### output

> 1
> WAR is peace.
3
war IS peace.
freedom IS slavery.
ignorance IS strength.
1
freedom is SLAVERY.
