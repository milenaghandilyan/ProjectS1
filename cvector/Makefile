# Makefile for CVector project

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
INCLUDES = -Iinclude
SRC = src/vector.c main.c
OUT = vector_demo

all:
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
