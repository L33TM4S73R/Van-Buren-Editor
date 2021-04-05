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
	#ifdef BUILD_LINUX
	system( "clear" );// Unix/Linux build
	#else
	system( "cls" );// Windows build
	#endif
	printf( "Thank you for using this program.\n" );
	printf( "Please report any suggestions or bugs to the Discord.\n");
	exit ( EXIT_SUCCESS );
}

/* Variables */

int Restart;
int ExportFiles;
int fsize;
char ch;

/* Stored Input/Output File Names */
char InputFileName[256], OutputFileName[256];

/* The files to be input and output */
FILE *InputFile, *OutputFile;

/* EEN2 Info */
struct EEN2 {

	char HeaderSize[4]; // overall size of header in bytes

};
struct EEN2 EEN2;

unsigned char EntityIdentifier[4]; // Environmental Entity Node v2? - Needs to be checked in all: AMO, ARM, CON, CRT, DOR, ITM, USE, and WEA files.

/* End of EEN2 Handling */

/* CRT File Info */
struct CRT {

// Race, Gender, Body Type
	int RGBValueLengthPosition;
	char RGBValueLengthSession[2];// = "0";

// Race
	char RaceUserInput[4];
	int RaceValuePosition;
	char RaceValueSession[4];

// Gender
	char GenderUserInput[2];
	int GenderValuePosition;
	char GenderValueSession[2];

// Body
	char BodyUserInput[4];
	int BodyValuePosition;
	char BodyValueSession[4];
};
struct CRT CRT;

// Find a way to make the file search for "Hum" and compare it to CRTRaceValueSession.
char CRTRaceHuman[4] = "Hum";

// Find a way to make the file search for all of these and compare that to CRTGenderValueSession.
char CRTGenderM[2] = "M";
char CRTGenderMLowercase[2] = "m";
char CRTGenderF[2] = "F";
char CRTGenderFLowercase[2] = "f";

// Find a way to make the file search for all of these and compare that to CRTBodyValueSession.
char CRTBodyStr[4] = "Str";
char CRTBodyFat[4] = "Fat";
char CRTBodyNor[4] = "Nor";
char CRTBodyWir[4] = "Wir";

/* End of CRT File Handling */

/* ITM File Info */
struct ITM {
};
struct ITM ITM;

/* End of ITM File Handling */

char EditMenuExtension;

#endif
