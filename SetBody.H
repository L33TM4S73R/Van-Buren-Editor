void SetBody()
{
	perror( "Set Body Called.\n" );
	printf( "Enter the desired 3-character body type.\n" );
	fflush( stdin );
	fgets( CRTBodyInputScan, sizeof( CRTBodyInputScan ), stdin ); // Input new body type
	printf( "Current body type : %s", CRTBodyInputScan ); // Find a way to translate to perror

	printf( "Making Changes...\n" );
	fseek( InputFile, 18, SEEK_SET ); // Moving pointer for body - Only for PCFemale.CRT

	printf( "%ld\n", ftell( InputFile ) ); // Find a way to translate to perror
	fputs( CRTBodyInputScan, InputFile );
	printf( "Done!\n" );
	perror( "Set Body Finished!\n" );
}
