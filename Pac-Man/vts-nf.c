/*
 * VTS - Virtual Terminal Sequences
 * Full implementation of https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences.
 * Some CSI / OCS are still missing.
 */

#ifndef VTS
#define VTS

#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#endif

// // Macro
#define vts_xy(x, y) vts_cursorXY(x, y);

// // Prototypes
bool vts_activateCommands();

// Miscellanous
void vts_resize(int, int);
void vts_clear();

// Cursor Positioning
void vts_cursorUp(int);
void vts_cursorDown(int);
void vts_cursorRight(int);
void vts_cursorLeft(int);
void vts_cursorNextLine(int);
void vts_cursorPreviousLine(int);
void vts_cursorHorizontalAbsolute(int);
void vts_cursorVerticalAbsolute(int);
void vts_cursorXY(int, int);
void vts_cursorSave();
void vts_cursorRestore();

// Cursor Visibility
void vts_cursorBlink();
void vts_cursorStill();
void vts_cursorShow();
void vts_cursorHide();

// Viewport
void vts_viewportUp(int);
void vts_viewportDown(int);

// Text Modification
void vts_textInsertChar(int);
void vts_textDeleteChar(int);
void vts_textEraseChar(int);
void vts_textInsertLine(int);
void vts_textDeleteLine(int);

// Text Formatting
void vts_textDefault();
void vts_textBold(); // makes bright foreground
void vts_textUnderline();
void vts_textNoUnderline();
void vts_textNegative();
void vts_textPositive();
// TODO: Test compat in windows
// void vts_textLowIntesity();
// void vts_textBlinking();
// void vts_textInvisible();

// Foreground Colors
void vts_foregroundBlack();
void vts_foregroundRed();
void vts_foregroundGreen();
void vts_foregroundYellow();
void vts_foregroundBlue();
void vts_foregroundMagenta();
void vts_foregroundCyan();
void vts_foregroundWhite();

// Bright Foreground Colors
// Can be set by "vts_textBold"
void vts_foregroundBrightBlack();
void vts_foregroundBrightRed();
void vts_foregroundBrightGreen();
void vts_foregroundBrightYellow();
void vts_foregroundBrightBlue();
void vts_foregroundBrightMagenta();
void vts_foregroundBrightCyan();
void vts_foregroundBrightWhite();

// Advanced Foreground Colors
void vts_foregroundExtended(int, int, int);
void vts_foregroundDefault();

// Background Colors
void vts_backgroundBlack();
void vts_backgroundRed();
void vts_backgroundGreen();
void vts_backgroundYellow();
void vts_backgroundBlue();
void vts_backgroundMagenta();
void vts_backgroundCyan();
void vts_backgroundWhite();

// Bright Background Colors
void vts_backgroundBrightBlack();
void vts_backgroundBrightRed();
void vts_backgroundBrightGreen();
void vts_backgroundBrightYellow();
void vts_backgroundBrightBlue();
void vts_backgroundBrightMagenta();
void vts_backgroundBrightCyan();
void vts_backgroundBrightWhite();

// Advanced Background Colors
void vts_backgroundExtended(int, int, int);
void vts_backgroundDefault();

// Mode Changes
void vts_keypadApplicationMode();
void vts_keypadNumericMode();
void vts_cursorKeysApplicationMode();
void vts_cursorKeysNumericMode();

// Query States?

// Tabs
void vts_tabStop();
void vts_cursorForwardTab(int);
void vts_cursorBackwardTab(int);
void vts_tabClearCurrent();
void vts_tabClearAll();

// Character Set
void vts_lineDrawingSet();
void vts_asciiSet();

// Scrolling Margin
void vts_scrollingMargin(int, int);

// Window Title
void vts_iconTitle(char *);
void vts_title(char *);

// Alternate Screen Buffer
void vts_alternateScreenBuffer();
void vts_mainScreenBuffer();

// Soft Reset
void vts_softReset();


