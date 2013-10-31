# DOCUMENTATION

This is basically me trying to implement the laby concept in a more workable fashion.
laby's project file can be found on [github](https://github.com/sgimenez/laby)

### goals:
* correct-ish gcc compiling
    * it should run ANY version of C, unlike the original... maybe fix the original?  
    * can it also run python & other languages? O.O
* gui-less (nox)
    * laby-world is intended to function with or without a gui, outputting to stdout
* "mind geek!"
    * just wanted to mess around with it.

##how it should run:

    1. check for running values/user configurations from gui?
    2. determine the max number of each item to place
    3. use a pseudorandom generator to build map
    4. recursively-ish solve the entire map[x][y] set & call this "show hint"
    5. check to point out where it might freeze
    6. compile or return errors from compiler
    7. execute (or bust), multithreading?
    8. give pass/fail

##the map & the rules explained:
this function is the basics for thinking imperitively. while this program
might not be as smart as you'd hope, it helps you see an interesting & complex
problem that you can spend time solving. personally, the actual program is a
bit weird... so you can type it in what ever language you'd prefer

### functions laby-world defines:

* look(); // identifies the objects one sqare infront of the bug
* forward(); // moves one square forward or returns an error
* left(); // turns bug counter-clockwise
* right(); // turns clockwise
* take(); // picks up rocks one square in front of the bug, doesn't move bug
* drop(); // places rocks one square in front of the bug, doesn't more bug
* escape(); // bug enters exit

values look returns:V B R W E A Null;

#changelog:
* after an initial concept, it's clear my code is FAR from streamlined >.<
* also, I'm not 100% sure most of this stuff is valid >.<

* the code now has ~90 lines, compared to 200. YAY! (I also cheated)