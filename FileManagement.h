char *FileString;
char FileExportPrompt;

int OpenInputFile( char *InputFileName )
{
	if( !( InputFile = fopen( InputFileName,"r+" ) ) )
	{
		perror( "File could not be opened or found, Quiting!\n" );
		exit( EXIT_FAILURE );
	}
	else
	{
		debugf( "Opening File.\n" );
	}

	return 1;
}

int CreateOutputFile( char *OutputFileName )
{
	OutputFile = fopen( OutputFileName,"w" );
	printf( "Creating File.\n" );
	
	return 1;
}

int ReadFile( void )
{
	fseek( InputFile, 0, SEEK_END );
	fsize = ftell( InputFile );
	FileString = malloc( sizeof( fsize ) + 1 );
	fseek( InputFile, 0, SEEK_SET );
	fread( FileString, 1, fsize, InputFile );

	return 1;
}

int FileExport( )
{
	if( ExportFiles >= 1 )
	{
		char ExportPrompt;
		printf( "Do you wish to export the file?(Y/N): \n" );
	    	scanf( " %c", &ExportPrompt );
	    	getchar( );

    		if( ExportPrompt == 'y'|| ExportPrompt == 'Y' )
		{
			printf( "Enter the new name of the file to be exported.\n" );
			if( fgets( OutputFileName, sizeof( OutputFileName ), stdin )!=NULL ) // File name to be exported
			{
				printf( "Creating backup of file...\n" );
				CreateOutputFile( OutputFileName );
				fputs( FileString, OutputFile );
				printf( "Backup created successfully.\n" );
				fclose( InputFile );
				fclose( OutputFile );
			}
			else
				printf(" Error writing to file! \n");
				exit( EXIT_FAILURE );
		}
	}
	return 1;
}
