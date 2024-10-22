/***********************************************************************
 * BrainfuckInterpreterProgram-265909-FinalVersion.c
 * Final Version.
 ***********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Define the constant for the memory size
#define MEMORY_SIZE 30000

void ExitProgram(void);
void OtherTestProgramsSubMenu(void);
void OtherDescriptionSubMenu(void);
void OtherMainMenu(void);
void AboutMainMenu(void);
void HelpMainMenu(void);
void OpenMainMenu(void);
void NewMainMenu(void);
void RunMainMenu(void);
void MainMenu(void);
void TitleScreen(void);
void SaveCode(char * Filename, char * Code);
void InterpretCode(char * Code);
int IsValidBFChar(char ch);
int ValidateBFCode(const char * Code);
void EmptyBuffer(void);
void ClearConsole(void);
void Loop(void);


/* ExitProgram */
void ExitProgram(void) {
  printf("############################################\n"
    "#          <7> - Exiting Program           #\n"
    "############################################\n");
  exit(0);
}
/* OtherTestProgramsSubMenu */
void OtherTestProgramsSubMenu(void) {
  int Choice;
  char * Code1 = "++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>++.>+.+++++++..+++.<<++.>+++++++++++++++.>.+++.------.--------.<<+."; //Hello World!
  char * Code2 = "++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>++++++++++++++++++.+.+.+.+.+.+.+.+.+."; //Numbers 0-9
  char * Code3 = "ABCxyz123#"; //ABCxyz123#
  char * Code = NULL;
  printf("############################################\n"
    "#    <6> - Other - <2> - Test Programs     #\n"
    "############################################\n"
    "\n"
    "############################################\n"
    "# Choose a program by selecting the number #\n"
    "# and the code shown will run. The program #\n"
    "# will give the expected value and the     #\n"
    "# actual value associated with it.         #\n"
    "############################################\n"
    "\n"
    "############################################\n"
    "# <1> - 'Hello World!' - Used to show a    #\n"
    "# simple Hellow World display.             #\n"
    "# <2> - 'Numbers 0-9' - Used to show the   #\n"
    "# numbers being displayed.                 #\n"
    "# <3> - 'ABCxyz123#' - Used to break the   #\n"
    "# program as a test.                       #\n"
    "############################################\n"
    ">");
  scanf("%d", & Choice); //Get Input

  switch (Choice) {
  case 1:
    Code = Code1;
    break;
  case 2:
    Code = Code2;
    break;
  case 3:
    Code = Code3;
    break;
  default:
    printf("############################################\n"
      "#               Invalid Entry              #\n"
      "############################################\n");
    return;
  }
  InterpretCode(Code);
}
/* OtherDescriptionSubMenu*/
void OtherDescriptionSubMenu(void) {
  printf("############################################\n"
    "#     <6> - Other - <1> - Description      #\n"
    "############################################\n"
    "\n"
    "############################################\n"
    "# This program is a simple interpreter for #\n"
    "# a esoteric programming language called   #\n"
    "# brainfuck. It is able to to run code,    #\n"
    "# create new files, save files and open    #\n"
    "# them. There is more information under    #\n"
    "# the 'About' and 'Help' sections.         #\n"
    "############################################\n");
}
/* OtherMainMenu */
void OtherMainMenu(void) {
  printf("############################################\n"
    "#            <6> - Other                   #\n"
    "############################################\n"
    "\n"
    "############################################\n"
    "# <1> - Description                        #\n"
    "# <2> - Test Programs                      #\n"
    "############################################\n"
    ">");
  int Choice;
  scanf("%d", & Choice); //Get Input
  if (Choice == 1) {
    OtherDescriptionSubMenu();
    getchar();
  } else if (Choice == 2) {
    OtherTestProgramsSubMenu();
    getchar();
  } else {
    printf("############################################\n"
      "#                  Error                   #\n"
      "############################################\n");
    getchar();
  }
}
/* AboutMainMenu */
void AboutMainMenu(void) {
  printf("############################################\n"
    "#            <5> - About - Menu            #\n"
    "############################################\n"
    "\n"
    "############################################\n"
    "# Program Name: Brainfuck Interpreter      #\n"
    "# Version: Final                           #\n"
    "# Developer: Christopher Jolly             #\n"
    "# Candidate Number: ------                 #\n"
    "# University: University of Sussex         #\n"
    "# School: ------------------------         #\n"
    "# Course: ------------------------         #\n"
    "# Module: ------------------------         #\n"
    "# Interface Type: Command Line             #\n"
    "# Source Language: C                       #\n"
    "############################################\n"
    ">");
}
/* HelpMainMenu */
void HelpMainMenu(void) {
  printf("############################################\n"
    "#            <4> - Help - Menu             #\n"
    "############################################\n"
    "\n"
    "############################################\n"
    "#        <1> - Run - Information:          #\n"
    "############################################\n"
    "# The 'run' option lets you enter brainfuck#\n"
    "# code which is then interpreted and       #\n"
    "# outputted. It does not let you save or   #\n"
    "# load code here.                          #\n"
    "############################################\n"
    "#        <2> - New - Information:          #\n"
    "############################################\n"
    "# The 'new' option operates similar to the #\n"
    "# 'run' option but instead the code written#\n"
    "# has to be saved in a file before being   #\n"
    "# run or tested.                           #\n"
    "############################################\n"
    "#        <3> - Open - Information:         #\n"
    "############################################\n"
    "# The 'open' option lets you enter a file  #\n"
    "# name after the '>'. The program will     #\n"
    "# attempt to open and read the code from   #\n"
    "# the file and then run it.                #\n"
    "############################################\n"
    "#            Extra Information:            #\n"
    "############################################\n"
    "# '>': Increments the pointer.             #\n"
    "# '<': Decrements the pointer.             #\n"
    "# '+': Increments the byte at the pointer. #\n"
    "# '-': Decrements the byte at the pointer. #\n"
    "# '.': Outputs the byte at the pointer.    #\n"
    "# ',': Accepts one byte of input.          #\n"
    "# '[': If the byte at the pointer is zero, #\n"
    "# jump forward in the code to the ']'.     #\n"
    "# ']' If the byte at the pointer is not    #\n"
    "# zero, jump back in the code to the '['.  #\n"
    "############################################\n"
    "#               Error Types                #\n"
    "############################################\n"
    "# There are various error types in the     #\n"
    "# program and they vary from syntax errors #\n"
    "# for the code, validation errors, general #\n"
    "# errors and others. They all generally    #\n"
    "# lead to the task or function being       #\n"
    "# repeated.                                #\n"
    "############################################\n"
    ">");
}
/* OpenMainMenu */
void OpenMainMenu(void) {
  printf("############################################\n"
    "#            <3> - Open - Menu             #\n"
    "############################################\n"
    ">");
  //Read filename from user. 255 is a reasonable length for a file name
  char Filename[256];
  scanf("%255s", Filename);
  // Open file and check if opened correctly
  FILE * file = fopen(Filename, "r");
  if (file == NULL) {
    printf("############################################\n"
      "#            Error Opening File            #\n"
      "############################################\n");
    return;
  }
  // Read the file
  char Code[MEMORY_SIZE] = {
    0
  };
  size_t i = 0;
  while ((i < MEMORY_SIZE - 1) && (Code[i] = fgetc(file)) != EOF) {
    ++i;
  }
  Code[i] = '\0';
  // Close the file
  fclose(file);
  // Validate the code
  if (!ValidateBFCode(Code)) {
    printf("############################################\n"
      "#           Brainfuck Syntax Error         #\n"
      "############################################\n");
    return;
  }
  // Interpret the code
  InterpretCode(Code);
}
/* NewMainMenu */
void NewMainMenu(void) {
  char Code[1024]; // Adjust size as necessary
  char Filename[255]; // Adjust size as necessary

  printf("############################################\n"
    "#             <2> - New - Menu             #\n"
    "############################################\n"
    "\n"
    "############################################\n"
    "#     Enter your code after the ' > '      #\n"
    "############################################\n"
    ">");
  fgets(Code, sizeof(Code), stdin); // Read user input
  printf("############################################\n"
    "#       Enter the filename to save to:     #\n"
    "############################################\n"
    "> ");
  fgets(Filename, sizeof(Filename), stdin); // Read filename
  Filename[strcspn(Filename, "\n")] = 0; // Remove trailing newline
  SaveCode(Filename, Code); // Save user input to file
  printf("############################################\n"
    "#                File Saved                #\n"
    "############################################\n"
    "> ");
  getchar();
  ClearConsole();
}
/* RunMainMenu */
void RunMainMenu(void) {
  printf("############################################\n"
    "#             <1> - Run - Menu             #\n"
    "############################################\n"
    "\n"
    "############################################\n"
    "#     Enter your code after the ' > '      #\n"
    "############################################\n"
    "> ");
}
/* MainMenu */
void MainMenu(void) {
  printf("############################################\n"
    "#                 Main Menu                #\n"
    "############################################\n"
    "\n"
    "############################################\n"
    "#     Select a Menu Option to Continue     #\n"
    "############################################\n"
    "\n"
    "############################################\n"
    "# <1> - Run                                #\n"
    "# <2> - New                                #\n"
    "# <3> - Open                               #\n"
    "# <4> - Help                               #\n"
    "# <5> - About                              #\n"
    "# <6> - Other                              #\n"
    "# <7> - Exit Program                       #\n"
    "############################################\n"
    ">");
}
/* TitleScreen */
void TitleScreen(void) {
  printf("############################################\n"
    "#        BrainFuck Interpreter in C        #\n"
    "############################################\n"
    "\n"
    "############################################\n"
    "#       Press <Enter> to Continue...       #\n"
    "############################################\n"
    ">");
}
/*Save Code*/
void SaveCode(char * Filename, char * Code) {
  FILE * fp;
  fp = fopen(Filename, "w");
  if (fp == NULL) {
    printf("############################################\n"
      "#             Error Saving File            #\n"
      "############################################\n");
    return;
  }
  fprintf(fp, "%s", Code);
  fclose(fp);
}
/* InterpretCode */
void InterpretCode(char * Code) {
  //Initialize memory array and pointer
  char memory[MEMORY_SIZE] = {
    0
  };
  char * ptr = memory;
  int loop;
  for (int i = 0; Code[i] != '\0'; ++i) {
    switch (Code[i]) {
    case '>': //Increase Pointer
      ++ptr;
      break;
    case '<': //Decrease Pointer
      --ptr;
      break;
    case '+': //Increase the byte at the pointer
      ++( * ptr);
      break;
    case '-': //Decrease the byte at the pointer
      --( * ptr);
      break;
    case '.': //Output the byte at the pointer
      putchar( * ptr);
      break;
    case ',': //Accept one byte of the input
      *
      ptr = getchar();
      break;
    case '[':
      if (! * ptr) {
        loop = 1;
        while (loop > 0) {
          ++i;
          if (Code[i] == '[')
            ++loop;
          else if (Code[i] == ']')
            --loop;
        }
      }
      break;
    case ']':
      loop = 1;
      while (loop > 0) {
        --i;
        if (Code[i] == '[')
          --loop;
        else if (Code[i] == ']')
          ++loop;
      }
      --i;
      break;
    }
  }
}
/* Check if the given character is a valid Brainfuck character */
int IsValidBFChar(char ch) {
  return ch == '>' || ch == '<' || ch == '+' || ch == '-' || ch == '.' || ch == ',' || ch == '[' || ch == ']';
}

