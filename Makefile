src = src/main.c src/command_parser.c src/executer.c src/util.c src/operations.c
cc = gcc
target = file_manager

$(target): $(src)
	@echo "Compiling the file manager..."
	$(cc) $(src) -o $@

clean: $(target)
	@echo "Removing the file manager..."
	rm $(target)

install: $(target)
	@echo "Moving executable into bin folders..."
	sudo cp $< /usr/bin/

remvoe: $(target)
	@echo "Removing the file manager from your system..."
	sudo rm /usr/bin/$(target)

.PHONY: clean install
