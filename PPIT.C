// Project Presidents - Inauguration Tool CRT,ITM,&RLE Test written in C

// DEVELOPER/DEVELOPERS!! OVER HERE!!!!
// Notes to self:

// Remember to actually do the "Find a way to translate to perror" thing
// log generation should be a priority to understand why things get broke, especially when we switch to SDL.

// FINALLY GET THE PROGRAM TO READ CRT DEFINITIONS FROM THE FILE YOU ARE EDITING,
// WhiteSnoop helped You/Redneck with this, but it won't work sometimes.

// Convert things from the various test.C files.

// Address ITM and MAP Files - 25%

// Make uploads to Github within 30 days or you'll never get this done.

// Learn the difference between a long int an int and a char, these compiler warnings are annoying.

// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3rd Party Libraries

// Project President Libraries

	int Restart, FileType;
	char ch;
// Stored Input/Output File Names
    char InputFileName[256]/*, OutputFileName[256]*/;
// Stored Input Scan Values
//	long int CRTBodyInputStringLength = sizeof( CRTBodyInputString );
//	long int CRTRaceInputStringLength = sizeof( CRTRaceInputString );
    int CRTGenderInputScan[1];
    char CRTBodyInputScan[3];
    char CRTRaceInputScan[3];
    char EditMenuExtension;
	FILE* InputFile/*, *OutputFile*/; // The files to be input and output
/*
struct CRT // CRT File: For NPCs, Creatures, and PC
{
	int IsNPC;
	int IsPC;
	char Name[80];
	int Race;
	int Gender;
	int Body;
};

struct ITM // ITM file: WEA, ITM, ??CHM??
{
	int AMO;
	int WEA;
	int CHM;
	char Name[80];
	char Icon[80];
	char Texture[80];
	char Model[80];
};

struct RLE // Pip-boy mini-map file
{
	int HEAD;
	int LGTD;
	int INFO;
	int LGTR;
};
*/
#include "SetRace.H"
#include "SetGender.H"
#include "SetBody.H"

#include "SetStrength.H"
#include "SetPerception.H"
#include "SetEndurance.H"
//#include "SetCharisma.H"
//#include "SetIntelligence.H"
//#include "SetAgility.H"
//#include "SetLuck.H"

void HexView( )
{
	perror( "Hex View Called.\n" );
	int i;

	printf( "Hex View of Input %s File :\n", InputFileName );
	while( ( ch = fgetc( InputFile ) ) != EOF )
	{
		printf( "%02X ",ch );
		if( !( ++i % 16 ) ) putc( '\n', stdout );
	}
	printf( "Done!\n" );
	printf( "Hex View Finished!\n" );
}

void PPITDisclaimer()
{
	printf( "This program is still in development.\n" );
	printf( "Many features don't work or are highly experimental.\n" );
	printf( "Right now, just consider this program a proof-of-concept.\n" );
	printf( "All things are liable to change, thank you.\n" );
}

void CRTEditMenu()
{
	int CRTEditMenuInput;
	printf( "Inauguration Tool Editing Menu - CRT\n" );
//	printf( "Inauguration Tool Editing Menu - %s\n", EditMenuExtension );
	printf( "NOTE: With Hex View you will get odd FFFFFF artifacts from time to time, I have no clue what these are.\n" );
	printf( "1. Edit Race\n" );
	printf( "2. *DISABLED* Edit Gender\n" );
	printf( "3. *DISABLED* Edit Body\n" );
	printf( "4. Hex View\n" );
	printf( "5. Exit\n" );
	scanf( " %d", &CRTEditMenuInput );
	printf( "Input is %d\n", CRTEditMenuInput ); // Find a way to translate to perror
	switch ( CRTEditMenuInput )
	{
		case 1:
			SetRace();
			break;
		case 2:
//			SetGender();
			perror( "Disabled, Quitting!\n " );
			exit( EXIT_SUCCESS );
			break;
		case 3:
//			SetBody();
			perror( "Disabled, Quitting!\n " );
			exit( EXIT_SUCCESS );
			break;
		case 4:
			HexView( );
			break;
		case 5:
			printf( "Thank you for using this program.\n" );
			exit( EXIT_SUCCESS );
			break;
		default:
			perror( "No Valid Input, Quitting!\n " );
			exit( EXIT_FAILURE );
			break;
	}
}

