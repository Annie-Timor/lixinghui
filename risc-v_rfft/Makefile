SRC = \
main.c \
fft.c \
user_rfft.c 

INC = -I ./

OBJ_DIR = build

OBJ=$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
#OBJ=$(SRC:.c=.o)

BIN=a.exe

# add src file to compiling dir
# no this compiling error
vpath %.c $(dir $(SRC))

$(BIN):$(OBJ)
	gcc $(OBJ) -o $(BIN)

$(OBJ_DIR)/%.o:%.c
	gcc -c $(INC) $< -o $@

.PHONY:clean

clean:
	del /Q /S $(OBJ_DIR)\*.o $(BIN)
