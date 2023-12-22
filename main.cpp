#include <iostream>
#include <cstring>
using namespace std;


int getWordLength(char arr[]) {
    unsigned L = 0;
     while (arr[L]) ++L;
     return L;
}

bool checkSymbolInWord(const char* arr, char symbol) {
    const char* ptr = arr;
    for (size_t i = 0; *ptr != '\0'; ++i) {
        if (*ptr == symbol) {
            return true;
        }
        ++ptr;
    }
    return false;
}

void clearArray(char arr[], const int size) {
    memset(arr, 0, size);
}

int countOccurrences(const char* arr, char el) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == el) {
            count++;
        }
    }
    return count;
}

void findSubstring(const char* arr, const char* needle, const int arrSize, const int needleSize) {
    for (int i = 0; i <= arrSize - needleSize; ++i) {
        bool found = true;
        for (int j = 0; j < needleSize; ++j) {
            if (arr[i + j] != needle[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << "\nfind one on " << i + 1 << "-" << i + 1 + needleSize << " position\n";
            found = false;
        }
    }
}

char getCharForDigit(int digit) {
    return 'a' + (digit - 1);
}

void replaceDigitsWithLetters(char arr[]) {
    for (int i = 0; arr[i] != '\0'; i++) {
        if (isdigit(arr[i])) {
            arr[i] = getCharForDigit(arr[i] - '0');
        } else if (ispunct(arr[i])) {
            break;
        }
    }
}

void equateArrays(char convertibleArr[], char subArr[]) {
    for (int i = 0; convertibleArr[i] != '\0'; i++) {
        convertibleArr[i] = subArr[i];
    }
}

void getSubstring(const char arr[], char substring[], int start, int end) {
    int subIdx = 0;
    for (int i = start; i < end; i++, subIdx++) {
        substring[subIdx] = arr[i];
    }
}


int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Navigation:" << "\n"
    << "1) A sequence of characters is entered from the keyboard (maximum 50 words of 10 characters each)" << "\n"
    << "2) Editing of entered text" << "\n"
    << "3) Display only those words that contain the same letters" << "\n"
    << "4) Replace numbers in all words with letters" << "\n"
    << "5) Find substring" << "\n";

    const int MAX_SIZE = 500;
    char sequence[MAX_SIZE];
    const char punctuation[] = { '.', ';', ':', '(', ')', '!', '?', ',', '&', '*', '/', '<', '>', '?', '«', '»', '#', '^' };

    
    while(true) {
        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();
        short int workPoint;
        
        cout << "Select point of work (number 1 to 5): ";
        cin >> workPoint;

        switch (workPoint)
        {   
            case 1: {
                cout << "Enter a string:\n";
                cin.get();
                cin.getline(sequence, MAX_SIZE, '.');
                cout << "Raw text:\n" << sequence << endl;
                break;
            }
            case 2: {
                cout << "Edited text:\n";
                char editedSequence[MAX_SIZE] = {};
                if (!checkSymbolInWord(punctuation, sequence[0])) {
                    editedSequence[0] = sequence[0];
                }
                int curIndex = 1;
                for (int i = 1; i < getWordLength(sequence) + 1; i++) {
                    if (sequence[i] != ' ') {
                        if (!checkSymbolInWord(punctuation, sequence[i]) || 
                        (checkSymbolInWord(punctuation, sequence[i]) && 
                        (sequence[i - 1] == ' ' || 
                        sequence[i + 1] == ' '))) {
                            editedSequence[curIndex] = tolower(sequence[i]);
                            curIndex++;
                        }
                    } else {
                        editedSequence[curIndex] = ' ';
                        curIndex++;
                    }
                }
                cout << editedSequence << ".\n";
                equateArrays(sequence, editedSequence);
                break;
            }
            case 3: {
                int startIndex = 0;
                char ccurrentWord[MAX_SIZE] = {};

                for (int i = 0; i < getWordLength(sequence) + 1; i++) {
                    if (sequence[i] == ' ' || sequence[i] == '\0') {
                        clearArray(ccurrentWord, MAX_SIZE);
                        getSubstring(sequence, ccurrentWord, startIndex, i);
                        startIndex = i + 1;
                        for (int j = 0; j < getWordLength(ccurrentWord); j++) {
                            if (countOccurrences(ccurrentWord, ccurrentWord[j]) > 1) {
                                cout << ccurrentWord << " ";
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case 4: {   
                char currentWord[MAX_SIZE] = {};
                if (!checkSymbolInWord(punctuation, sequence[0])) {
                    currentWord[0] = sequence[0];
                }
                int curIndex = 1;
                for (int i = 1; i < getWordLength(sequence) - 1; i++) {
                    if (sequence[i] != ' ') {
                        if (!checkSymbolInWord(punctuation, sequence[i]) || 
                        (checkSymbolInWord(punctuation, sequence[i]) && 
                        (sequence[i - 1] == ' ' || 
                        sequence[i + 1] == ' '))) {
                            currentWord[curIndex] = tolower(sequence[i]);
                            curIndex++;
                        }
                    } else {
                        currentWord[curIndex] = '\0';
                        replaceDigitsWithLetters(currentWord);
                        cout << currentWord << " ";
                        curIndex = 0;
                        clearArray(currentWord, MAX_SIZE);
                    }
                }
                replaceDigitsWithLetters(currentWord);
                cout << currentWord << ".\n";
             
                break;
            }
            case 5: {
                char substring[MAX_SIZE];

                cout << "Enter a substring:\n";
                cin.get();
                cin.getline(substring, MAX_SIZE, '.');
                findSubstring(sequence, substring, getWordLength(sequence), getWordLength(substring));
                break;
            }
            default: {
                cout << "\n" << "You did not enter a number in the range from 1 to 5";
                break;
            }
        }

        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();

        char stopFlag;
        cout << "\n" << "Continue the program? (Y/N) ";
        cin >> stopFlag;
        
        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }
    
    return 0;
}
// 4 var