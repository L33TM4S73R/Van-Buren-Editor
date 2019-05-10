int GetCRTRaceValuePosition( )
{
	char *pointer;

	pointer=strstr( FileString,CRTRaceHuman );
	if( pointer != NULL && pointer > 0 ) 
	{
		CRTRaceValuePosition = pointer - FileString;
		printf("CRT Race Location: %d\n", CRTRaceValuePosition);
	}
	else
	{
		printf( "File is either corrupt or an invalid .CRT" );
		exit( EXIT_FAILURE );
	}
	return 1;
}

int SetCRTRaceValue( )
{
	printf( "Enter the desired 3-character race type.\n" );
	fflush(stdin);
	if( fgets( CRTRaceUserInput, sizeof( CRTRaceUserInput ), stdin )!=NULL /*&& sizeof( CRTRaceUserInput ) == 3 */)
	{
		printf( "Making Changes...\n" );
		fseek( InputFile, CRTRaceValuePosition, SEEK_SET );
		fwrite( CRTRaceUserInput , sizeof( char ), sizeof( CRTRaceUserInput ), InputFile );
		printf( "Finished!\n" );
	}
	else
	{
			printf( "Invalid Race length: Either too small or too large.\n" );
			exit( EXIT_FAILURE );
	}
	return 1;
}

int GetCRTBodyValuePosition( )
{
	CRTBodyValuePosition = CRTRaceValuePosition + 2;
	printf( "CRT Body Location: %d\n", CRTBodyValuePosition );
	return 1;
}

int SetCRTBodyValue( )
{
	printf( "Enter the desired 3-character body type.\n" );
	fflush(stdin);
	if( fgets( CRTBodyUserInput, sizeof( CRTBodyUserInput ), stdin )!=NULL /*&& sizeof( CRTBodyUserInput ) == 3 */)
	{
		printf( "Making Changes...\n" );
		fseek( InputFile, CRTBodyValuePosition, SEEK_SET );
		fwrite( CRTBodyUserInput , sizeof( char ), sizeof( CRTBodyUserInput ), InputFile );
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
	printf("CRT Race Location: %d, CRT Race value: %s\n", CRTRaceValuePosition, CRTRaceHuman );
	printf("CRT Body Location: %d\n", CRTBodyValuePosition );
//	printf("CRT Body Location: %d, CRT Body value: %s\n", CRTRaceValuePosition, CRTBodyStr );
	printf( "-----------------------------\n" );
	printf( "1. *WIP-Broken* Edit Race\n" );
//	printf( "2. *UNAVAILABLE* Edit Gender\n" );
	printf( "3. *WIP-Broken* Edit Body\n" );
//	printf( "4. *UNAVAILABLE* Edit Strength\n" );
//	printf( "5. *UNAVAILABLE* Edit Perception\n" );
//	printf( "6. *UNAVAILABLE* Edit Endurance\n" );
//	printf( "7. *UNAVAILABLE* Edit Charisma\n" );
	printf( "-----------------------------\n" );
	printf( "4. Exit\n" );
	scanf( " %d", &CRTEditMenuInput );
	getchar( );
	switch ( CRTEditMenuInput )
	{
		case 1:
			SetCRTRaceValue( );
			break;
		case 2:
			printf( "Disabled, Quitting!\n " );
			exit( EXIT_SUCCESS );
			break;
		case 3:
			SetCRTBodyValue( );
			break;
		case 4:
			printf( "Thank you for using this program.\n" );
			exit( EXIT_SUCCESS );
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
//	printf( "%s", string );

//	HEY_REDNECK_HEY!	Put Position Finder here!
	GetCRTRaceValuePosition( );
//	GetCRTGenderValuePosition( );
	GetCRTBodyValuePosition( );

	CRTEditMenu( );

	return 1;
}
