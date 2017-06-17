# CppAutomata

FILES = ABB.c cliente.c ABB_priv.c
OUT = a.out
CC = gcc
WARN = -Wall
FLAGS = -lm

default: $(OUT)
$(OUT): $(FILES)
	$(CC) $(WARN) -o $(OUT) $(FILES) $(FLAGS)

.PHONY: $(OUT)
