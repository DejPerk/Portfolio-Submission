#include "WordManager.h"

WordManager::WordManager() {}

void WordManager::addWordToManager(std::string word) {

	// Check if the word exists in the word manager
	if (WordManager::wordManager.find(word) != WordManager::wordManager.end()) {
		WordManager::wordManager[word] += 1;	// Word exists, increment the count
	}
	else {
		WordManager::wordManager[word] = 1;		// Word does not exist, add it with a count of 1
	}

}

void WordManager::loadFromFile(std::string filename) {
	std::ifstream inputFile(filename);		// open the file as an input , so it can be read

	if (!inputFile) {						// check if the file opening is succesful or not
		std::cout << "The input file can not be opened!" << std::endl;		// print the error if not successful
		return;				// return from the function
	}

	std::string word;		// get a variable to read the strings
	while (inputFile >> word) {		// read lines while runing out of lines
		addWordToManager(word);		// add the word to the manager
	}

	inputFile.close();		// close the file
}

void WordManager::exportToFile(std::string filename) {
	std::ofstream outputFile(filename);		// open the file as an output , so it can be written

	if (!outputFile) {						// check if the file opening is succesful or not
		std::cout << "The output file can not be opened!" << std::endl;		// print the error if not successful
		return;				// return from the function
	}

	for (const auto& pair : WordManager::wordManager) {	// read every pair in the wordmanger map
		outputFile << pair.first << ": " << pair.second << std::endl;	// write the word and the count to the output file
	}

	outputFile.close();		// close the file

	std::cout << "Backup process completed!" << std::endl;	// print the success message
}	

int WordManager::getCountOfWord(std::string word) {
	
	if (WordManager::wordManager.find(word) != WordManager::wordManager.end()) {	// check if the word is in the map or not
		return WordManager::wordManager[word];	// if it is in the map, return the count
	}
	else {
		return 0;	// if not in the map, return 0
	}

}

void WordManager::printAllWords(bool addStyle) {
	
	for (const auto& pair : WordManager::wordManager) {		// go through every pair in the map
		std::cout << pair.first << " ";		// print the word first
		if (!addStyle) {					// check if the style is required
			std::cout << pair.second;		// if style is not required, print the count
		}
		else {								// if style is required
			for (int i = 0;i < pair.second;i++) {	// go through a number of times for the word count
				std::cout << "*";			// print the *
			}
		}
		std::cout << std::endl;				// print a new line
		
	}

}

