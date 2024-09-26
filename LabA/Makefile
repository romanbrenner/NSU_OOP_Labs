CXX = g++
CXXFLAGS = -Wall -g

# Указываем все объектные и исходные файлы
OBJECTS = main.o module1.o module2.o module3.o
SOURCES = main.cpp module1.cpp module2.cpp module3.cpp
HEADERS = module1.h module2.h module3.h

# Цель по умолчанию
my_program: $(OBJECTS)
	$(CXX) -o my_program $(OBJECTS)

# Правило для создания объектных файлов
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка от собранных файлов
clean:
	rm -f $(OBJECTS) my_program