#ifndef _GLOBAL_H_
#define _GLOBAL_H_

// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 3rd Party Libraries */

#define TITLE		"Project Presidents - Inauguration Tool"
#define VERSION		"In-Dev - Rewrite"

/* Variables */

int Restart;
char ch;

/* Stored Input/Output File Names */
char InputFileName[256], OutputFileName[256];

 /* The files to be input and output */
FILE *InputFile, *OutputFile;

/* CRT File Handling */

char CRTRaceUserInput[4];
int CRTRaceValuePosition;
char CRTRaceHuman[50] = "Hum";

int CRTSexValuePosition;
char CRTSexM[50] = "M";
char CRTSexF[50] = "F";

int CRTBodyValuePosition;
char CRTBodyStr[50] = "Str";
char CRTBodyFat[50] = "Fat";
char CRTBodyNor[50] = "Nor";
char CRTBodyWir[50] = "Wir";

/* End of CRT File Handling */

char EditMenuExtension;

#endif
