CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g
LDFLAGS     =

#Directories where the compiler can find things
INCLUDES    = -Iinclude
LIBDIRS     = 
LIBS        = 

BINDIR = bin/
SRCDIR = src/

#Put the names of your source code files in the lines below.  You will need both your
# Solution source code file and the source code with the main program in it

SOURCE1 = $(SRCDIR)testList.c $(SRCDIR)linkedList.c
SOURCE2 = $(SRCDIR)simulation.c $(SRCDIR)linkedList.c $(SRCDIR)simFunctions.c

#The list of object files for each program is below.  
# The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJS1    = Testing.o list.o
OBJS2    = Simulation.o list.o

PROGNAME1 = $(BINDIR)listTest
PROGNAME2 = $(BINDIR)runsim
all : test sim


test : $(SOURCE1)
	$(CC) $(CFLAGS)  $(SOURCE1) $(INCLUDES) $(LIBDIRS) -o $(PROGNAME1) $(LIBS)

sim : $(SOURCE2)
	$(CC) $(CFLAGS)  $(SOURCE2) $(INCLUDES) $(LIBDIRS) -o $(PROGNAME2) $(LIBS)

clean:
	@ rm *.o