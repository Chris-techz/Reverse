#define _CRT_SECURE_NO_WARNINGS
#ifndef REVERSE_H
#define REVERSE_H

#include <stdio.h>

class Reverse
{

private:
	//Pointer to the file content array
	int* ptFile = nullptr;
	//FILE pointer to the .txt file
	FILE* pFile = NULL;
	//FILE pointer to the .txt file
	FILE* pGlossary = NULL;
	//FILE pointer to the .txt file
	FILE* pInversed = NULL;
	//Size of the original file
	int fileSize = 0;

public:
	Reverse();
	//Destructor releasing memory
	~Reverse();
	//Open file with the path passed in argument, get the lenght of the file to allocate memory to it
	void OpenFile(char* path);
	//Load the file content in memory to exploit it
	void LoadFile(char* path);
	//Display the file on output, to find errors (display bugs, solved)
	void DisplayFile();
	//Store the words of the file in a glossary file, without the one letter words
	void Glossary();
	//Sort glossary, not done
	void Occurrence();
	//Invert each words of the original file, must be perfected
	void Inversed();
};

#endif REVERSE_H
