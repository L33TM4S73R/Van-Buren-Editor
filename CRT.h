int GetCRTRaceValuePosition( )
{
	char *pointer;

	pointer=strstr(FileString,CRTRaceHuman);
	if( pointer != NULL ) 
	{
		CRTRaceValuePosition = pointer - FileString;
	}

	printf("CRT Race Location: %d\n", CRTRaceValuePosition);

	return 1;
}

int SetCRTRaceValue( )
{
	GetCRTRaceValuePosition( );
	printf( "Enter the desired 3-character race type.\n" );
	fflush(stdin);
	if( fgets (CRTRaceUserInput, sizeof(CRTRaceUserInput), stdin)!=NULL )
	{
//		printf( "Now: %s", CRTRaceUserInput );
		printf( "Making Changes...\n" );
		fseek( InputFile, CRTRaceValuePosition, SEEK_SET );
//		fseek( InputFile, 20, SEEK_SET );
		fwrite (CRTRaceUserInput , sizeof(char), sizeof(CRTRaceUserInput), InputFile);
		printf( "Finished!\n" );
	}
	else
	{
			printf( "Race length is to small or large\n" );
			printf( "Invalid race length\n");
			exit( EXIT_FAILURE );
	}
	return 1;
}

void CRTEditMenu( )
{
	int CRTEditMenuInput;
	printf( "Inauguration Tool Editing Menu - CRT\n" );
	printf( "-----------------------------\n" );
	printf( "1. *WIP* Edit Race\n" );
//	printf( "2. *UNAVAILABLE* Edit Gender\n" );
//	printf( "3. *UNAVAILABLE* Edit Body\n" );
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
			printf( "Disabled, Quitting!\n " );
			exit( EXIT_SUCCESS );
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

int ReadCRTFile( void )
{
	fseek( InputFile, 0, SEEK_END );
	fsize = ftell( InputFile );
	fseek( InputFile, 0, SEEK_SET );

	FileString = malloc( fsize + 1 );
	fread( FileString, 1, fsize, InputFile );

	return 1;
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
//		if ( (InputFile = fopen( InputFileName, "r+" ) ) == NULL ) //read+write binary mode
//		{
//			printf( "Error! File not found, Quitting!\n" );
//			exit( EXIT_FAILURE );
//		}
		ReadCRTFile( );
	}

	FileString[fsize] = 0;
//	printf( "%s", string );

	GetCRTRaceValuePosition( );

	CRTEditMenu( );

	return 1;
}

int CRTExport( )
{
	printf( "Export The File?(Y/N): \n" );
		char ExportPrompt ='n';
    	scanf( " %c", &ExportPrompt );
    	getchar();

    	if ( ExportPrompt == 'y'|| ExportPrompt == 'Y' )
	{
		printf( "Enter the name of the .CRT file to be exported.\n" );
		if( fgets ( OutputFileName, sizeof( OutputFileName ), stdin )!=NULL ) // File name to be exported
		{
			printf( "Creating backup of file...\n" );
			CreateOutputFile( OutputFileName );
			fputs( FileString, OutputFile );
			printf( "Backup created successfully.\n" );
			fclose( InputFile );
			fclose( OutputFile );
		}
	}
	return 1;
}
