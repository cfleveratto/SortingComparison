objects= CompareSorts.o sorts.o helper.o

testComparison: $(objects)
	g++ $(objects) -o testComparison

CompareSorts.o: BOTree.h helper.h sorts.h CompareSorts.cpp
	g++ -c CompareSorts.cpp

BOTree.h: BONode.h

sorts.o: sorts.h sorts.cpp
	g++ -c sorts.cpp

helper.o: helper.h helper.cpp
	g++ -c helper.cpp

clean:
	rm *~ $(objects) testComparison
