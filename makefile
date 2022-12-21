CC = g++
CFLAGS = -std=c++20 -fdiagnostics-color=always -g
TARGET = ./target/
DAY = 00
OUTPUT_FOLDER = ./out/
EXE_FILE = advent_of_code_day_$(DAY)
TAR_NAME = AdventOfCode


SRCEXT = cpp

build: $(TARGET) $(TARGET)day_$(DAY).o $(TARGET)utils.o $(OUTPUT_FOLDER)
	$(CC) $(CFLAGS) $(TARGET)day_$(DAY).o $(TARGET)utils.o -o $(OUTPUT_FOLDER)$(EXE_FILE)

run:
	make build
	$(OUTPUT_FOLDER)$(EXE_FILE)

$(TARGET):
	mkdir $(TARGET)

$(OUTPUT_FOLDER):
	mkdir $(OUTPUT_FOLDER)

$(TARGET)%.o: ./src/%.$(SRCEXT)
	$(CC) $(CFLAGS) -c -o ./$@ $<

tar:
	tar -cvf $(TAR_NAME).tar Makefile *.cpp *.h *.hpp

clean:
	rm -r $(TARGET)
	rm -rf $(OUTPUT_FOLDER)

template:
	cat ./src/atemplate.cpp >> ./src/day_$(DAY).cpp
	touch ./input/day_$(DAY).txt
