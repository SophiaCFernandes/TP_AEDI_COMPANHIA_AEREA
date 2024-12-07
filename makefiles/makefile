# Nome do compilador
CXX = g++

# Nome do executável final
TARGET = companhia_aerea

# Flags de compilação
CXXFLAGS = -Wall -Wextra -g -std=c++17

# Diretórios de origem e construção
SRC = ../source_files
BUILD = ./build

# Todos os arquivos .cpp
SRCS = $(wildcard $(SRC)/*.cpp)

# Gerar os arquivos objeto correspondentes
OBJS = $(SRCS:$(SRC)/%.cpp=$(BUILD)/%.o)

# Regra padrão para compilar o projeto
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Comentar para windows
# Regra para gerar arquivos .o a partir de .cpp
$(BUILD)/%.o: $(SRC)/%.cpp
	@mkdir -p $(BUILD)  # Garante que a pasta build exista
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Para windows descomentar
#@if not exist $(BUILD) mkdir $(BUILD)

# Comentar para windows
# Limpeza de arquivos gerados
clean:
	rm -rf $(BUILD) $(TARGET)

# Descomentar para windows
# clean:
# 	del /q /s $(BUILD)\* $(TARGET).exe
# 	rmdir /q /s $(BUILD)
