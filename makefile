hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c 
	gcc -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.c 
	gcc -I ./include/ -o ./lib/Oyun.o -c ./src/Oyun.c 
	gcc -I ./include/ -o ./bin/Test ./src/Test.c ./lib/Oyun.o ./lib/Dosya.o ./lib/Kisi.o
	
calistir:
	./bin/Test
	