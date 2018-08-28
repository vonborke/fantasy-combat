
combat: main.o menu.o utility.o tournament.o character.o barbarian.o vampire.o blueMen.o medusa.o harryPotter.o linkedContainer.o
	g++ -std=c++11 main.o menu.o utility.o tournament.o character.o barbarian.o vampire.o blueMen.o medusa.o harryPotter.o linkedContainer.o -o combat

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

tournament.o: tournament.cpp tournament.hpp
	g++ -c -std=c++11 tournament.cpp

linkedContainer.o: linkedContainer.cpp linkedContainer.hpp
	g++ -c -std=c++11 linkedContainer.cpp
	
character.o: character.cpp character.hpp
	g++ -c -std=c++11 character.cpp
	
barbarian.o: barbarian.cpp barbarian.hpp
	g++ -c -std=c++11 barbarian.cpp
	
vampire.o: vampire.cpp vampire.hpp
	g++ -c -std=c++11 vampire.cpp
	
blueMen.o: blueMen.cpp blueMen.hpp
	g++ -c -std=c++11 blueMen.cpp
	
medusa.o: medusa.cpp medusa.hpp
	g++ -c -std=c++11 medusa.cpp
	
harryPotter.o: harryPotter.cpp harryPotter.hpp
	g++ -c -std=c++11 harryPotter.cpp
	
menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp
	
utility.o: utility.cpp utility.hpp
	g++ -c -std=c++11 utility.cpp

clean:
	rm *.o combat
	
