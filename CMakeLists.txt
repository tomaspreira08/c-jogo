cmake_minimum_required(VERSION 3.10 FATAL_ERROR) # Versão do CMake que você tem (3.10 é comum e segura)

project(JogoVelocidade VERSION 1.0 LANGUAGES CXX) # Define o nome do seu projeto e que ele é C++

# --- Configurações do Qt ---
# Encontra as bibliotecas do Qt.
# Mude para Qt5 se estiver usando Qt5.
# Se o CMake não encontrar o Qt, você pode precisar dizer a ele onde procurar.
# Por exemplo, no Windows, adicione: set(CMAKE_PREFIX_PATH "C:/Qt/6.x.x/mingw_64") antes de find_package.
find_package(Qt6 COMPONENTS Widgets REQUIRED) # 'Widgets' é o módulo para a interface gráfica

# --- Inclui diretórios para seus cabeçalhos (.hpp) ---
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include # Adiciona a pasta 'include'
)

# --- Define o executável do seu jogo ---
# Usamos qt_add_executable porque ele sabe como lidar com os arquivos .ui
qt_add_executable(${PROJECT_NAME}
    src/main.cpp
    src/jogo.cpp
    src/perguntas.cpp
    src/utils.cpp # Ainda que vazia, mantenha aqui por enquanto se quiser.
    src/minhajogojanela.cpp # SEU NOVO ARQUIVO!
    jogo.ui                 # SEU ARQUIVO DE INTERFACE DO QT DESIGNER!
)

# --- Linka as bibliotecas do Qt ao seu executável ---
target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Widgets # Linka o módulo de Widgets do Qt
)

# Opcional: Para facilitar a depuração, você pode querer que o executável apareça mais facilmente
# set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11) # Opcional: Garante C++11