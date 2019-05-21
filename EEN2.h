#ifndef _EEN2_H_
#define _EEN2_H_

int ValidateEntityFile( )
{
	char *pointer;

	pointer=strstr( FileString,EntityIdentifier );
	if( pointer != NULL && pointer > 0 ) 
	{
		debugf( "File has a valid Entity identifier." );
	}
	else
	{
		printf( "File is either corrupt, not an Entity file, or or the wrong Entity version." );
		exit( EXIT_FAILURE );
	}
	return 1;
}

#endif
