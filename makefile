CXX := g++
OBJECTS := CLogger.o main.o
LIBS := -lpthread



SampleLogging: $(OBJECTS)
	$(CXX) $(LIBS) $(OBJECTS) -o SampleLogging 
Clogger.o: Clogger.cpp
	$(CXX) -c Clogger.cpp -o Clogger.o
main.o: main.cpp
	$(CXX) -c main.cpp -o main.o
