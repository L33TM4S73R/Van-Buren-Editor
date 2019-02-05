void CRTEdit( )
{
	perror( "CRT Edit called.\n" );
//	printf( "%s Edit called.\n", EditMenuExtension ); // Find a way to translate to perror
	fflush( stdin );
	printf( "Enter the name of the .CRT file you wish to modify.\n" );

    if( fgets ( InputFileName, sizeof( InputFileName ), stdin )!=NULL )
    {
        InputFileName[strlen( InputFileName )-1] = 0x00; // string length for HexView
        printf( "Reading Input File...\n" );
        InputFile = fopen( InputFileName,"r+" ); // read+write binary mode

        CRTEditMenu( );
    }
    else
	{
		perror( "Error while reading the file, Quitting!\n" );
		exit( EXIT_FAILURE );
	}
}
