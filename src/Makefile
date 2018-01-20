CC := gcc
RM := rm -f
CCFLAGS = -DDEBUG -g -g3 -gdwarf-2
LIBS =
  
all: LinkedList SqList BiTree

Linkedlist:	LinkedList.c
	${CC} ${CCFLAGS} -o ../Debug/LinkedList LinkedList.c
	
SqList:	SqList.c
	${CC} ${CCFLAGS} -o ../Debug/SqList SqList.c
	
BiTree: BiTree.c
	${CC} ${CCFLAGS} -o ../Debug/BiTree BiTree.c


#debug: CCFLAGS += -DDEBUG -g
#debug: LinkedList SqList BiTree

clean:
	@echo '$(OS)'
	del /s ..\Debug\*.exe
	