bin = errno

all : $(bin)

$(bin) : main.c
	gcc -o $@ -Wall -Wextra $^

clear :
	rm $(bin)

play :
	./errno 3
