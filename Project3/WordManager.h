#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>

class WordManager
{
public:
    WordManager(); // Constructor

    void addWordToManager(std::string word);    // Add a word to the manager

    void loadFromFile(std::string filename);    // Load words from a file and add them to the manager

    void exportToFile(std::string filename);    // Export the word manager data to a file

    int getCountOfWord(std::string word);       // Get the count of a specific word in the manager

    void printAllWords(bool addStyle);          // Print all words in the manager, optionally with styling

private:
    std::map<std::string, int> wordManager;     // Map to store word count
};

