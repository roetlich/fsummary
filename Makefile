FLAGS=-I. -Isrc -Idependencies -lm -ldl -std=c99 -Wall -Wextra -pedantic -Wstrict-prototypes -Wold-style-definition
LINKER_FLAGS=-Isrc -Idependencies -lm -ldl
CFILES=dependencies/sds/*.c dependencies/toml/*.c src/**/*.c src/*.c ./dependencies/yasl/build/libyaslapi.a ./dependencies/lua/src/liblua.a
HEADERS=dependencies/sds/*.h dependencies/toml/*.h src/**/*.h src/*.h


build:
	cc $(FLAGS) -O3 $(CFILES) $(LINKER_FLAGS) -o fsummary

build-debug:
	cc $(FLAGS) -g $(CFILES) $(LINKER_FLAGS) -o fsummary

git-get-submodules:
	git submodule init

install-yasl: git-get-submodules
	mkdir -p dependencies/yasl/build && \
	cd dependencies/yasl/build && \
	cmake .. && cmake --build . 

install-lua:
	curl -R -O http://www.lua.org/ftp/lua-5.4.2.tar.gz && \
	mkdir -p ./dependencies/lua && \
	tar zxf lua-5.4.2.tar.gz -C ./dependencies/lua --strip-components=1 && \
	rm lua-5.4.2.tar.gz && \
	cd dependencies/lua && \
	make all test

install-dependencies: install-yasl install-lua

check: build
	 ./fsummary ./Makefile

run-tests:
	 cc  -I. -lm -ldl -std=c99 -D"TESTS=1" $(CFILES) ./tests/test*.c $(LINKER_FLAGS) -o test && ./test

format:
	 find . -path ./dependencies -prune -false -o -iname '*.c' -or -iname '*.h'| xargs clang-format -i --style=llvm

loc:
	loc --exclude "dependencies/"

clean:
	rm -rf dependencies/lua/ ; \
	rm dependencies/yasl/libyaslapi.a