/* Validate Brainfuck code */
int ValidateBFCode(const char * Code) {
  while ( * Code) {
    if (!IsValidBFChar( * Code)) {
      return 0; // Invalid character found
    }
    ++Code;
  }
  return 1; // All characters are valid
}
/* Empty the keyboard buffer */
void EmptyBuffer(void) {
  while (getchar() != '\n') {
    ;
  }
}

/* Clear Console */
void ClearConsole(void) {
  getchar();
  system("cls");
}
void Loop(void) {

  int Choice;
  char Code[MEMORY_SIZE];
  do {
    MainMenu();
    scanf("%d", & Choice);
    //EmptyBuffer();
    switch (Choice) {
    case 1:
      ClearConsole();
      RunMainMenu();
      fgets(Code, MEMORY_SIZE, stdin);
      InterpretCode(Code);
      getchar();
      ClearConsole();
      break;
    case 2:
      ClearConsole();
      NewMainMenu();
      break;
    case 3:
      ClearConsole();
      OpenMainMenu();
      break;
    case 4:
      ClearConsole();
      HelpMainMenu();
      ClearConsole();
      break;
    case 5:
      ClearConsole();
      AboutMainMenu();
      ClearConsole();
      break;
    case 6:
      ClearConsole();
      OtherMainMenu();
      ClearConsole();
      break;
    case 7:
      ClearConsole();
      ExitProgram();
      break;
    default:
      printf("############################################\n"
        "#               Invalid Entry              #\n"
        "############################################\n");
    }
  } while (Choice != 7);
}
/* Main */
int main(void) {
  TitleScreen();
  EmptyBuffer();
  ClearConsole();
  Loop();
  return 0;
}
