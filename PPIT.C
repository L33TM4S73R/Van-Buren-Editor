// Project Presidents - Inauguration Tool CRT,ITM,&RLE Test written in C

// DEVELOPER!! OVER HERE!!!!
// Notes to self:

// Remember to actually do the "Find a way to translate to perror" thing
// log generation should be a priority to make sure y'know why things get borked.

// FINALLY GET THE PROGRAM TO READ CRT DEFINITIONS FROM THE FILE YOU ARE EDITING,
// WhiteSnoop helped you with this, you figured it out, but it won't work sometimes.

// Convert things from the various test.C files.

// Address ITM and MAP Files

// Make uploads to Github within 30 days or you'll never get this done.

// Learn the difference between a long int an int and a char, these compiler warnings are annoying.

// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3rd Party Libraries(May never get used with my track record)

// Project President Libraries

	int Restart, FileType;
	char ch, InputFileName[256]/*, OutputFileName[256]*/; // The name of the files to input and output
/*	char CRTRaceInputString[3], CRTGenderInputScan[1], body_input[3]*/; // The values to be changed
//  int CRTGenderInputScan;
//	long int CRTRaceInputStringLength = sizeof( CRTRaceInputString );
	FILE* InputFile/*, *OutputFile*/; // The files to be input and output
/*
struct CRT { // CRT File: For NPCs, Creatures, and PC
	int IsNPC;
	int IsPC;
	char Name;
	int Race;
	int Gender;
	int Body;
};

struct ITM { // ITM file: WEA, ITM, ??CHM??
	int AMO;
	int WEA;
	int CHM;
	char Name;
	int Icon;
	int Texture;
	int Model;
};

struct RLE { // Pip-boy mini-map file
	int HEAD;
	int LGTD;
	int INFO;
	int LGTR;
};
*/

void SetRace()
{
	char CRTRaceInputString[7];
	long int CRTRaceInputStringLength = sizeof( CRTRaceInputString );
	perror( "Set Race Called.\n" );

	printf( "Was: %s", CRTRaceInputString ); // Find a way to translate to perror
	printf( "Enter the desired 7-character race type.\n" );
	fflush(stdin);

	printf( "Race input string length: %d\n", sizeof( CRTRaceInputString )  ); // Find a way to translate to perror
	printf( "Equivalent hexadecimal number of $placeholder$ is: %02X",CRTRaceInputStringLength ); // Find a way to translate to perror

	fgets( CRTRaceInputString, sizeof( CRTRaceInputString ), stdin ); // Input new race type
	printf( "Now: %s", CRTRaceInputString ); // Find a way to translate to perror
	if( CRTRaceInputStringLength == 7 )
	{
			printf( "Making Changes...\n" );
			fseek( InputFile, 14, SEEK_SET ); // Moving pointer for race - Only for select .CRT files
		//	fseek( InputFile, CRTRaceLocation, SEEK_SET )// Moving pointer for race
			printf( "%ld\n", ftell( InputFile ) );// Find a way to translate to perror
			fputs( CRTRaceInputString, InputFile );
	}
	else
	{
		//	printf( "Race length is to small or large\n" );
		//	perror( "Invalid race length\n");
		//	exit( EXIT_FAILURE );
	}
	printf( "Done!\n" );
	perror( "Set Race Finished!\n" );
}

void SetGender()
{
	long int CRTGenderInputScan;

	perror( "Set Gender Called.\n" );
	printf( "Enter the desired 1-character gender type.\n" );
//	fflush(stdin);
	scanf( "%d",&CRTGenderInputScan);
//	fgets( gender_input, sizeof( gender_input ), stdin ); // Input new gender type

//	printf( "Current gender type : %s", CRTGenderInputScan ); // Find a way to translate to perror

//	printf( "Making Changes...\n" );
//	fseek( InputFile, 17, SEEK_SET ); // Moving pointer for gender - Only for PCFemale.CRT
//  fseek( InputFile, CharGenderLocation, SEEK_SET ): // CharGenderLocation is 17 in PCFemale.CRT
//	printf( "%ld\n", ftell( InputFile ) ); // Find a way to translate to perror
//	fputs( gender_input, InputFile );
	printf( "Done!\n" );
	perror( "Set Gender Finished!\n" );
}

