void ITMEdit( )
{
	perror( "ITM Edit called.\n" );
//	printf( "%s Edit called.\n", EditMenuExtension );
/*	Need to find a way to define the source file being an ITM and put it here.*/
	fflush( stdin );
	printf( "Enter the name of the .ITM file you wish to modify.\n" );
	fgets( InputFileName, sizeof( InputFileName ), stdin ); // Input file to be imported
	InputFileName[strlen( InputFileName )-1] = 0x00; // string length for HexView

	printf( "Reading Input File...\n" );
	InputFile = fopen( InputFileName,"r+" ); // read+write binary mode

	if( InputFile == NULL )
	{
		perror( "Error while reading the file, Quitting!\n" );
		exit( EXIT_FAILURE );
	}

	ITMEditMenu( );
}
