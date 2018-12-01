# Van-Buren-Editor

F.Y.I I have no clue how Github does merges, so if you made a branch of this and/or push or pull, I might break everything, sorry.

This is a repo to house code of a command-line, WIP Editor for the Van Buren Tech Demo, written in C, perhaps C++ in the future. The name of this project is currently Project Presidents(BTW, how do I change the name to where it shows up on Github?). This program is being written in Dev-C++ as it is a very lightweight environment, this may change if required but not very likely. Future versions may use SDL if I can put 2 and 2 together and figure out why including libraries in a project hates me.

As I am currently learning C there may be coding issues or outdated methods. I will fix these as I become aware of them. Anyone is free to take this code and modify it to their hearts content, not that there is much code to it.

Regards, RedneckHax0r

Warning:

This program has broken .CRT files on me before, not all .CRT files are structured the same, mainly NPC vs PC .CRTs, where the NPC pulls name data from elsewhere, whereas PC defines it's own name. This program defaults to the body type being 14 bytes from the start of the file, if another .CRT file doesn't have body type here it will surely break.

Compiling:

Compiling this editor is easy, simply download a zip of this repo, then compile the PPIT.C using any C compiler, uncomment whatever code you wish to use as most actual editing is commented out until it is confirmed to be working 100%, this program relies on no 3rd party libraries as of yet.
