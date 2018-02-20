
.PHONY: default
default: cpp.exe c.exe data.txt

cpp.exe: cpp.cpp
	g++ -g -o cpp.exe cpp.cpp 

c.exe: c.c 
	gcc -g -o c.exe c.c

data.txt: gen.py 
	rm -f data.txt
	python gen.py  0 300000
