CC = gcc
CFLAGS = -Wall -g

SRC = tree.h node.h helper.h

OBJ = tree.o helper.o
MASTER_OBJ = main.o

MASTER = P0

OUTPUT = $(MASTER)

all: $(OUTPUT)

%.o: %.c $(STANDARD) $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(MASTER): $(MASTER_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(MASTER_OBJ) $(OBJ) -o $(MASTER)

clean: 
	rm $(OUTPUT) *.o *.inorder *.preorder *.postorder output 
