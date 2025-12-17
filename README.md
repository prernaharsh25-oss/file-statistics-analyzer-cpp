# file-statistics-analyzer-cpp

# PROJECT DISCRIPTION
A C++ text file analysis tool implementing, file handling, hash-based frequency mapping and string processing to display word statistics.

# FEATURES
  # Word Frequency Analysis 
   It counts how many times each word appears in the file using unordered_map.
  # Case-sensitive and Case-insensitive Analysis
   Allows users to choose whether words with different cases should be treated as same or not.
   Converts text to lowercase when case-insensitive mode is selected.
  # Displaying the word-file statistics 
   Finds total word count, longest word detection, Average word length calculation.
  # Special character handling
   Filters out special characters and punctuation to ensure accurate word analysis.

# TECHNOLIGIES USED
   Language- C++
   Concepts- File Handling
             Hashing
             Strings and character processing
             Functions and Modular programming

# TIME AND SPACE COMPLEXITY
  Time Complexity-
   O(n) where n is the number of words in the file.
  Space Complexity-
   O(n) for storing word frequencies in the unordered map, where n is the number of unique words.
   
# HOW TO RUN THE PROJECT
  1. Clone the repository
     <https://github.com/prernaharsh25-oss/file-statistics-analyzer-cpp>
  2. Compile the code
     g++ main.cpp -o analyzer
  4. Run the executable
     ./analyzer
  6. input file in the same directory

# FUTURE IMPROVEMENTS
 Add sentence and paragraph analysis
 Support multiple file formats
 Export statistics to a separate output file
 Add a menu-driven interface

     
     
   
 
 
   
