#ifndef _GLOBAL_H_
#define _GLOBAL_H_

// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/* 3rd Party Libraries */

#define TITLE		"Project Presidents - Inauguration Tool"
#define VERSION		"In-Dev - Testing"
#define DEBUG		1

int debugf( char *message, ... )
{
	if( DEBUG == 1 )
	{
		va_list args;
		va_start(args, message);
		printf("Debug: ");
		vprintf(message, args);
		printf("\n");
		va_end(args);
	}
  
	return 1;
}

void Quit( )
{
	printf( "Cleaning up...\n" );
//	#ifdef BUILD_LINUX
	system( "clear" );// Unix/Linux build
//	#else
//	system( "cls" );// Windows build
//	#endif // BUILD_LINUX
	printf( "Thank you for using this program.\n" );
	printf( "Please report any suggestions or bugs to the Discord.\n");
	exit ( EXIT_SUCCESS );
}

/* Variables */

int Restart;
int ExportFiles;
char ch;

/* Stored Input/Output File Names */
char InputFileName[256], OutputFileName[256];

/* The files to be input and output */
FILE *InputFile, *OutputFile;

char EntityIdentifier[5] = "EEN2"; // Environmental Entity Node v2? - Needs to be checked in all: AMO, ARM, CON, CRT, DOR, ITM, USE, and WEA files.

/* CRT File Handling */

char CRTFileSize[2];

char CRTRaceUserInput[4];
int CRTRaceValuePosition;
char CRTRaceValueSession[4];

// Find a way to make the file search for "Hum" and compare it to CRTRaceValueSession.
char CRTRaceHuman[4] = "Hum";

//char CRTGenderUserInput;
char CRTGenderUserInput[2];
int CRTGenderValuePosition;
char CRTGenderValueSession[2];

// Find a way to make the file search for all of these and compare that to CRTGenderValueSession.
char CRTGenderM[2] = "M";
char CRTGenderF[2] = "F";

char CRTBodyUserInput[4];
int CRTBodyValuePosition;
char CRTBodyValueSession[4];

// Find a way to make the file search for all of these and compare that to CRTBodyValueSession.
char CRTBodyStr[4] = "Str";
char CRTBodyFat[4] = "Fat";
char CRTBodyNor[4] = "Nor";
char CRTBodyWir[4] = "Wir";

char CRTStrengthUserInput[2];
int CRTStrengthValuePosition;
char CRTStrengthValueSession[2];
/* End of CRT File Handling */

char EditMenuExtension;

#endif
