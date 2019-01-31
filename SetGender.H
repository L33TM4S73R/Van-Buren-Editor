void SetGender()
{
	long int CRTGenderInputScan;

	perror( "Set Gender Called.\n" );
	printf( "Enter the desired 1-character gender type.\n" );
//	fflush(stdin);
	scanf( "%d",&CRTGenderInputScan);
//	fgets( gender_input, sizeof( gender_input ), stdin ); // Input new gender type

//	printf( "Current gender type : %s", CRTGenderInputScan ); // Find a way to translate to perror

//	printf( "Making Changes...\n" );
//	fseek( InputFile, 17, SEEK_SET ); // Moving pointer for gender - Only for PCFemale.CRT
//  fseek( InputFile, CharGenderLocation, SEEK_SET ): // CharGenderLocation is 17 in PCFemale.CRT
//	printf( "%ld\n", ftell( InputFile ) ); // Find a way to translate to perror
//	fputs( gender_input, InputFile );
	printf( "Done!\n" );
	perror( "Set Gender Finished!\n" );
}
