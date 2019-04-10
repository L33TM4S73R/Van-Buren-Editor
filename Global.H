#ifndef _GLOBAL_H_
#define _GLOBAL_H_

/* C Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 3rd Party Libraries */

#define TITLE		"Project Presidents - Inauguration Tool"
#define VERSION		"In-Dev"

/* Variables */

int Restart;
char ch;
char InputFileName[256]/*, OutputFileName[256]*/; /* Stored Input/Output File Names */
FILE *InputFile/*, *OutputFile*/; /* The files to be input and output */

/*      Stored Input Scan Values */
// long int CRTBodyInputStringLength = sizeof( CRTBodyInputString );
// long int CRTRaceInputStringLength = sizeof( CRTRaceInputString );
char CRTGenderInput[1];
char CRTRaceInputScan[3];

char EditMenuExtension;


int FileType;
const char *F3DataFormat( const char *InputFileName )
{
	const char *ext = strrchr( InputFileName, '.' );
	if( !ext || ext == InputFileName ) return "Not Valid File";
	return ext + 1;
}

const char *F3DataFormatCritterCRT( )
{

}

#endif