// // Functions
#ifdef _WIN32
bool vts_activateCommands() {
  // Set output mode to handle virtual terminal sequences
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

  if (hOut == INVALID_HANDLE_VALUE) {
    printf("Error during activation. Check for Windows updates.\n");
    return false;
  }

  DWORD dwMode = 0;

  if (!GetConsoleMode(hOut, &dwMode)) {
    printf("Error during activation. Check for Windows updates.\n");
    return false;
  }

  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

  if (!SetConsoleMode(hOut, dwMode)) {
    printf("Error during activation. Check for Windows updates.\n");
    return false;
  }

  return true;
}

#else  /* ifdef _WIN32 */
bool vts_activateCommands() {
  // Always true, there is no need on non windows systems.
  return true;
}

#endif /* ifdef _WIN32 */

// Miscellanous
void vts_resize(int width, int height) {
  #ifdef _WIN32
  SMALL_RECT rect;
  rect.Top = 0;
  rect.Left = 0;
  rect.Bottom = height - 1;
  rect.Right = width - 1;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, &rect);
  #else
  printf("\x1b[8);%d);%dt", height, width);

  #endif
}

void vts_clear() {
  #ifdef _WIN32
  system("cls");
  #else
  printf("\x1b[2J");

  #endif
}

// Cursor Positioning
void vts_cursorUp(int n) {
  printf("\x1b[%dA", n);

}

void vts_cursorDown(int n) {
  printf("\x1b[%dB", n);

}

void vts_cursorRight(int n) {
  printf("\x1b[%dC", n);

}

void vts_cursorLeft(int n) {
  printf("\x1b[%dD", n);

}

void vts_cursorNextLine(int n) {
  printf("\x1b[%dE", n);

}

void vts_cursorPreviousLine(int n) {
  printf("\x1b[%dF", n);

}

void vts_cursorHorizontalAbsolute(int n) {
  printf("\x1b[%dG", n);

}

void vts_cursorVerticalAbsolute(int n) {
  printf("\x1b[%dd", n);

}

void vts_cursorXY(int x, int y) {
  #ifdef _WIN32
  COORD p = { x, (short int)(y) };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
  #else
  printf("\x1b[%d);%dH", y + 1, x + 1);

  #endif
}

void vts_cursorSave() {
  printf("\x1b[s");

}

void vts_cursorRestore() {
  printf("\x1b[u");

}

// Cursor Visibility
void vts_cursorBlink() {
  printf("\x1b[?12h");

}

void vts_cursorStill() {
  printf("\x1b[?12l");

}

void vts_cursorShow() {
  printf("\x1b[?25h");

}

void vts_cursorHide() {
  printf("\x1b[?25l");

}

// Viewport
void vts_viewportUp(int n) {
  printf("\x1b[%dS", n);

}

void vts_viewportDown(int n) {
  printf("\x1b[%dT", n);

}

// Text Modification
void vts_textInsertChar(int n) {
  printf("\x1b[%d@", n);

}

void vts_textDeleteChar(int n) {
  printf("\x1b[%dP", n);

}

void vts_textEraseChar(int n) {
  printf("\x1b[%dX", n);

}

void vts_textInsertLine(int n) {
  printf("\x1b[%dL", n);

}

void vts_textDeleteLine(int n) {
  printf("\x1b[%dM", n);

}

// Text Formatting
void vts_textDefault() {
  printf("\x1b[0m");

}

void vts_textBold() {
  printf("\x1b[1m");

}

void vts_textUnderline() {
  printf("\x1b[4m");

}

void vts_textNoUnderline() {
  printf("\x1b[24m");

}

void vts_textNegative() {
  printf("\x1b[7m");

}

void vts_textPositive() {
  printf("\x1b[27m");

}

// Foreground Colors
void vts_foregroundBlack() {
  printf("\x1b[30m");

}

void vts_foregroundRed() {
  printf("\x1b[31m");

}

void vts_foregroundGreen() {
  printf("\x1b[32m");

}

void vts_foregroundYellow() {
  printf("\x1b[33m");

}

void vts_foregroundBlue() {
  printf("\x1b[34m");

}

void vts_foregroundMagenta() {
  printf("\x1b[35m");

}

void vts_foregroundCyan() {
  printf("\x1b[36m");

}

