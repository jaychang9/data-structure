CC := gcc
RM := rm -f
CCFLAGS = -DDEBUG -g -g3 -gdwarf-2
LIBS =
  
all: LinkedList SqList BiTree

LinkedList:	src/LinkedList.c
	${CC} ${CCFLAGS} -o Debug/LinkedList src/LinkedList.c
	
SqList:	src/SqList.c
	${CC} ${CCFLAGS} -o Debug/SqList src/SqList.c
	
BiTree: src/BiTree.c
	${CC} ${CCFLAGS} -o Debug/BiTree src/BiTree.c


#debug: CCFLAGS += -DDEBUG -g
#debug: LinkedList SqList BiTree

clean:
	@echo '$(OS)'
	del /s Debug\*.exe
	