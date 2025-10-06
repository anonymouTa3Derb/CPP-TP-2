# ==========================================
# CONFIGURATION DE BASE
# ==========================================

# Nom de votre programme final
EXEC = programme

# Compilateur C++
CXX = g++

# Options de compilation (ajout de -I. pour inclure les headers locaux)
FLAGS = -Wall -Wextra -std=c++11 -g -I.

# ==========================================
# VOS FICHIERS
# ==========================================

# Listez tous vos fichiers .cpp
SRC = main.cpp \
      Collection.cpp \
      Trajet.cpp

# Fichiers .h associés (pour les dépendances)
HEADERS = Collection.h \
	Trajet.h

# Les fichiers .o (générés automatiquement)
OBJ = $(SRC:.cpp=.o)

# ==========================================
# COMMANDES PRINCIPALES
# ==========================================

# Cible par défaut : compiler le projet
all: $(EXEC)

# Créer l'exécutable (dépend des .o ET des .h)
$(EXEC): $(OBJ) $(HEADERS)
	$(CXX) $(OBJ) -o $(EXEC)
	@echo "✅ Compilation terminée: $(EXEC) est prêt!"

# Règle pour générer les .o (avec dépendance vers les .h)
%.o: %.cpp $(HEADERS)
	$(CXX) $(FLAGS) -c $< -o $@

# ==========================================
# EXÉCUTION
# ==========================================

# Lancer le programme (dépend de l'exécutable)
run: $(EXEC)
	./$(EXEC)

# Lancer avec Valgrind (outils de détection de fuites mémoire)
valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXEC)

# ==========================================
# NETTOYAGE
# ==========================================

# Supprimer les fichiers .o
clean:
	rm -f $(OBJ)
	@echo "✅ Fichiers .o supprimés"

# Supprimer l'exécutable + les .o
fclean: clean
	rm -f $(EXEC)
	@echo "✅ Programme et fichiers .o supprimés"

# Recompiler entièrement
re: fclean all

# Afficher l'aide
help:
	@echo "Cibles disponibles:"
	@echo "  make        - Compiler le projet (défaut)"
	@echo "  make run    - Compiler et exécuter"
	@echo "  make valgrind - Lancer avec Valgrind"
	@echo "  make clean  - Nettoyer les .o"
	@echo "  make fclean - Nettoyer tout"
	@echo "  make re     - Tout recompiler"
	@echo "  make help   - Afficher cette aide"