#include "CRTEdit.H"

void RLEEditMenu( )
{
//	printf( "Inauguration Tool Editing Menu - %s\n", EditMenuExtension );
    printf( "How the heck did you get here?" );
}

#include "RLEEdit.H"

void ITMEditMenu( )
{
	int ITMEditMenuInput;
	printf( "Inauguration Tool Editing Menu - ITM\n" );
//	printf( "Inauguration Tool Editing Menu - %s\n", EditMenuExtension );
	printf( "NOTE: With Hex View you will get odd FFFFFF artifacts from time to time, I have no clue what these are.\n" );
	printf( "1. Hex View\n" );
	printf( "2. Exit\n" );
	scanf( " %d", &ITMEditMenuInput );
	printf( "Input is %d\n", ITMEditMenuInput ); // Find a way to translate to perror
	switch ( ITMEditMenuInput )
	{
		case 1:
			HexView( );
			break;
		case 2:
			printf( "Thank you for using this program.\n" );
			exit( EXIT_SUCCESS );
			break;
		default:
			perror( "No Valid Input, Quitting!\n " );
			exit( EXIT_FAILURE );
			break;
	}
}

#include "ITMEdit.H"

void StartMenu( )
{
	do
	{
	    int StartMenuInput;
        PPITDisclaimer( );
		printf( "Inauguration Tool Start Menu\n" );
		printf( "1. Load a Human CRT to Edit\n" );
		printf( "2. *DISABLED AGAIN!!* Load an ITM to Edit\n" );
		printf( "3. *DISABLED* Load a RLE to Edit\n" );
		printf( "4. Write errors to external log file(this session)\n" );
		printf( "5. Exit\n" );
		printf( "Note: Please refer to Technical Info.txt\n" );
		scanf( " %d", &StartMenuInput );
		printf( "Input is %d\n", StartMenuInput ); // Find a way to translate to perror
		switch ( StartMenuInput )
		{
			case 1:
//psuedo               EditMenuExtension == "CRT"
				CRTEdit( );
				break;
			case 2:
//psuedo                EditMenuExtension == "ITM"
//				ITMEdit( );
				perror( "Disabled, Quitting!\n" );
				exit( EXIT_SUCCESS );
				break;
			case 3:
//psuedo                EditMenuExtension == "RLE"
//				RLEEdit( );
				perror( "Disabled, Quitting!\n" );
				exit( EXIT_SUCCESS );
				break;
			case 4:
				freopen( "error.log", "w", stderr );
				perror( "Log file created.");
				break;
			case 5:
				printf( "Thank you for using this program.\n" );
				break;
				exit( EXIT_SUCCESS );
			default:
				perror( "No Valid Input, Quitting!\n " );
				exit( EXIT_FAILURE );
				break;
		}

    		printf( "Restart?(y/n): \n" );
			char RestartPrompt ='y';
    		scanf( " %c", &RestartPrompt );

    		if ( RestartPrompt == 'n'|| RestartPrompt == 'N' )
                Restart = 1;

    } while ( !Restart );
		fclose( InputFile );
//		fclose( OutputFile );
		printf( "Thank you for using this program.\n" );
		exit ( EXIT_SUCCESS );

}

int main( void )
{
    StartMenu( );
// Start of older code to be restructured
/*
		printf( "Enter the name of the .CRT file to be exported.\n" );
//		fgets( OutputFileName, sizeof( OutputFileName ), stdin ); // Input File name to be exported

//		OutputFile = fopen( OutputFileName,"ab+" ); // Open or create file for writing
//		printf( "Creating backup of file...\n" );

//		if( OutputFileName == NULL )
//		{
//			fclose( InputFile );
//			perror( "Error while creating and reading backup.\n" );
//			exit( EXIT_FAILURE );
//		}

//		while ( ( ch = fgetc( InputFile ) ) != EOF )
//		fputc( ch, OutputFile );

//		printf( "Backup created successfully.\n" );

//		fclose(InputFile);
*/

}