void SetBody()
{
	perror( "Set Body Called.\n" );
//	printf( "Enter the desired 3-character body type.\n" );
//	fflush( stdin );
//	fgets( body_input, sizeof( body_input ), stdin ); // Input new body type
//	printf( "Current body type : %s", body_input ); // Find a way to translate to perror

//	printf( "Making Changes...\n" );
//	fseek( InputFile, 18, SEEK_SET ); // Moving pointer for body - Only for PCFemale.CRT

//	printf( "%ld\n", ftell( InputFile ) ); // Find a way to translate to perror
//	fputs( body_input, InputFile );
	printf( "Done!\n" );
	perror( "Set Body Finished!\n" );
}

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
	scanf( "%d", &CRTEditMenuInput );
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

//#include "CRTEdit.H"

void CRTEdit( )
{
	perror( "CRT Edit called.\n" );
//	printf( "%s Edit called.\n", EditMenuExtension ); // Find a way to translate to perror
	fflush( stdin );
	printf( "Enter the name of the .CRT file you wish to modify.\n" );
	fgets( InputFileName, sizeof( InputFileName ), stdin ); // Input File name to be imported
	InputFileName[strlen( InputFileName )-1] = 0x00; // string length for HexView

	printf( "Reading Input File...\n" );
	InputFile = fopen( InputFileName,"r+" ); // read+write binary mode

	if( InputFile == NULL )
	{
		perror( "Error while reading the file, Quitting!\n" );
		exit( EXIT_FAILURE );
	}

	CRTEditMenu( );
}

void RLEEditMenu( )
{
//	printf( "Inauguration Tool Editing Menu - %s\n", EditMenuExtension );
    printf( "How the heck did you get here?" );
}

void RLEEdit()
{
	perror( "RLE Edit Called.\n" );
//	printf( "%s Edit called.\n", EditMenuExtension ); // Find a way to translate to perror
	printf( "Done!\n" );
	perror( "RLE Edit Finished!\n" );
}

void ITMEditMenu( )
{
	int ITMEditMenuInput;
	printf( "Inauguration Tool Editing Menu - ITM\n" );
//	printf( "Inauguration Tool Editing Menu - %s\n", EditMenuExtension ); // Find a way to translate to perror
	printf( "NOTE: With Hex View you will get odd FFFFFF artifacts from time to time, I have no clue what these are.\n" );
	printf( "1. Hex View\n" );
	printf( "2. Exit\n" );
	scanf( "%d", &ITMEditMenuInput );
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

void ITMEdit( )
{
	perror( "ITM Edit called.\n" );
//	printf( "%s Edit called.\n", EditMenuExtension );
/*	Need to find a way to define the source file being an ITM and put it here.*/
	fflush( stdin );
	printf( "Enter the name of the .ITM file you wish to modify.\n" );
	fgets( InputFileName, sizeof( InputFileName ), stdin ); // Input file to be imported
	InputFileName[strlen( InputFileName )-1] = 0x00; // string length for HexView

	printf( "Reading Input File...\n" );
	InputFile = fopen( InputFileName,"r+" ); // read+write binary mode

	if( InputFile == NULL )
	{
		perror( "Error while reading the file, Quitting!\n" );
		exit( EXIT_FAILURE );
	}

	ITMEditMenu( );
}

int main( void )
{
	do
	{
		int StartMenuInput;
		PPITDisclaimer( );
//		StartMenu( );
		printf( "Inauguration Tool Start Menu\n" );
		printf( "1. Load a Human CRT to Edit\n" );
		printf( "2. *DISABLED AGAIN!!* Load an ITM to Edit\n" );
		printf( "3. *DISABLED* Load a RLE to Edit\n" );
		printf( "4. Write errors to external log file(this session)\n" );
		printf( "5. Exit\n" );
		printf( "Note: Please refer to Technical Info.txt\n" );
		scanf( "%d", &StartMenuInput );
		printf( "Input is %d\n", StartMenuInput ); // Find a way to translate to perror
		switch ( StartMenuInput )
		{
			case 1:
//psuedo                EditMenuExtension == CRT
				CRTEdit( );
				break;
			case 2:
//psuedo                EditMenuExtension == ITM
//				ITMEdit( );
				perror( "Disabled, Quitting!\n" );
				exit( EXIT_SUCCESS );
				break;
			case 3:
//psuedo                EditMenuExtension == RLE
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
    		fflush(stdin);
			char RestartPrompt ='y';
    		scanf( "%c", &RestartPrompt );

    		if ( RestartPrompt == 'n'|| RestartPrompt == 'N' )
                Restart = 1;

//		return 0;

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

	return(0);
*/
    } while ( !Restart );
		fclose( InputFile );
//		fclose( OutputFile );
		printf( "Thank you for using this program.\n" );
		exit ( EXIT_SUCCESS );

}
