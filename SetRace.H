void SetRace()
{
	char CRTRaceInputString[7];
	int CRTRaceInputStringLength = sizeof( CRTRaceInputString );
	perror( "Set Race Called.\n" );

	printf( "Was: %s", CRTRaceInputString ); // Find a way to translate to perror
	printf( "Enter the desired 7-character race type.\n" );
	fflush(stdin);
    printf( "Race Information:");
	printf( "String length: %ld\n", sizeof( CRTRaceInputString )  ); // Find a way to translate to perror
	printf( "Equivalent hexadecimal number: %02d",CRTRaceInputStringLength ); // Find a way to translate to perror

	if( fgets (CRTRaceInputString, sizeof(CRTRaceInputString), stdin)!=NULL )
	{
        printf( "Now: %s", CRTRaceInputString ); // Find a way to translate to perror
    }
//	fgets( CRTRaceInputString, sizeof( CRTRaceInputString ), stdin ); // Input new race type
//	printf( "Now: %s", CRTRaceInputString ); // Find a way to translate to perror
//	if( CRTRaceInputStringLength == 7 )
//	{
//			printf( "Making Changes...\n" );
//			fseek( InputFile, 14, SEEK_SET ); // Moving pointer for race - Only for select .CRT files
		//	fseek( InputFile, CRTRaceLocation, SEEK_SET )// Moving pointer for race
//			printf( "%ld\n", ftell( InputFile ) );// Find a way to translate to perror
//			fputs( CRTRaceInputString, InputFile );
//	}
	else
	{
		//	printf( "Race length is to small or large\n" );
		//	perror( "Invalid race length\n");
		//	exit( EXIT_FAILURE );
	}
	printf( "Done!\n" );
	perror( "Set Race Finished!\n" );
}
