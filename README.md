# Project-Presidents-Inauguration-Tool

[Jefferson Engine Research Discord](https://discord.gg/tzF3YFu/).

Foreword
----------------
I will no longer push and pull directly to master, I have realized my issue.

Description
----------------
This is a WIP Editor for the Van Buren Tech Demo, part of a project called Project Presidents, this tool is written in C, which may very likely switch to C++ in the future. This program's Development Environment is currently Code::Blocks 16.01 running on Ubuntu. Future versions will likely use the SDL library when I gain further understanding of it.

As of right now all it is a glorified body editor, and it can't even do that right, will hopefully finish some SPECIAL editing here soon.

As I am currently learning C and C++ there very well may be brute-force style coding issues, outdated standards, and some things may be flat out wrong. I will try to fix and edit these mistakes as I become aware of them. Also, anyone is free to take this code and modify it to their hearts content.

Overview
----------------
Repository structure:
- docs: Documentation files. Currently just contains a simple .txt file about creature body types.
- build: Shouldn't be in the repository itself but will be where compiled binaries will go.
- test: Contains source code tests that haven't made it into the main source code

Disclaimer
----------------
This program has broken .CRT files on me before, not all .CRT files are structured the same, mainly NPC vs PC .CRTs, where the NPC pulls name data from elsewhere(probably mission scripts), whereas PC defines it's own name. This program currently(until body editing gets a re-write) defaults to the body type being 14 bytes from the start of the file, if another .CRT file doesn't have body type here it will surely break.

Compiling
----------------

Compiling this editor is easy, simply download a zip of this repo, then compile the PPIT.C using any C compiler, uncomment whatever code you wish to use as most actual editing is commented out until it is confirmed working in my eyes, this program relies on no 3rd party libraries as of yet.

Regards, RedneckHax0r
