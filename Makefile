bin = errno



compile: main.c
	gcc -o $(bin) -Wall -Wextra $^

install: 
	make compile
	cp ./$(bin) ~/.local/bin/

uninstall:
	rm ~/.local/bin/$(bin)

exec: 
	./$(bin)

clean:
	rm ./$(bin)



