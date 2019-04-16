// Project Presidents - Inauguration Tool CRT,ITM,&RLE Test written in C

#include "Global.h"
#include "FileManagement.h"

//#include "SetGender.H"
//#include "SetBody.H"

//#include "SetStrength.H"
//#include "SetPerception.H"
//#include "SetEndurance.H"
//#include "SetCharisma.H"
//#include "SetIntelligence.H"
//#include "SetAgility.H"
//#include "SetLuck.H"

void CleanUp( )
{
	printf( "Cleaning up...\n" );
//	#ifdef BUILD_LINUX
	system( "clear" );// Unix/Linux build
//	#else
//	system( "cls" );// Windows build
//	#endif // BUILD_LINUX
}

void HexView( ) // Calls up a Hexidecimal view of the current file, gets odd FFFFFF artifacts
{
	perror( "Hex View Called.\n" );
	int i;

	printf( "Hex View of Input %s File :\n", InputFileName );
	while( ( ch = fgetc( InputFile ) ) != EOF )
	{
		printf( "%02X ",ch );
		if( !( ++i % 16 ) ) putc( '\n', stdout );
	}
	printf( "Done!\n" );
	printf( "Hex View Finished!\n" );
}

void PPITDisclaimer( ) // Simply just lets the user know this program is highly experimental and is a WIP
{
	printf( "Many features in this program don't work or are highly experimental.\n" );
	printf( "Right now, just consider this program a proof-of-concept/rough draft.\n" );
	printf( "All things are liable to change, thank you!\n" );
}

#include "CRT.h"
//#include "RLE.h"
//#include "ITM.h"

void StartMenu( )
{
	do
	{
		int StartMenuInput;
		printf( "%s version %s\n",TITLE,VERSION );
		PPITDisclaimer( );
		printf( "-----------------------------\n" );
		printf( "Inauguration Tool Start Menu\n" );
		printf( "NOTE: Please refer to Technical Info.txt\n" );
		printf( "-----------------------------\n" );
		printf( "Inauguration Tool Test Menu - ITM\n" );
		printf( "-----------------------------\n" );
		printf( "1. Load a Human CRT to Edit\n" );
//		printf( "2. *DISABLED* Load an ITM to Edit\n" );
//		printf( "3. *DISABLED* Load a RLE to Edit\n" );
        	printf( "-----------------------------\n" );
		printf( "4. Write errors to external log file(for this session)\n" );
		printf( "5. Toggle file export(for this session)\n" );
	        printf( "-----------------------------\n" );
		printf( "6. Exit\n" );
		scanf( " %d", &StartMenuInput );
		getchar( );
		switch ( StartMenuInput )
		{
			case 1:
				CRTLoad( );
				CRTExport( );
				break;
			case 2:
//				ITMEdit( );
				printf( "Disabled, Quitting!\n" );
				exit( EXIT_SUCCESS );
				break;
			case 3:
//				RLEEdit( );
				printf( "Disabled, Quitting!\n" );
				exit( EXIT_SUCCESS );
				break;
			case 4:
				freopen( "error.log", "w", stderr );
				printf( "Log file created.\n");
				break;
			case 5:
				printf( "Not Finished Yet.\n" );
				break;
			case 6:
				printf( "Thank you for using this program.\n" );
				break;
				exit( EXIT_SUCCESS );
			default:
				printf( "No Valid Input, Quitting!\n " );
				exit( EXIT_FAILURE );
				break;
		}
    		printf( "Restart?(Y/N): \n" );
			char RestartPrompt ='y';
    		scanf( " %c", &RestartPrompt );
    		getchar();

    		if ( RestartPrompt == 'n'|| RestartPrompt == 'N' )
                Restart = 1;
	}
	while( !Restart );
		CleanUp( );
		printf( "Thank you for using this program.\n" );
		printf( "Please report any suggestions or bugs to the Discord.\n");
		exit ( EXIT_SUCCESS );
}
int main( void )
{
	StartMenu( );
	return 0;
}
