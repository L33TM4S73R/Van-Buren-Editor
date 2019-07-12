#include "SPECIAL.h"

int GetCRTFileSize( )
{
	fseek( InputFile, 8, SEEK_SET );
	fread( CRTFileSize, 1, 1, InputFile );
	return 1;
	
}
int GetCRTRaceValuePosition( )
{
	char *pointer;

	pointer=strstr( FileString,CRTRaceHuman );
	if( pointer != NULL && pointer > 0 ) 
	{
		CRTRaceValuePosition = pointer - FileString;
		debugf( "CRT Race Location: %d", CRTRaceValuePosition );
	}
	else
	{
		printf( "File is either corrupt or not a Human Creature file.\n" );
		exit( EXIT_FAILURE );
	}
	return 1;
}

int GetCRTRaceValue( )
{
	debugf( "GetCRTRaceValue Called" );

	fseek( InputFile, CRTRaceValuePosition, SEEK_SET );
	fread( CRTRaceValueSession, strlen( CRTRaceHuman ), 1, InputFile );
	fseek( InputFile, 0, SEEK_SET );

	return 1;
}

int SetCRTRaceValue( )
{
	printf( "Enter the desired 3-character race type.\n" );
	fflush(stdin);
	if( fgets( CRTRaceUserInput, sizeof( CRTRaceUserInput ), stdin )!=NULL && strlen( CRTRaceUserInput ) == 3 )
	{
		printf( "Making Changes...\n" );
		fseek( InputFile, CRTRaceValuePosition, SEEK_SET );
		fwrite( CRTRaceUserInput , sizeof( char ), strlen( CRTRaceUserInput ), InputFile );
		printf( "Finished!\n" );
	}
	else
	{
			printf( "Invalid Race length: Either too small or too large.\n" );
			exit( EXIT_FAILURE );
	}
	return 1;
}

int GetCRTGenderValuePosition( )
{
	CRTGenderValuePosition = CRTRaceValuePosition + 3; // Hack method, works great, but something better would be nice.
	debugf( "CRT Gender Location: %d", CRTGenderValuePosition );
	return 1;
}

int GetCRTGenderValue( )
{
	debugf( "GetCRTGenderValue Called" );

	fseek( InputFile, CRTGenderValuePosition, SEEK_SET );
	fread( CRTGenderValueSession, strlen( CRTGenderM ), 1, InputFile );
	fseek( InputFile, 0, SEEK_SET );

	return 1;
}

int SetCRTGenderValue( ) // Kind of want to use getchar( ) in this one, will rewrite later.
{
	printf( "Enter the desired 1-character gender type.\n" );
	fflush(stdin);
	if( fgets( CRTGenderUserInput, sizeof( CRTGenderUserInput ), stdin )!=NULL && strlen( CRTGenderUserInput ) == 1 )
	{
		printf( "Making Changes...\n" );
		fseek( InputFile, CRTGenderValuePosition, SEEK_SET );
		fwrite( CRTGenderUserInput , sizeof( char ), strlen( CRTGenderUserInput ), InputFile );
		printf( "Finished!\n" );
	}
	else
	{
			printf( "Invalid Gender length: Either too small or too large.\n" );
			exit( EXIT_FAILURE );
	}
	return 1;
}


int GetCRTBodyValuePosition( )
{
	CRTBodyValuePosition = CRTRaceValuePosition + 4; // Hack method, works great, but something better would be nice.
	debugf( "CRT Body Location: %d", CRTBodyValuePosition );

	return 1;
}

int GetCRTBodyValue( )
{
	debugf( "GetCRTBodyValue Called" );

	fseek( InputFile, CRTBodyValuePosition, SEEK_SET );
	fread( CRTBodyValueSession, strlen( CRTRaceHuman ), 1, InputFile );
	fseek( InputFile, 0, SEEK_SET );

	return 1;
}

int SetCRTBodyValue( )
{
	printf( "Enter the desired 3-character body type.\n" );
	fflush( stdin );
	if( fgets( CRTBodyUserInput, sizeof( CRTBodyUserInput ), stdin )!=NULL && strlen( CRTBodyUserInput ) == 3 )
	{
		printf( "Making Changes...\n" );
		fseek( InputFile, CRTBodyValuePosition, SEEK_SET );
		fwrite( CRTBodyUserInput , sizeof( char ), strlen( CRTBodyUserInput ), InputFile );
		printf( "Finished!\n" );
	}
	else
	{
			printf( "Invalid Body length: Either too small or too large.\n" );
			exit( EXIT_FAILURE );
	}
	return 1;
}

void CRTEditMenu( )
{
	int CRTEditMenuInput;
	printf( "Inauguration Tool Editing Menu - CRT\n" );
	printf( "-----------------------------\n" );
	printf( "CRT Race Location: %d, CRT Race Value: %s\n", CRTRaceValuePosition, CRTRaceValueSession );
	printf( "CRT Gender Location: %d, CRT Gender Value: %s\n", CRTGenderValuePosition, CRTGenderValueSession );
	printf( "CRT Body Location: %d, CRT Body Value: %s\n", CRTBodyValuePosition, CRTBodyValueSession );
	printf( "-----------------------------\n" );
	printf( "1. *WIP* Edit Race\n" );
	printf( "2. *WIP* Edit Gender\n" );
	printf( "3. *WIP* Edit Body\n" );
	printf( "4. *WIP* Edit SPECIAL\n" );
	printf( "-----------------------------\n" );
	printf( "5. *WIP* Hex View\n" );
	printf( "6. Exit\n" );
	scanf( " %d", &CRTEditMenuInput );
	getchar( );
	switch ( CRTEditMenuInput )
	{
		case 1:
			SetCRTRaceValue( );
			break;
		case 2:
			SetCRTGenderValue( );
			break;
		case 3:
			SetCRTBodyValue( );
			break;
		case 4:
			SPECIALEditMenu( );
			break;
		case 5:
			HexView( );
			break;
		case 6:
			Quit( );
			break;
		default:
			printf( "No Valid Input, Quitting!\n " );
			exit( EXIT_FAILURE );
			break;
	}
}

int CRTLoad( void )
{

	fflush( stdin );
	printf( "Enter the name of the .CRT file you wish to modify.\n" );
	if( fgets ( InputFileName, sizeof( InputFileName ), stdin )!=NULL )
	{
		InputFileName[strlen( InputFileName )-1] = 0x00; // string length for HexView
		printf( "Reading Input File...\n" );
		OpenInputFile( InputFileName );
		ReadFile( );
	}

	FileString[fsize] = 0;

	ValidateEntityFile( );

/*	Put Position Finders here! */
	GetCRTFileSize( );
	GetCRTRaceValuePosition( );
	GetCRTRaceValue( );
	GetCRTGenderValuePosition( );
	GetCRTGenderValue( );
	GetCRTBodyValuePosition( );
	GetCRTBodyValue( );

	CRTEditMenu( );

	return 1;
}
