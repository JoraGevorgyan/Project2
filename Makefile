all: bankBase

bankBase: object/main.o object/account.o
	g++ object/main.o object/account.o -o bankBase

object/main.o: source/main.cpp source/bankAccountCtrl.hpp
	mkdir -p ./object
	g++ -c source/main.cpp -o object/main.o

object/account.o: source/account.cpp
	mkdir -p ./object
	g++ -c source/account.cpp -o object/account.o

clean:
	rm -rf ./object

clean_a:
	rm -rf ./object
	rm ./bankBase
