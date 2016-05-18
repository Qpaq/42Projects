ASM		= ./ASM
VM		= ./VM

all: 
	@echo "Building ASM"
	@make -C $(ASM)
	@echo "Building VM"
	@make -C $(VM)
	@mv $(ASM)/asm .
	@mv $(VM)/corewar .

clean:
	@make clean -C $(ASM)
	@make clean -C $(VM)
	@echo "\033[31mCleaning...\033[0m"

fclean: clean
	@make fclean -C $(ASM)
	@make fclean -C $(VM)
	@rm corewar
	@rm asm
