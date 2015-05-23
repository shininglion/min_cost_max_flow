CXX	=	g++ -std=c++11 -Wall -O2
EXE = mcmf

all: $(EXE)

$(EXE): main.cpp mcmf.cpp mcmf.h
	$(CXX) $< -o $@

clean:
	rm -f $(EXE)
