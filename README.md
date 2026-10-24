# Log-errno-c
A simple CLI tool in C that takes an errno code as a command-line argument and prints its corresponding error description .


# Make Instructions
- `make compile` : will compile
- `make install` : will cp the binary to /usr/bin
- `make uninstall` : remove /usr/bin/errno
- `make clean`: rm ./errno

# usage
1. Run the program in the terminal with errno code as  a command-line argument  : `$ errno 1 2 3 4 5`.
2. ![image](https://github.com/user-attachments/assets/e927287e-632b-41c0-89ae-301fbcfa3c6d) 
3. If pass a non-number the program will run normaly and get the others code errors.
4. ![image](https://github.com/user-attachments/assets/e8b1d6f6-035f-4b40-9f75-8468892e9bf9) 

