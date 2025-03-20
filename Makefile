all:
	g++ -o encoder main.cpp hash.cpp

clean:
	rm -f *.o encoder