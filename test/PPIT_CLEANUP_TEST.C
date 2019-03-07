#include <stdio.h>
#include <stdlib.h>

// Stored Input/Output File Names
    char InputFileName[256]/*, OutputFileName[256]*/;
    FILE *InputFile, *OutputFile; // The files to be input and output

void CleanUp( )
{
    printf( "Cleaning up...\n" );
	fclose( InputFile );
	fclose( OutputFile );
	//system( "cls" );// Windows build
	system( "clear" );// Unix/Linux build
}

int main( )
{
    atexit( CleanUp );

    printf( "Starting  main program...\n" );
    printf( "Exiting main program...\n" );

    return( 0 );
}
