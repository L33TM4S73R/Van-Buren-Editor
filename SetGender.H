void SetGender()
{
	int CRTGenderValueLocation;

	perror( "Set Gender Called.\n" );
//	printf( "Current gender type : '%s'\n", CRTGender ); // Find a way to translate to perror
	printf( "Enter the desired 1-character gender type.\n" );
	fflush( stdin );

	if( fgets( CRTGenderInput, sizeof( CRTGenderInput ), stdin )!=NULL )
    {
        printf( "Making Changes...\n" );
//      fseek( InputFile, CRTGenderLocation, SEEK_SET ); // Moving pointer for gender - pulls info from "CRTBodyValueLocation"
	    fseek( InputFile, 17, SEEK_SET ); // Moving pointer for gender - Only for PCFemale.CRT
        printf( "%ld\n", ftell( InputFile ) ); // Find a way to translate to perror
        fputs( CRTGenderInput, InputFile );
        printf( "Done!\n" );
//  	printf( "Gender type after edit: '%s'\n", CRTGenderInput ); // Find a way to translate to perror
    }
	else
	{
		perror( "Error parsing input, Quitting!\n" );
		exit( EXIT_FAILURE );
	}
	perror( "Set Gender Finished!\n" );
}
