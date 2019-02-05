void SetBody()
{
	int CRTBodyValueLocation;

	perror( "Set Body Called.\n" );
//	printf( "Current body type : '%s'\n", CRTBody ); // Find a way to translate to perror
	printf( "Enter the desired 3-character body type.\n" );
	fflush( stdin );

	if( fgets( CRTBodyInput, sizeof( CRTBodyInput ), stdin )!=NULL )
	{
//        printf( "Is '%s' the correct Input?\n", CRTBody );

        printf( "Making Changes...\n" );
        // fseek(InputFile, CRTBodyValueLocation, SEEK_SET) // Moving pointer for body - pulls info from "CRTBodyValueLocation"
        fseek( InputFile, 18, SEEK_SET ); // Moving pointer for body - Only for PCFemale.CRT

        printf( "%ld\n", ftell( InputFile ) ); // Find a way to translate to perror
        fputs( CRTBodyInput, InputFile );
        printf( "Done!\n" );
//  	printf( "Body type after edit: '%s'\n", CRTBodyInput ); // Find a way to translate to perror
	}
	else
	{
		perror( "Error parsing input, Quitting!\n" );
		exit( EXIT_FAILURE );
	}
	perror( "Set Body Finished!\n" );
}
