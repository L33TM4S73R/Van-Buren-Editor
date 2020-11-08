struct CRT CRT;

int GetCRTFileSize( )
{
	fseek( InputFile, 8, SEEK_SET );
	fread( CRT.FileSize, 1, 1, InputFile );
	return 1;
	
}
int GetCRTRaceValuePosition( )
{
	char *pointer;

	pointer=strstr( FileString,CRTRaceHuman );
	if( pointer != NULL && pointer > 0 ) 
	{
		CRT.RaceValuePosition = pointer - FileString;
		debugf( "CRT Race Location: %d", CRT.RaceValuePosition );
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
	debugf( "Getting Creature Race Value" );

	fseek( InputFile, CRT.RaceValuePosition, SEEK_SET );
	fread( CRT.RaceValueSession, strlen( CRTRaceHuman ), 1, InputFile );
	fseek( InputFile, 0, SEEK_SET );

	return 1;
}

int SetCRTRaceValue( )
{
	printf( "Enter the desired 3-character race type.\n" );
	printf( "Only known option is human: 'Hum'\n" );
	fflush(stdin);
	if( fgets( CRT.RaceUserInput, sizeof( CRT.RaceUserInput ), stdin )!=NULL && strlen( CRT.RaceUserInput ) == 3 )
	{
		printf( "Making Changes...\n" );
		fseek( InputFile, CRT.RaceValuePosition, SEEK_SET );
		fwrite( CRT.RaceUserInput , sizeof( char ), strlen( CRT.RaceUserInput ), InputFile );
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
	CRT.GenderValuePosition = CRT.RaceValuePosition + 3; // Hack method, works great, but something better would be nice.
	debugf( "CRT Gender Location: %d", CRT.GenderValuePosition );
	return 1;
}

int GetCRTGenderValue( )
{
	debugf( "Getting Creature Gender Value" );

	fseek( InputFile, CRT.GenderValuePosition, SEEK_SET );
	fread( CRT.GenderValueSession, strlen( CRTGenderM ), 1, InputFile );
	fseek( InputFile, 0, SEEK_SET );

	return 1;
}

int SetCRTGenderValue( ) // Kind of want to use getchar( ) in this one, will rewrite later.
{
	printf( "Enter the desired 1-character gender type (M/F).\n" );
	fflush(stdin);
	if( fgets( CRT.GenderUserInput, sizeof( CRT.GenderUserInput ), stdin )!=NULL && strlen( CRT.GenderUserInput ) == 1 )
	{
// Quick half-done Capitalization test
		printf( "Checking capitalization..\n");
		if( CRT.GenderUserInput == CRTGenderFLowercase ) // Verify lowercase letter
		{
			
			debugf( "Lowercase F entered!" );
			CRT.GenderUserInput == CRTGenderF;  // Convert to uppercase
		}
		else if( CRT.GenderUserInput == CRTGenderMLowercase )  // Verify lowercase letter
		{
		
			debugf( "Lowercase M entered!" );
			CRT.GenderUserInput == CRTGenderM;  // Convert to uppercase
		}
		printf( "Making Changes...\n" );
		fseek( InputFile, CRT.GenderValuePosition, SEEK_SET );
		fwrite( CRT.GenderUserInput , sizeof( char ), strlen( CRT.GenderUserInput ), InputFile );
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
	CRTBodyValuePosition = CRT.RaceValuePosition + 4; // Hack method, works great, but something better would be nice.
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

int GetCRTRGBValueLengthPosition( )
{
	CRT.RGBValueLengthPosition = CRT.RaceValuePosition - 2; // Hack method, works great, but something better would be nice.
	debugf( "CRT Race,Gender,Body Length Position Location: %d", CRT.RGBValueLengthPosition );
	return 1;
}

int GetCRTRGBValueLength( )
{
	debugf( "Getting RGB Value Length" );

	fseek( InputFile, CRT.RGBValueLengthPosition, SEEK_SET );
	fread( CRT.RGBValueLengthSession, strlen( CRT.RGBValueLengthSession ), 1, InputFile );
	fseek( InputFile, 0, SEEK_SET );

	debugf( "Length of CRT Race,Gender, and Body combined: %02X", CRT.RGBValueLengthSession );

	return 1;
}

void CRTEditMenu( )
{
	int CRTEditMenuInput;
	printf( "Inauguration Tool Editing Menu - CRT\n" );
	printf( "-----------------------------\n" );
	printf( "CRT Race Location: %d, CRT Race Value: %s\n", CRT.RaceValuePosition, CRT.RaceValueSession );
	printf( "CRT Gender Location: %d, CRT Gender Value: %s\n", CRT.GenderValuePosition, CRT.GenderValueSession );
	printf( "CRT Body Location: %d, CRT Body Value: %s\n", CRTBodyValuePosition, CRTBodyValueSession );
	printf( "-----------------------------\n" );
	printf( "1. *WIP* Edit Race\n" );
	printf( "2. *WIP* Edit Gender\n" );
	printf( "3. *WIP* Edit Body\n" );
//	printf( "-----------------------------\n" );
//	printf( "4. *UNAVAILABLE* Edit Script\n" );
//	printf( "5. *UNAVAILABLE* Edit Dialogue Script\n" );
//	printf( "6. *UNAVAILABLE* Edit Skin Texture\n" );
//	printf( "7. *UNAVAILABLE* Edit Inventory\n" );
//	printf( "-----------------------------\n" );
//	printf( "8. *UNAVAILABLE* Edit SPECIAL\n" );
	printf( "-----------------------------\n" );
	printf( "4. *WIP* Hex View\n" );
	printf( "5. Exit\n" );
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
			HexView( );
			break;
		case 5:
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
	GetCRTRGBValueLengthPosition( );
	GetCRTRGBValueLength( );
//	GetCRTSkinValueLength( );
//	GetCRTSkinValue( );

	CRTEditMenu( );

	return 1;
}
