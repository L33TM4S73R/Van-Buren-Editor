// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long fsize;
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
		printf( "File loaded!\n" );
	}

	return 1;
}

int CreateOutputFile( char *OutputFileName )
{
	OutputFile = fopen( OutputFileName,"w" );
	printf( "File Created!\n" );
	
	return 1;
}

int ReadFile( void )
{
	fseek( InputFile, 0, SEEK_END );
	fsize = ftell( InputFile );
	fseek( InputFile, 0, SEEK_SET );

	FileString = malloc( fsize + 1 );
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
		}
	}
	return 1;
}
