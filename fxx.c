#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Text colour
#define RED 		"\033[0;31m"
#define GREEN 		"\033[0;32m"
#define YELLOW 		"\033[0;33m"
#define BLUE 		"\033[0;34m"
#define PURPLE 		"\033[0;35m"
#define CYAN  		"\033[0;36m"
#define WHITE		"\033[0;37m"
#define RESET		"\033[0m"

//Testing changes
int Hex_View(unsigned char* Bin, int Size, int Line_Width)
{
	int Line_Count = 0;
	for(int i = 0; i < Size; i++)
	{
		if(Line_Count == Line_Width) { printf("\n"); Line_Count = 0; }
		printf("%02X ", Bin[i]);
		Line_Count++;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	unsigned char* Buffer;
	int FileSize;
	if(argc == 2)
	{
		FILE* file = fopen(argv[1], "rb");
		if(file == NULL) { printf("\n %s[ERROR] File does not exist%s\n", RED, RESET);  return 1;}
		fseek(file, 0L,SEEK_END);
		FileSize = ftell(file);
		fseek(file, 0L, SEEK_SET);

		Buffer = (char*)calloc(FileSize, sizeof(char));
		if(Buffer == NULL) { printf("[ERROR ALLOC] Could not allocate memory\n"); return 2;}
		fread(Buffer, sizeof(char), FileSize, file);
		fclose(file);

		Hex_View(Buffer, FileSize, 16);

		free(Buffer);
	}

	if(argc == 4)
	{
		if (strcmp(argv[2] , "-c") == 0)
		{
			int FileSize_comp;
			FILE* file = fopen(argv[1], "rb");
			FILE* file_comp = fopen(argv[3], "rb");
			if(file == NULL || file_comp == NULL) { printf("\n %s[ERROR] File does not exist%s\n", RED, RESET);  return 1;}
			fseek(file, 0L, SEEK_END);
			fseek(file_comp, 0L, SEEK_END);
			FileSize = ftell(file);
			FileSize_comp = ftell(file_comp);
			if(FileSize != FileSize_comp) { printf("File 1 Size : %d :::%s File 2 Size : %d %s\n", FileSize, RED, FileSize_comp, RESET); }
			if(FileSize == FileSize_comp) { printf("%sFile 1 Size : %d ::: File 2 Size : %d %s\n", GREEN, FileSize, FileSize_comp, RESET); }
			
		}
	}
	

	printf("arg 1 : %s arg 2 : %s arg 3 : %s\n", argv[1], argv[2], argv[3]);
	printf("\nFilename : %s Size : %d \n", argv[1], FileSize);

	return 0;

}
