CC = gcc
CC_FLAGS = -g -ansi -pedantic -Wall -w -lm
OUT_EXE = "dice"
FILES = dice.c Game_Functions.c

Assignment2: $(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES)

dice.o : Game_Functions.h