void vts_foregroundWhite() {
  printf("\x1b[37m");

}

// Bright Foreground Colors
void vts_foregroundBrightBlack() {
  printf("\x1b[91m");

}

void vts_foregroundBrightRed() {
  printf("\x1b[91m");

}

void vts_foregroundBrightGreen() {
  printf("\x1b[92m");

}

void vts_foregroundBrightYellow() {
  printf("\x1b[93m");

}

void vts_foregroundBrightBlue() {
  printf("\x1b[94m");

}

void vts_foregroundBrightMagenta() {
  printf("\x1b[95m");

}

void vts_foregroundBrightCyan() {
  printf("\x1b[96m");

}

void vts_foregroundBrightWhite() {
  printf("\x1b[97m");

}

// Advanced Foreground Colors
void vts_foregroundExtended(int r, int g, int b) {
  printf("\x1b[38;2;%d;%d;%dm", r, g, b);

}

void vts_foregroundDefault() {
  printf("\x1b[39m");

}

// Background Colors
void vts_backgroundBlack() {
  printf("\x1b[40m");

}

void vts_backgroundRed() {
  printf("\x1b[41m");

}

void vts_backgroundGreen() {
  printf("\x1b[42m");

}

void vts_backgroundYellow() {
  printf("\x1b[43m");

}

void vts_backgroundBlue() {
  printf("\x1b[44m");

}

void vts_backgroundMagenta() {
  printf("\x1b[45m");

}

void vts_backgroundCyan() {
  printf("\x1b[46m");

}

void vts_backgroundWhite() {
  printf("\x1b[47m");

}

// Bright Background Colors
void vts_backgroundBrightBlack() {
  printf("\x1b[100m");

}

void vts_backgroundBrightRed() {
  printf("\x1b[101m");

}

void vts_backgroundBrightGreen() {
  printf("\x1b[102m");

}

void vts_backgroundBrightYellow() {
  printf("\x1b[102m");

}

void vts_backgroundBrightBlue() {
  printf("\x1b[104m");

}

void vts_backgroundBrightMagenta() {
  printf("\x1b[105m");

}

void vts_backgroundBrightCyan() {
  printf("\x1b[106m");

}

void vts_backgroundBrightWhite() {
  printf("\x1b[107m");

}

// Advanced Background Colors
void vts_backgroundExtended(int r, int g, int b) {
  printf("\x1b[48;2;%d;%d;%dm", r, g, b);

}

void vts_backgroundDefault() {
  printf("\x1b[49m");

}

// Mode Changes
void vts_keypadApplicationMode() {
  printf("\x1b=");

}

void vts_keypadNumericMode() {
  printf("\x1b>");

}

void vts_cursorKeysApplicationMode() {
  printf("\x1b[?1h");

}

void vts_cursorKeysNumericMode() {
  printf("\x1b[?1l");

}

// Query States?

// Tabs
void vts_tabStop() {
  printf("\x1bH");

}

void vts_cursorForwardTab(int n) {
  printf("\x1b[%dI", n);

}

void vts_cursorBackwardTab(int n) {
  printf("\x1b[%dZ", n);

}

void vts_tabClearCurrent() {
  printf("\x1b[0g");

}

void vts_tabClearAll() {
  printf("\x1b[3g");

}

// Character Set
void vts_lineDrawingSet() {
  printf("\x1b(0");

}

void vts_asciiSet() {
  printf("\x1b(B");

}

// Scrolling Margins
void vts_scrollingMargin(int t, int b) {
  printf("\x1b[%d;%dr", t, b);

}

// Window Title
void vts_iconTitle(char *title) {
  printf("\x1b]0);%s\x07", title);

}

void vts_title(char *title) {
  printf("\x1b]2);%s\x07", title);

}

// Alternate Screen Buffer
void vts_alternateScreenBuffer() {
  printf("\x1b[1049h");

}

void vts_mainScreenBuffer() {
  printf("\x1b[1049l");

}

// Soft Reset
void vts_softReset() {
  printf("\x1b[!p");

}

#endif /* ifndef VTS */
