# **cpp-chess-v1 by mattperls-code**

## **setup**

Clone this github repository.

Next execute the bash script *"build/compile.bash"*.

Finally execute the compiled program *"build/chess"*.

<br/>

## **usage**

## moving pieces

> move &lt;piece-name&gt; &lt;move-name&gt; &lt;move-iteration-count&gt;

examples:
 * move p4 up two *1
 * move k2 right two and up *1
 * move q1 left and back *3
 * move r1 right *6

<br/>

move-name is the string that tells where the piece should go. The horizontal movement is always listed first.

examples:
 * left
 * left and up
 * right two and back
 * back two
 * right and up

<br/>

move-iteration-count is an integer that tells how many times this move should be repeated. It is only used for rooks, bishops, and queens.

This must be included, **even if the piece does not have the option to iterate its moves**.

It should be written as *1 if the move should only be done once, *2 if the move should be done twice, *3 if the move should be done three times, etc.

## special moves (castling)

Castling is very simple, to castle with rook number 1, you would do the following:

> move r1 castle *1

Remember that the move-iteration-count **must** be included