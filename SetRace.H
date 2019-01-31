void SetRace()
{
	char CRTRaceInputString[7];
	long int CRTRaceInputStringLength = sizeof( CRTRaceInputString );
	perror( "Set Race Called.\n" );

	printf( "Was: %s", CRTRaceInputString ); // Find a way to translate to perror
	printf( "Enter the desired 7-character race type.\n" );
	fflush(stdin);

	printf( "Race input string length: %d\n", sizeof( CRTRaceInputString )  ); // Find a way to translate to perror
	printf( "Equivalent hexadecimal number of $placeholder$ is: %02X",CRTRaceInputStringLength ); // Find a way to translate to perror

	fgets( CRTRaceInputString, sizeof( CRTRaceInputString ), stdin ); // Input new race type
	printf( "Now: %s", CRTRaceInputString ); // Find a way to translate to perror
	if( CRTRaceInputStringLength == 7 )
	{
			printf( "Making Changes...\n" );
			fseek( InputFile, 14, SEEK_SET ); // Moving pointer for race - Only for select .CRT files
		//	fseek( InputFile, CRTRaceLocation, SEEK_SET )// Moving pointer for race
			printf( "%ld\n", ftell( InputFile ) );// Find a way to translate to perror
			fputs( CRTRaceInputString, InputFile );
	}
	else
	{
		//	printf( "Race length is to small or large\n" );
		//	perror( "Invalid race length\n");
		//	exit( EXIT_FAILURE );
	}
	printf( "Done!\n" );
	perror( "Set Race Finished!\n" );
}
