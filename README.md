# Project-Presidents-Inauguration-Tool

Jefferson Engine Research Discord: https://discord.gg/tzF3YFu

Foreword: I push and pull directly to master, so I will break things if you wish to contribute, sorry, it's a habit I will try to break.

This is a WIP Editor for the Van Buren Tech Demo, part of a project called Project Presidents, this tool is written in C, which may very likely switch to C++ in the future. This program's Development Environment is currently Code::Blocks 16.01 running on Ubuntu which means Linux binaries are possible but not priority. Future versions may use SDL when I gain proper understanding of it.

As I am currently learning C there very well may be brute-force style coding issues, outdated standards, and some things may be flat out wrong. I will try to fix and edit these mistakes as I become aware of them. Also, anyone is free to take this code and modify it to their hearts content, making a completely new program or an entirely better one.

Warning:

This program has broken .CRT files on me before, not all .CRT files are structured the same, mainly NPC vs PC .CRTs, where the NPC pulls name data from elsewhere, whereas PC defines it's own name. This program currently defaults to the body type being 14 bytes from the start of the file, if another .CRT file doesn't have body type here it will surely break.

Compiling:

Compiling this editor is easy, simply download a zip of this repo, then compile the PPIT.C using any C compiler, uncomment whatever code you wish to use as most actual editing is commented out until it is confirmed working in my eyes, this program relies on no 3rd party libraries as of yet.

Regards, RedneckHax0r
