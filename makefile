LIBS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lpython3.2mu

all:
	rm -rf build
	mkdir build
	mkdir build/framework
	g++ -Wall src/main.cpp -o build/main -lpython3.2mu
	g++ -Wall -c src/libs/sterne.cpp -o sterne.o
	g++ -shared sterne.o $(LIBS) -o build/framework/sterne.so
	cp src/framework/framework.py build/framework/framework.py
	make clean
	
clean:
	rm -f *.o
	
