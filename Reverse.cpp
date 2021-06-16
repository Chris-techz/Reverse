#include "Reverse.h"

//Methods has been programmed in this order

Reverse::Reverse()
{
	//Default constructor
}

Reverse::~Reverse()
{
	//Destructor
	delete[] ptFile;
	delete pFile;
}

void Reverse::OpenFile(char* path)
{
	pFile = NULL;
	//temporary variable to read characters and know the file lenght
	int nbc = 0;	
	//open the file, reading mode
	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		//Acquire the lenght of the file
		do						
		{
			nbc = fgetc(pFile);
			fileSize++;
		} while (nbc != EOF);

		//allocation of the file array in memory
		int* myFile = new int[fileSize];
		//pointer to navigate the array
		ptFile = myFile;
		//close file
		fclose(pFile);
	}
	else
		printf("Error opening file (Error : unable to know file size\n");
}

void Reverse::LoadFile(char* path)
{
	pFile = NULL;
	//open the file, reading mode
	pFile = fopen(path, "r");

	if (pFile != NULL)
	{
		//Write the file content in the array
		for(int i = 0; i < fileSize; i++)
		{
			*(ptFile + i) = fgetc(pFile);
		}
		fclose(pFile);
	}
	else
		printf("Error opening file (Error : unable to load in memory\n");
}

void Reverse::DisplayFile()
{
	//Print the file content in output
	for (int i = 0; i < fileSize - 1; i++)
	{
		printf("%c", *(ptFile + i));
	}
}

void Reverse::Glossary()
{
	pGlossary = NULL;
	//Create a new document if it doesn't exit, to store every words of the original file (without one letter words)
	pGlossary = fopen("Glossaire.txt", "w");
	//Variable to know words lenght
	int wordSize = 0;

	if (pGlossary != NULL)
	{
		for (int i = 0; i < fileSize - 1; i++)
		{
			if(*(ptFile + i) == 32 || *(ptFile + i) == 39)	//if current char is an space or an apostrophe, line break
			{
				fputc(10, pGlossary);
				//reset word lenght, next word
				wordSize = 0;
			}
			else if (wordSize < 1 && *(ptFile + (i + 1)) == 39)	//if the words is currently one character long and finished
			{	
				//reset word lenght, next word
				wordSize = 0;
			}
			else                                               //the word is valid, write it in the glossary
			{									
				wordSize++;
				fputc(*(ptFile + i), pGlossary);
			}
		}
		fclose(pGlossary);
	}
	else
		printf("Error opening file\n");
}

void Reverse::Occurrence()	//Part of the exercice I haven't done
{
	pGlossary = NULL;
	pGlossary = fopen("Glossaire.txt", "r");

	if (pGlossary != NULL)
	{
		
	}
	else
		printf("Error opening file");
}

void Reverse::Inversed()
{
	pInversed = NULL;
	//Create a new document to store the original file but inversed
	pInversed = fopen("sample.reverse.txt", "w");

	//temporary array to store and invert the word, before writing it in the inversed file, 64 = max word lenght,
	//it's small so I don't allocate it
	int tempWord[64] = { 0 };
	int wordSize = 0;

	if (pInversed != NULL)
	{
		for (int i = 0; i < fileSize; i++)
		{
			if (*(ptFile + i) == 32)	//if current char is an space
			{
				for (int k = wordSize; k >= 0; k--)
				{
					//Write the current word upside down
					fputc(tempWord[k], pInversed);
					//Reset the temp array
					tempWord[k] = 0;
				}
				//write space
				fputc(32, pInversed);
				//Reset the word size
				wordSize = 0;
			}
			else if (*(ptFile + i) == 10)   //if current character is a line break, write line break, it didn't work before i write this 
			{
				fputc(10, pInversed);
			}
			else
			{
				//Load the current word to invert it
				tempWord[wordSize] = *(ptFile + i);
				wordSize++;
			}
		}
		fclose(pInversed);
	}
	else
		printf("Error opening file (Error: unable to invert the file\n");
}	