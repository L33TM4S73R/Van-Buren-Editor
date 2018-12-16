# Project-Presidents-Inauguration-Tool

F.Y.I I have no clue how Github does merges, so if you made a branch of this and/or push or pull, I might break everything, sorry.

This is a WIP Editor for the Van Buren Tech Demo, part of a project called Project Presidents, this tool is written in C, which may switch to C++ in the future. This program's Development Environment is currentyl Dev-C++ as it is very lightweight, this may change if required but not likely. Future versions may use SDL if I can put figure out why including libraries in a project causes me issues.

As I am currently learning C there may be and will be brute-force style coding issues, outdated methods, and some things may be flat out wrong. I will try to fix and edit these mistakes as I become aware of them. Also, anyone is free to take this code and modify it to their hearts content, making a completely new program or an entirely better one.

Regards, RedneckHax0r

Warning:

This program has broken .CRT files on me before, not all .CRT files are structured the same, mainly NPC vs PC .CRTs, where the NPC pulls name data from elsewhere, whereas PC defines it's own name. This program currently defaults to the body type being 14 bytes from the start of the file, if another .CRT file doesn't have body type here it will surely break.

Compiling:

Compiling this editor is easy, simply download a zip of this repo, then compile the PPIT.C using any C compiler, uncomment whatever code you wish to use as most actual editing is commented out until it is confirmed working in my eyes, this program relies on no 3rd party libraries as of yet.
