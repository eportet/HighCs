# in EC327, we use the ${GCC} compiler
# therefore, we define the GCC variable
GCC = g++ 


HighCs: pa3.o GameObject.o Sailor.o Dock.o Port.o CartPoint.o CartVector.o Model.o View.o GameCommand.o
	${GCC} pa3.o GameObject.o Sailor.o Dock.o Port.o CartPoint.o CartVector.o Model.o View.o GameCommand.o -o HighCs

#c1: CartPoint.o CartVector.o TestCheckPoint1.o
#	${GCC} CartPoint.o CartVector.o TestCheckPoint1.o -o c1

#c2: CartPoint.o CartVector.o GameObject.o Port.o TestCheckPoint2.o
#	${GCC} CartPoint.o CartVector.o GameObject.o Port.o TestCheckPoint2.o -o c2

#c3: CartPoint.o CartVector.o GameObject.o Port.o Dock.o Sailor.o TestCheckPoint3.o
#	${GCC} CartPoint.o CartVector.o GameObject.o Port.o Dock.o Sailor.o TestCheckPoint3.o -o c3

pa3.o: pa3.cpp
	${GCC} -c pa3.cpp

GameObject.o: GameObject.cpp
	${GCC} -c GameObject.cpp

Sailor.o: Sailor.cpp
	${GCC} -c Sailor.cpp

Dock.o: Dock.cpp
	${GCC} -c Dock.cpp

Port.o: Port.cpp
	${GCC} -c Port.cpp


TestCheckPoint1.o: TestCheckPoint1.cpp
	${GCC} -c TestCheckPoint1.cpp

CartPoint.o: CartPoint.cpp
	${GCC} -c CartPoint.cpp

CartVector.o: CartVector.cpp
	${GCC} -c CartVector.cpp

Model.o: Model.cpp
	${GCC} -c Model.cpp

View.o: View.cpp
	${GCC} -c View.cpp

GameCommand.o: GameCommand.cpp
	${GCC} -c GameCommand.cpp

clean:
	rm pa3.o GameObject.o Sailor.o Dock.o Port.o CartPoint.o CartVector.o Model.o View.o GameCommand.o HighCs  
