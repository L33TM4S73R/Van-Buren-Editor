// Project Presidents - Inauguration Tool Extension Test written in C

// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *F3DataFormat( const char *filename )
{
    const char *ext = strrchr( filename, '.' );
    if( !ext || ext == filename ) return "Not Valid F3 Format";
    return ext + 1;
}

const char *F3DataFormatCritterCRT( )
{

}

int main( )
{
    printf( "%s\n", F3DataFormat( "PCFemale.CRT" ) );
    printf( "%s\n", F3DataFormat( "Communist" ) );

    return 0;
}
