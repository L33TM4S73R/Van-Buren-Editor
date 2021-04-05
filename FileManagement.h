char *FileString;
char FileExportPrompt;

int OpenInputFile( char *InputFileName )
{
	debugf( "Opening file...\n" );
	if( !( InputFile = fopen( InputFileName,"r+" ) ) )
	{
		perror( "File could not be opened or found, Quiting!\n" );
		exit( EXIT_FAILURE );
	}
	else
	{
		debugf( "File opened.\n" );
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
	debugf( "Seeking to end of file...\n" );
	fseek( InputFile, 0, SEEK_END );
	debugf( "Getting size of file...\n" );
	fsize = ftell( InputFile );
	debugf( "Allocating file size...\n" );
	FileString = malloc(  fsize + 1 );
	debugf( "Seeking to beginning of file...\n" );
	fseek( InputFile, 0, SEEK_SET );
	debugf( "Reading file...\n" );
	fread( FileString, 1, fsize, InputFile );
	debugf( "File reading finished...\n" );
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
				printf( "Error writing to file!\n" );
				exit( EXIT_FAILURE );
		}
	}
	return 1;
}
