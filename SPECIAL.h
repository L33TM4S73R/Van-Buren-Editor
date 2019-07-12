#ifndef _SPECIAL_H_
#define _SPECIAL_H_

int GetSPECIALStrengthValuePosition( )
{
//	Method of acquiring position
	debugf( "CRT Gender Location: %d", CRTStrengthValuePosition );
	return 1;
}

int GetSPECIALStrengthValue( )
{
	debugf( "GetStrengthValue Called" );

	fseek( InputFile, CRTStrengthValuePosition, SEEK_SET );
	fread( CRTStrengthValueSession, 2, 1, InputFile );
	fseek( InputFile, 0, SEEK_SET );

	return 1;
}

void SPECIALEditMenu( )
{
	int SPECIALEditMenuInput;
	printf( "Inauguration Tool Editing Menu - SPECIAL\n" );
	printf( "-----------------------------\n" );
	printf( "Strength Location: %d, Strength  Value: %s\n", CRTStrengthValuePosition, CRTStrengthValueSession );
	printf( "Perception Location:     0, Perception Value:    5\n" ); // Placeholder, proof of concept
	printf( "Endurance Location:      0, Endurance Value:     5\n" ); // Placeholder, proof of concept
	printf( "Charisma Location:       0, Charisma Value:      5\n" ); // Placeholder, proof of concept
	printf( "Intelligence Location:   0, Intelligence Value:  5\n" ); // Placeholder, proof of concept
	printf( "Agility Location:        0, Agility Value:       5\n" ); // Placeholder, proof of concept
	printf( "Luck Location:           0, Luck Value:          5\n" ); // Placeholder, proof of concept
	printf( "-----------------------------\n" );
	printf( "1. *WIP* Edit Strength\n" );
	printf( "2. *WIP* Edit Perception\n" );
	printf( "3. *WIP* Edit Endurance\n" );
	printf( "4. *WIP* Edit Charisma\n" );
	printf( "5. *WIP* Edit Intelligence\n" );
	printf( "6. *WIP* Edit Agility\n" );
	printf( "7. *WIP* Edit Luck\n" );
	printf( "-----------------------------\n" );
	printf( "8. Exit\n" );
	scanf( " %d", &SPECIALEditMenuInput );
	getchar( );
	switch ( SPECIALEditMenuInput )
	{
		case 1:
			SetStrength( );
			printf( "Disabled, Quitting!\n " );
			exit( EXIT_SUCCESS );
			break;
		case 2:
			printf( "Disabled, Quitting!\n " );
			exit( EXIT_SUCCESS );
			break;
		case 3:
			printf( "Disabled, Quitting!\n " );
			exit( EXIT_SUCCESS );
			break;
		case 4:
			printf( "Disabled, Quitting!\n " );
			exit( EXIT_SUCCESS );
			break;
		case 5:
			printf( "Disabled, Quitting!\n " );
			exit( EXIT_SUCCESS );
			break;
		case 6:
			printf( "Disabled, Quitting!\n " );
			exit( EXIT_SUCCESS );
			break;
		case 7:
			printf( "Disabled, Quitting!\n " );
			exit( EXIT_SUCCESS );
			break;
		case 8:
			Quit( );
			break;
		default:
			printf( "No Valid Input, Quitting!\n " );
			exit( EXIT_FAILURE );
			break;
	}
}

#endif
