imageDriver: imageDriver.o Image.o
	g++ -o imageDriver imageDriver.o Image.o
imageDriver.o: imageDriver.cpp Image.h
	g++ -c imageDriver.cpp
Image.o: Image.cpp Image.h
	g++ -c Image.cpp

clean: 
	rm *.o imageDriver
