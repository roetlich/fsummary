FLAGS=-I. -Isrc -Isrc/dependencies -lyaslapi -std=c99 -O3 -Wall -Wextra -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition
CFILES=src/dependencies/sds/*.c src/dependencies/toml/*.c src/**/*.c src/*.c
HEADERS=src/dependencies/sds/*.h src/dependencies/toml/*.h src/**/*.h src/*.h


build:
	cc $(FLAGS) $(CFILES) fsummary.c -o fsummary

check:
	cc $(FLAGS) $(CFILES) fsummary.c -o fsummary && ./fsummary ./Makefile

tests:
	cc $(FLAGS) $(CFILES) ./test.c -o test && ./test

format: 
	 clang-format -i --style=llvm $(CFILES) $(HEADERS)