// Project Presidents - Inauguration Tool Extension Test written in C
// Test: To check if a "file" is a valid F3 Format, if not, show prompt
// Future purpose: To check if a file is a valid F3 Format, if not, don't load file.

// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *F3DataFormat( const char *InputFileName )
{
    const char *ext = strrchr( InputFileName, '.' );
    if( !ext || ext == InputFileName ) return "Not Valid F3 Format";
    return ext + 1;
}

const char *F3DataFormatCritterCRT( )
{

}

#include <stdio.h>
#include <string.h>

int main( )
{
   char InputFileName[] = "PCFemale.CRT";
   char *ext;

   ext = strrchr( InputFileName, '.' );

   printf( "'%s'", ext );

   return( 0 );
}

//int main( )
//{
//    printf( "%s\n", F3DataFormat( "PCFemale.CRT" ) );
//    printf( "%s\n", F3DataFormat( "Communist" ) );
//
//    return 0;
//}
