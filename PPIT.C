// Project Presidents - Inauguration Tool CRT,ITM,&RLE Test written in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	char /*ch, */source_file_name[256]/*, target_file_name[256]*/; // The name of the files to input and output
	char race_input[3]/*, gender_input[1], body_input[7]*/; // The values to be changed
	FILE *source_file/*, *target_file*/; // The files to be input and output

struct CRT { // CRT File: For NPCs, Creatures, and PC
	int IsNPC;
	int IsPC;
	int Name;
	int Race;
	int Gender;
	int Body;
};

struct ITM { // ITM file: WEA, ITM, ??CHM??
	int AMO;
	int WEA;
	int CHM;
	int Name;
	int Icon;
	int Texture;
	int Model;
};

struct RLE { // Pip-boy mini-map file
	int HEAD;
	int LGTD
	int INFO;
	int LGTR;
};

void CRTEdit()
{
	printf( "CRT Edit called.\n" ); // Development Feature - Delete
	fflush( source_file_name )
	printf("Enter the name of the .CRT file you wish to modify.\n");
	fgets( source_file_name, sizeof( source_file_name ), stdin ); // Input File name to be imported
	source_file_name[strlen(source_file_name)-1] = 0x00; // something to do with string length

	printf("Reading Input File...\n");
	source_file = fopen(source_file_name,"r+"); // read+write binary mode
   
	if( source_file == NULL )
	{
		perror("Error while reading the file.\n");
		exit(EXIT_FAILURE);
	}

	
}
void RLEEdit()
{
    printf( "RLE Edit called.\n" ); // Development Feature - Delete
	
}
void SetRace()
{
	printf( "Enter the desired 3-character race type.\n" );
	fgets( race_input, sizeof( race_input ), stdin ); // Input new race type
	printf( "Current race type : %s", race_input ); // Development Feature - Delete

//	printf( "Making Changes...\n" );
//	fseek( source_file, 14, SEEK_SET ); // Moving pointer for race - Only for PCFemale.CRT

//	printf( "%ld\n", ftell( source_file ) ); // Development Feature - Delete
//	fputs( race_input, source_file );
	printf( "Done!\n" );
}
void SetGender()
{
    printf( "Set Gender called.\n" ); // Development Feature - Delete
//	printf( "Enter the desired 1-character gender type.\n" );
//	fgets( gender_input, sizeof( gender_input ), stdin ); // Input new gender type
//	printf( "Current gender type : %s", gender_input ); // Development Feature - Delete

//	printf( "Making Changes...\n" );
//	fseek( source_file, 17, SEEK_SET ); // Moving pointer for gender - Only for PCFemale.CRT

//	printf( "%ld\n", ftell( source_file ) ); // Development Feature - Delete
//	fputs( gender_input, source_file );
	printf( "Done!\n" );
}
void SetBody()
{
    printf( "Set Body called.\n" ); // Development Feature - Delete
//	printf( "Enter the desired 3-character body type.\n" );
//	fgets( body_input, sizeof( body_input ), stdin ); // Input new body type
//	printf( "Current body type : %s", body_input ); // Development Feature - Delete

//	printf( "Making Changes...\n" );
//	fseek( source_file, 18, SEEK_SET ); // Moving pointer for body - Only for PCFemale.CRT

//	printf("%ld\n", ftell( source_file ) ); // Development Feature - Delete
//	fputs( body_input, source_file );
	printf( "Done!\n" );
}
void HexView()
{
    printf( "Hex View called.\n" ); // Development Feature - Delete
//	int i;
	
//	printf( "Hex View of Input %s File :\n", source_file_name );
//	while( ( ch = fgetc( source_file ) ) != EOF )
//	{
//		printf( "%02X \n",ch );
//		if( !( ++i % 16 ) ) putc( '\n', stdout );
//	}
}

void Disclaimer()
{
	printf( "This program is still in development.\n" );
	printf( "Many features don't work or are highly experimental.\n" );
	printf( "Right now, just consider this program a proof-of-concept.\n" );
	printf( "All things are liable to change, thank you.\n" );
}
void CRTEditMenu()
{
	int EditMenuInput;
	printf( "Inauguration Tool CRT Editing Menu\n" );
	printf( "1. Edit Race\n" );
	printf( "2. Edit Gender\n" );
	printf( "3. Edit Body\n" );
	printf( "4. Hex View\n" );
	printf( "5. Exit\n" );
	printf( "Note: Please refer to Technical Info.txt\n" );
	scanf( "%d", &EditMenuInput );
	printf( "Input is %d\n", EditMenuInput ); // Development Feature - Delete
	switch ( EditMenuInput ) {
		case 1:
			SetRace();
			break;
		case 2:
			SetGender();
			break;
		case 3:
			SetBody();
			break;
		case 4:
			HexView();
			break;
		case 5:
			printf( "Thank you for using this program.\n" );
			break;
		default:
			printf( "Error, Done!\n " );
//			perror( "Error, quitting!\n " );
//			exit( EXIT_FAILURE );
			break;
	}
}
int main(void)
{
	int StartMenuInput;
	Disclaimer()
	printf( "Inauguration Tool Start Menu\n" );
	printf( "1. Load a RLE to Edit\n" );
	printf( "2. Load a ITM to Edit\n" );
	printf( "3. Exit\n" );
	printf( "Note: Please refer to Technical Info.txt\n" );
	scanf( "%d", &StartMenuInput );
	printf( "Input is %d\n", StartMenuInput ); // Development Feature - Delete
	switch ( StartMenuInput ) {
		case 1:
			CRTEdit();
			break;
		case 2:
			ITMEdit();
			break;
		case 3:
			printf( "Thank you for using this program.\n" );
			break;
		default:
			printf( "Error, Done!\n " );
//			perror( "Error, quitting!\n " );
//			exit( EXIT_FAILURE );
			break;
	}
//	CRTEditMenu();
	getchar();
//	return 0;
	
/*
	source_file_name[strlen(source_file_name)-1] = 0x00; // something to do with string length

	printf("Reading Input File...\n");
	source_file = fopen(source_file_name,"r+"); // read+write binary mode
   
	if( source_file == NULL )
	{
		perror("Error while reading the file.\n");
		exit(EXIT_FAILURE);
	}

//	printf("Enter the name of the .CRT file to be exported.\n");
//	fgets(target_file_name, sizeof(target_file_name), stdin);; // Input File name to be exported

//	target_file = fopen(target_file_name,"ab+"); // Open or create file for writing
//	printf("Creating backup of file...\n");

//	if( target_file_name == NULL )
//	{
//		fclose(source_file);
//		perror("Error while creating and reading backup.\n");
//		exit(EXIT_FAILURE);
//	}
	
//	while ((ch = fgetc(source_file)) != EOF)
//	fputc(ch, target_file);

//	printf("Backup created successfully.\n");

	fclose(source_file);
// <!!FUTUREx2!!>	fclose(target_file);
   
	return(0);
*/
}
