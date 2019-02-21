// Project Presidents - Character in string test, written in C
// Test: To find the Position of a given character or string
// Future purpose: To find certain positions within Van Buren's files

// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( )
{

	char InputFileName[256], BodyValue[4];
	int CRTBodyValueLocation;

	printf( "Enter a string: " );
	if( fgets( InputFileName, sizeof( InputFileName ), stdin )!=NULL )
	{

//        printf( "Enter a Body Value to find the position of: " );
//        fgets ( BodyValue, sizeof( BodyValue ), stdin );

        printf( "Position in the file: " );
        while( ( ch = fgetc( InputFileName ) ) != EOF )
        for( CRTBodyValueLocation = 0; CRTBodyValueLocation < strlen( InputFileName ); CRTBodyValueLocation++ )
        {
            if( *"F" == InputFileName[CRTBodyValueLocation] )
            {
                printf( "%d  ", CRTBodyValueLocation + 1 );
            }
            else if( *"M" == InputFileName[CRTBodyValueLocation] )
            {
                printf( "%d  ", CRTBodyValueLocation + 1 );
            }
        }
    }
	else
	{
		perror( "Error while reading the file, Quitting!\n" );
		exit( EXIT_FAILURE );
	}

	return 0;
}
