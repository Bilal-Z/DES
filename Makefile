CXX=g++

CXXFLAGS=-g -Wall

vpath %.cpp src
vpath %.hpp src
vpath %.o obj
SRCDIR=src
OBJDIR=obj

TARGET=des

default: $(TARGET)

objects = $(addprefix $(OBJDIR)/, main.o feistal.o function.o roundkeys.o utils.o)

$(TARGET): $(objects)
	$(CXX) $(XX) -o $(TARGET) $(objects)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/roundkeys.hpp $(SRCDIR)/function.hpp $(SRCDIR)/feistal.hpp $(SRCDIR)/utils.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/feistal.o: $(SRCDIR)/feistal.cpp $(SRCDIR)/roundkeys.hpp $(SRCDIR)/function.hpp $(SRCDIR)/feistal.hpp $(SRCDIR)/utils.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/function.o: $(SRCDIR)/function.cpp $(SRCDIR)/function.hpp $(SRCDIR)/utils.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/roundkeys.o: $(SRCDIR)/roundkeys.cpp $(SRCDIR)/roundkeys.hpp $(SRCDIR)/utils.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/utils.o: $(SRCDIR)/utils.cpp $(SRCDIR)/utils.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean: 
	$(RM) $(objects) *~ des

# g++ -c *.cpp -o des
# ./des