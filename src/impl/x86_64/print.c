#include "print.h"
const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;
struct Char {
    uint8_t character;
    uint8_t color;
};
struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 1;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;
void clear_row(size_t row) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };
    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}
// Clears Screen
void print_clear() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
}
// Adds new row to stdout
void print_newline() {
    col = 0;
    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }
    for (row; row < NUM_ROWS; row++) {
        for (col; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }
    clear_row(NUM_COLS - 1);
}
// prints char to stdout 
void print_char(char character) {
    if (character == '\n') {
        print_newline();
        return;
    }
    if (col > NUM_COLS) {
        print_newline();
    }
    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };
    col++;
}
// prints string to std out 
void print_str(char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];
        if (character == '\0') {
            return;
        }
        print_char(character);
    }
}
// First declare the background of the text, then the color of the text itself
void print_set_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}

void print_kmsg(_Bool success, char* msg) {
	if (success) {
		print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
		print_str("[ ");
		print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_WHITE);
		print_str("OK ");
		print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
		print_str("] ");
		print_str(msg);
	} else {
		
		print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
		print_str("[ ");
		print_set_color(PRINT_COLOR_RED, PRINT_COLOR_WHITE);
		print_str("FAIL ");
		print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
		print_str("] ");
		print_str(msg);
	}
}
}

