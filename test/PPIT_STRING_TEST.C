// Project Presidents - Character in string test, written in C
// Test: To find the Position of a given character or string
// Future purpose: To find certain positions within Van Buren's files

// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


	int CRTPhysicalValueLocation;
	unsigned int CRTPhysicalValue;
    char InputFileName[256], BodyValue[4];

void JumpToPhysicalLocation( )
{
    CRTPhysicalValueLocation == 0;
    for( CRTPhysicalValueLocation = 0; CRTPhysicalValueLocation < strlen( InputFileName ); CRTPhysicalValueLocation++ )
    {
        if( *"Hum" == InputFileName[CRTPhysicalValueLocation] )
        {
            printf( "%d  ", CRTPhysicalValueLocation + 1 );
            CRTPhysicalValue == CRTPhysicalValueLocation + 1;
        }
    }
}

int main( )
{

	printf( "Enter a string: " );
	if( fgets( InputFileName, sizeof( InputFileName ), stdin )!=NULL )
	{

//        printf( "Enter a Body Value to find the position of: " );
//        fgets ( BodyValue, sizeof( BodyValue ), stdin );

        printf( "Position in the file: " );
        JumpToPhysicalLocation( );
//        while( ( ch = fgetc( InputFileName ) ) != EOF )
    }
	else
	{
		perror( "Error while reading the file, Quitting!\n" );
		exit( EXIT_FAILURE );
	}

	return 0;
}
