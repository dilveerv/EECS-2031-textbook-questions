OBJS=main.o morsecode.o
LDFLAGS=-lwiringPi

CC=gcc
CFLAGS=-Wall -pedantic

%.o: %.c morsecode.h
    $(CC) $(CFLAGS) -c -ansi $<
    
main: ${OBJS}
    $(CC) $(CFLAGS) ${OBJS} -o main $(LDFLAGS)



alarm.o: alarm.c
    $(CC) -Wall -pedantic -c -ansi $<
    
alarm: alarm.o
    $(CC) -Wall -pedantic alarm.o -o alarm -lwiringPi
    
    

