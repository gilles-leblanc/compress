CFLAGS=-Wall -g

all: clean
	make compress

clean:
	rm -f compress

compress:
	gcc compress.c `pkg-config --cflags --libs glib-2.0` -o compress
