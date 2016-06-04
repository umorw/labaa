INCLUDE=-I ./thirdparty
INCLUDE1=-I ./src

all: bin/square bin/test

bin/square: obj/main.o obj/worx.o 
	mkdir -p bin
	gcc obj/main.o obj/worx.o -o bin/square -lm

bin/test: obj/functional_test.o obj/test_main.o
	gcc -o bin/test obj/test_main.o obj/functional_test.o obj/worx.o -Wall -lm

test:	bin/test
	./bin/test

obj/main.o: src/main.c
	mkdir -p obj
	gcc $(INCLUDE1) -c src/main.c -Wall -o obj/main.o

obj/worx.o: src/worx.c
	gcc $(INCLUDE1) -c src/worx.c -Wall -o obj/worx.o

obj/test_main.o: test/test_main.c
	gcc $(INCLUDE) -c test/test_main.c -Wall -o obj/test_main.o

obj/functional_test.o: test/functional_test.c
	gcc $(INCLUDE1) $(INCLUDE) -c test/functional_test.c -Wall -o obj/functional_test.o -lm

.PHONY: clean
clean:
	rm -f -r bin/ obj/


