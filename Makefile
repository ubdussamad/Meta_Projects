all: play record

prop: details.c
	gcc details.c -lm -ldl -lasound -o det > tmp
	rm tmp
	./det > tmp
	rm det
	cat tmp | xargs echo -e
	rm tmp

play: play_raw.c
	 gcc play_raw.c -lm -ldl -lasound -o lis

record: sond.c
	 gcc sond.c -lm -ldl -lasound -o rec

clean:
	rm rec lis
