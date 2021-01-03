#ifndef _EEN2_H_
#define _EEN2_H_

int ValidateEntityFile( )
{
	debugf( "Checking for valid Entity identifier." );

	fseek( InputFile, 0, SEEK_SET );
	fread( EntityIdentifier, 4, 1, InputFile );
	if ( EntityIdentifier[0] == 0x45 && EntityIdentifier[1] == 0x45 && EntityIdentifier[2] == 0x4E && EntityIdentifier[3] == 0x32 )
	{ 
		debugf( "File has a valid Entity identifier." );
	}
	else
	{
		printf( "File is either corrupt, not an Entity file, or the wrong Entity version." );
		exit( EXIT_FAILURE );
	}
	return 1;
}

#endif
