# ==========================================
# CONFIGURATION DE BASE
# ==========================================

# Nom de votre programme final
EXEC = programme

# Compilateur C++
CXX = g++

# Options de compilation
FLAGS = -Wall -Wextra -std=c++11 -g

# ==========================================
# VOS FICHIERS
# ==========================================

# Listez tous vos fichiers .cpp
FICHIERS = main.cpp \
           Collection.cpp \
           Trajet.cpp
# Les fichiers .o (générés automatiquement)
OBJETS = $(FICHIERS:.cpp=.o)

# ==========================================
# COMMANDES PRINCIPALES
# ==========================================

# Compiler le projet
all: $(EXEC)

# Créer l'exécutable
$(EXEC): $(OBJETS)
	$(CXX) $(OBJETS) -o $(EXEC)
	@echo "✓ Compilation terminée!"

# Compiler chaque fichier .cpp en .o
%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

# ==========================================
# EXÉCUTION
# ==========================================

# Lancer le programme normalement
run: $(EXEC)
	./$(EXEC)

# Lancer avec Valgrind
valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC)

# ==========================================
# NETTOYAGE
# ==========================================

# Supprimer les fichiers compilés
clean:
	rm -f $(OBJETS)
	@echo "✓ Fichiers .o supprimés"

# Tout supprimer
fclean: clean
	rm -f $(EXEC)
	@echo "✓ Programme supprimé"

# Recompiler tout
re: fclean all
