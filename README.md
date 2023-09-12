# system-prog-lab-1

# Variant number 12

# Text File Word Processor

This GitHub repository contains a simple text file word processor that processes a text file with no size restrictions and words separated by various delimiters. The objective is to extract unique words from the file based on certain criteria and sort them in ascending order of the number of consonants in each word.

## How it Works

The text file processor is designed to handle large text files with words of up to 30 characters in length. It performs the following steps:

1. **Input File**: You provide the name of the text file you want to process.

2. **Word Extraction**: The program reads the file and extracts words from it, ignoring non-alphabet characters and special symbols. It uses a delimiter-based approach to identify and separate words.

3. **Uniqueness Check**: For each extracted word, the program checks if it's unique by comparing it to previously processed words. Duplicate words are excluded.

4. **Consonant Count**: The program calculates the number of consonants in each unique word. It does not consider the case of letters and does not account for proper spelling.

5. **Sorting**: All unique words are sorted in ascending order based on the number of consonants using a sorting algorithm.

6. **Output**: The sorted list of unique words, along with the count of consonants in each word, is displayed as the final result.
