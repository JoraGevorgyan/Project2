all: baseEditor

baseEditor: object/main.o object/account.o object/base.o
	g++ object/main.o object/account.o object/base.o -o baseEditor

object/main.o: source/main.cpp source/accountCtrl.hpp
	mkdir -p ./object
	g++ -c source/main.cpp -o object/main.o

object/account.o: source/account.cpp
	mkdir -p ./object
	g++ -c source/account.cpp -o object/account.o

object/base.o: source/base.cpp
	mkdir -p ./object
	g++ -c source/base.cpp -o object/base.o

clean:
	rm -rf ./object

clean_a:
	rm -rf ./object
	rm ./baseEditor
