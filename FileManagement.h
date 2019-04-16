// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long fsize;
char *FileString;

int OpenInputFile( char *InputFileName )
{
	if( !( InputFile = fopen( InputFileName,"r+" ) ) ) perror("File Not Found!");
	else printf( "File loaded!\n" );

	return 1;
}

int CreateOutputFile( char *OutputFileName )
{
	OutputFile = fopen( OutputFileName,"w" );
	printf( "File Created!\n" );
	
	return 1;
}
