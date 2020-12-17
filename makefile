CC=g++
CFLAGS= -c -Wall -std=c++14
EXENAME= RSA_Encryption

default: main.o RSA.o
	$(CC) main.o RSA.o  -o $(EXENAME)

main.o: main.cpp
	$(CC) $(CFLAGS)  main.cpp

RSA.o: RSA.cpp
	$(CC) $(CFLAGS) RSA.cpp

clean:
	rm *.o $(EXENAME)

run:
	./$(EXENAME)