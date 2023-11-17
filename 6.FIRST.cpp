#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_NON_TERMINALS 10
#define MAX_RULES 20

// Structure to represent the FIRST set for non-terminals
typedef struct {
    char nonTerminal;
    bool isTerminalSet[26];  // Assuming uppercase letters as terminals
} FirstSet;

// Structure to represent the grammar rule
typedef struct {
    char nonTerminal;
    char production[50];
} GrammarRule;

// Function to initialize FIRST sets
void initializeFirstSets(FirstSet* firstSets, int numNonTerminals) {
    for (int i = 0; i < numNonTerminals; i++) {
        firstSets[i].nonTerminal = 'A' + i;
        for (int j = 0; j < 26; j++) {
            firstSets[i].isTerminalSet[j] = false;
        }
    }
}

// Function to compute FIRST sets
void computeFirstSets(FirstSet* firstSets, int numNonTerminals, GrammarRule* rules, int numRules) {
    bool updated;
    do {
        updated = false;
        for (int i = 0; i < numRules; i++) {
            char nonTerminal = rules[i].nonTerminal;
            char firstSymbol = rules[i].production[0];
            
            int nonTerminalIndex = nonTerminal - 'A';
            int firstSymbolIndex = firstSymbol - 'A';

            if (isupper(firstSymbol) && nonTerminal != firstSymbol) {
                for (int j = 0; j < 26; j++) {
                    if (firstSets[firstSymbolIndex].isTerminalSet[j] && !firstSets[nonTerminalIndex].isTerminalSet[j]) {
                        firstSets[nonTerminalIndex].isTerminalSet[j] = true;
                        updated = true;
                    }
                }
            } else if (firstSymbol == 'e') {
                if (!firstSets[nonTerminalIndex].isTerminalSet[0]) {
                    firstSets[nonTerminalIndex].isTerminalSet[0] = true;
                    updated = true;
                }
            } else if (islower(firstSymbol) && !firstSets[nonTerminalIndex].isTerminalSet[firstSymbol - 'a']) {
                firstSets[nonTerminalIndex].isTerminalSet[firstSymbol - 'a'] = true;
                updated = true;
            }
        }
    } while (updated);
}

// Function to print FIRST sets
void printFirstSets(FirstSet* firstSets, int numNonTerminals) {
    for (int i = 0; i < numNonTerminals; i++) {
        printf("FIRST(%c) = { ", firstSets[i].nonTerminal);
        bool printed = false;
        for (int j = 0; j < 26; j++) {
            if (firstSets[i].isTerminalSet[j]) {
                if (printed) {
                    printf(", ");
                }
                printf("%c", 'A' + j);
                printed = true;
            }
        }
        if (firstSets[i].isTerminalSet[0]) {
            if (printed) {
                printf(", ");
            }
            printf("e");
        }
        printf(" }\n");
    }
}

int main() {
    int numNonTerminals = 3;
    FirstSet firstSets[MAX_NON_TERMINALS];
    initializeFirstSets(firstSets, numNonTerminals);

    int numRules = 5;
    GrammarRule rules[MAX_RULES] = {
        {'A', "Ba|b"},
        {'B', "Cc|c"},
        {'C', "aB|B|e"},
        {'B', "d|e"},
        {'C', "d|e"}
    };

    computeFirstSets(firstSets, numNonTerminals, rules, numRules);
    printFirstSets(firstSets, numNonTerminals);

    return 0;
}

