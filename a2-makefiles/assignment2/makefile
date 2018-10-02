# 
#  FILE          : source.c 
#  PROJECT       : PROG1165 - Advanced System Programming - Assignment #2
#  PROGRAMMER    : Brendan Rushing
#  FIRST VERSION : 2018-06-17
#  DESCRIPTION   : 
#	This assignment verifys a random number against user input
#

OUTPUT = random
MAIN_SRC = source






# =======================================================
#                  	random
# =======================================================
# FINAL BINARY Target
./bin/$(OUTPUT) : ./obj/$(MAIN_SRC).o
	cc ./obj/$(MAIN_SRC).o -o ./bin/$(OUTPUT)
#
# =======================================================
#                     Dependencies
# =======================================================                     
./obj/$(MAIN_SRC).o : ./src/$(MAIN_SRC).c 
	cc -c ./src/$(MAIN_SRC).c -o ./obj/$(MAIN_SRC).o


#
# =======================================================
# Other targets
# =======================================================                     
all : ./bin/$(OUTPUT)

clean:
	rm -f ./bin/*
	rm -f ./obj/*.o
	rm -f ./inc/*.h~
	rm -f ./src/*.c~



