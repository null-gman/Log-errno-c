# Log-errno-c
a simple CLI tool in C that takes an errno code as a command-line argument and prints its corresponding error description .


# Make Instructions
- `make` : will compile
- `make compile`
- `make install` : will cp the binary to /home/USER/.local/bin
- `make uninstall` : remove /home/USER/.local/bin/errno
- `make clean`: rm ./errno

# usage
1. run the program in the terminal with errno code as  a command-line argument  : `./errno 1 2 3 4 5` .
2. ![image](https://github.com/user-attachments/assets/e927287e-632b-41c0-89ae-301fbcfa3c6d) 
3. if add a non-number  the program will run normaly and get the outhers code errors .
4. ![image](https://github.com/user-attachments/assets/e8b1d6f6-035f-4b40-9f75-8468892e9bf9) 

