all : tp1

tp1 : tp1.out fonction_Tp1.h
	gcc -o tp1.out tp1.c 
