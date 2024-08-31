// Dilara Sen, sen1@kenyon.edu
// August 31, 2024

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to sort the characters of a string
string sortString(const string &str) {
  string sorted_str = str;
  sort(sorted_str.begin(), sorted_str.end());
  return sorted_str;
}

// Function to check if two words are anagrams
bool areAnagrams(const string &word1, const string &word2) {
  return sortString(word1) == sortString(word2);
}

// Function to find and return all anagrams in the file
vector<string> findAnagrams(const string &word, const string &filename) {
  ifstream file(filename);
  vector<string> anagrams;
  string line;

  if (!file.is_open()) {
    cerr << "Error: Could not open the file " << filename << endl;
    return anagrams;
  }

  while (getline(file, line)) {
    if (areAnagrams(word, line)) {
      anagrams.push_back(line);
    }
  }

  file.close();
  return anagrams;
}

int main() {
  string word, filename;

  // Get the word from the user
  cout << "Enter a word: ";
  cin >> word;

  // Get the filename from the user
  cout << "Enter the filename containing the list of words: ";
  cin >> filename;

  // Find anagrams in the file
  vector<string> anagrams = findAnagrams(word, filename);

  // Open the text file to save the results and append to it
  ofstream outputFile("testruns.txt", ios::app);

  // Check if the text file opened successfully
  if (!outputFile.is_open()) {
    cerr << "Error: Could not open the output file testruns.txt" << endl;
    return 1;
  }

  // Output the results to the console and to the testruns file
  if (anagrams.empty()) {
    cout << "No anagrams found for the word '" << word << "' in the file." << endl;
    outputFile << "No anagrams found for the word '" << word << "' in the file." << endl;
  } else {
    cout << "Anagrams found for the word '" << word << "':" << endl;
    outputFile << "Anagrams found for the word '" << word << "':" << endl;

    int count = 1; // Initialize counter for number of anagrams found

    for (const string &anagram : anagrams) {
      cout << count << ". " << anagram << endl; // Write to console
      outputFile << count << ". " << anagram << endl; // Write to output
      count++; // Incrementor for number
    }
  }

  outputFile.close(); // Close the output file

  return 0;
}
