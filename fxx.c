#include <stdio.h>
#include <stdlib.h>
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
	char* Buffer;
	int FileSize;
	if(argc == 2)
	{
		FILE* file = fopen(argv[1], "rb");
		if(file == NULL) { printf("\n [ERROR] File does not exist\n");  return 1;}
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
	


	printf("\nFilename : %s Size : %d \n", argv[1], FileSize);

	return 0;

}
