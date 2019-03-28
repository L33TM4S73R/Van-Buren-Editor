void CRTEdit( )
{
//    char str1[];
//    char HumanCRTFileCheck[] = "Hum";

	perror( "CRT Edit called.\n" );
//	printf( "%s Edit called.\n", EditMenuExtension ); // Find a way to translate to perror
	fflush( stdin );
	printf( "Enter the name of the .CRT file you wish to modify.\n" );

    if( fgets ( InputFileName, sizeof( InputFileName ), stdin )!=NULL )
    {
        InputFileName[strlen( InputFileName )-1] = 0x00; // string length for HexView
        printf( "Reading Input File...\n" );
        if ( (InputFile = fopen( InputFileName, "r+" ) ) == NULL ) //read+write binary mode
        {
            perror( "Error! File not found, Quitting!\n" );
            exit( EXIT_FAILURE );
        }
        else
        {
            perror( "Error while reading the file, Quitting!\n" );
            exit( EXIT_FAILURE );
        }
// Search File for the occurrence of Hum
//      if( strstr( str1, HumanCRTFileCheck ) )
//      {
//          printf( "Is valid Human .CRT file" );
//          CRTInformationMenu( );
//      }
//      else
//      {
//          printf( "Not a valid Human .CRT file" );
//          return 0;
//      }
        CRTInformationMenu( );

    }
}
