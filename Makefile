CXX			= g++
CXXFLAGS 	= `pkg-config --cflags opencv`
LIBS 		= `pkg-config --libs opencv`


# Individual Compile Tests
testing: testing.cpp
	$(CXX) testing.cpp -o testing $(CXXFLAGS) $(LIBS)

clean:
	rm testing
