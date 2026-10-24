bin = errno



compile: main.c
	gcc -o $(bin) -Wall -Wextra $^

install:	
	make compile
	cp ./$(bin) /usr/bin/

uninstall:
	rm /usr/bin/$(bin)

exec: 
	./$(bin)

clean:
	rm ./$(bin)



