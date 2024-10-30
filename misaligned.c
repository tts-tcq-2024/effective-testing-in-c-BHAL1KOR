#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct {
    int pairNumber;
    char majorColor[8];
    char minorColor[8];
} ColorPair;

const char* ExpectedColorPair =
        "0 | White  | Blue  \n"
        "1 | White  | Orange\n"
        "2 | White  | Green \n"
        "3 | White  | Brown \n"
        "4 | White  | Slate \n"
        "5 | Red    | Blue  \n"
        "6 | Red    | Orange\n"
        "7 | Red    | Green \n"
        "8 | Red    | Brown \n"
        "9 | Red    | Slate \n"
        "10 | Black  | Blue  \n"
        "11 | Black  | Orange\n"
        "12 | Black  | Green \n"
        "13 | Black  | Brown \n"
        "14 | Black  | Slate \n"
        "15 | Yellow | Blue  \n"
        "16 | Yellow | Orange\n"
        "17 | Yellow | Green \n"
        "18 | Yellow | Brown \n"
        "19 | Yellow | Slate \n"
        "20 | Violet | Blue  \n"
        "21 | Violet | Orange\n"
        "22 | Violet | Green \n"
        "23 | Violet | Brown \n"
        "24 | Violet | Slate \n";


void generateColorMap(ColorPair colorMap[], int* size) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0, index = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            colorMap[index].pairNumber = index + 1;
            strcpy(colorMap[index].majorColor, majorColor[i]);
            strcpy(colorMap[index].minorColor, minorColor[j]);
            index++;
        }
    }
    *size = index;
}

void printColorMap(ColorPair colorMap[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%2d | %-6s | %-6s\n", colorMap[i].pairNumber, colorMap[i].majorColor, colorMap[i].minorColor);
    }
}

int main() {
    ColorPair colorMap[25];
    int size = 0;
    generateColorMap(colorMap, &size);
    assert(size == 25);
    strcmp(colorMap, ExpectedColorPair) == 0);

    printColorMap(colorMap, size);
    printf("All is well (maybe!)\n");
    return 0;
}
