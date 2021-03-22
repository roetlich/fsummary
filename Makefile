FLAGS=-I. -Isrc -Isrc/dependencies -lyaslapi -std=c99 -O3 -Wall -Wextra -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition
CFILES=src/dependencies/sds/*.c src/dependencies/toml/*.c src/**/*.c src/*.c
HEADERS=src/dependencies/sds/*.h src/dependencies/toml/*.h src/**/*.h src/*.h


build:
	cc $(FLAGS) $(CFILES) fsummary.c -o fsummary

install-dependencies:
	git submodule update --init --recursive && cd src/dependencies/yasl && cmake --configure . && cmake --build . && ./install.sh

check: build
	 ./fsummary ./Makefile

test:
	cc $(FLAGS) $(CFILES) ./test.c -o test && ./test

format: 
	 clang-format -i --style=llvm $(CFILES) $(HEADERS)
