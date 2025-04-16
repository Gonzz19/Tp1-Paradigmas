CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRC = main.cpp \
    fabrica_personajes/fabrica_personajes.cpp \
    ../ej1/personajes/guerreros/barbaro/barbaro.cpp \
    ../ej1/personajes/guerreros/paladin/paladin.cpp \
    ../ej1/personajes/guerreros/gladiador/gladiador.cpp \
    ../ej1/personajes/guerreros/guerreros.cpp \
    ../ej1/personajes/guerreros/caballero/caballero.cpp \
    ../ej1/personajes/guerreros/mercenario/mercenario.cpp \
    ../ej1/armas/magicas/amuleto/amuleto.cpp \
    ../ej1/armas/magicas/libro_hechizos/libro_hechizo.cpp \
    ../ej1/armas/magicas/pocion/pocion.cpp \
    ../ej1/armas/magicas/baston/baston.cpp \
    ../ej1/armas/magicas/armas_magicas.cpp \
    ../ej1/armas/combate/armas_combate.cpp \
    ../ej1/armas/combate/espada/espada.cpp \
	../ej1/armas/combate/manos/manos.cpp \
    ../ej1/armas/combate/hacha_simple/hacha_simple.cpp \
    ../ej1/armas/combate/hacha_doble/hacha_doble.cpp \
    ../ej1/armas/combate/garrote/garrote.cpp \
    ../ej1/armas/combate/lanza/lanza.cpp \
    ../ej1/personajes/magos/magos.cpp \
    ../ej1/personajes/magos/hechicero/hechicero.cpp \
    ../ej1/personajes/magos/conjurador/conjurador.cpp \
    ../ej1/personajes/magos/brujo/brujo.cpp \
    ../ej1/personajes/magos/nicromante/nicromante.cpp \

# Archivos objeto
OBJ = $(SRC:.cpp=.o)

# Nombre del ejecutable
EXEC = prueba

# Regla principal
.PHONY: all clean
all: $(EXEC)

# Compilar el ejecutable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJ) $(EXEC)

run:
	./prueba