# CPP Calculator V2

Dit project is versie 2 van de C++ Calculator. Zie [GitHub](https://github.com/NHLStenden/CppCalculatorV1) voor
de eerste versie.

Dit project maakt gebruik van twee klassen om de functionaliteit testbaar te maken. Er worden een aantal
tests aangeboden die met Google Tests geautomatiseerd kunnen worden. Daarmee wordt het ook mogelijk om deze
tests in een GitHub Actions omgeving te activeren. Zo wordt het mogelijk om bij het push-en van een nieuwe
GIT *commit* deze tests uit te laten voeren.

# Uitleg bij het bouwen van het project

Het bouwen van het project wordt gedaan via CMake. Hiervoor is een `CMakeLists.txt` bestand aangemaakt.
Hieronder volgt de uitleg van deze configuratie.

Deze CMakeLists.txt is een geavanceerdere versie van de vorige en voegt extra functies toe, zoals het opdelen van de
code in een bibliotheek en ondersteuning voor tests.

## Minimale CMake-versie instellen

```cmake
   cmake_minimum_required(VERSION 3.25)
```

Dit betekent dat CMake 3.25 of hoger nodig is om het project te kunnen bouwen. Oudere versies kunnen fouten geven als
bepaalde functies ontbreken.

## Projectnaam instellen

```cmake
   project(CppCalculator_v2)
```

Hiermee wordt het project CppCalculator_v2 genoemd. Dit helpt bij het organiseren van bestanden en instellingen binnen
CMake.

## standaard instellen

```cmake
   set(CMAKE_CXX_STANDARD 20)
```

Hiermee wordt C++20 ingeschakeld, wat nodig is als het project functies uit deze standaard gebruikt.

## Linkeropties instellen

```cmake
   set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")
```

Deze regels zorgen ervoor dat de gegenereerde uitvoerbare bestanden statisch worden gelinkt.

## Een statische bibliotheek maken

```cmake
   add_library(calculator STATIC Calculator.cpp Parser.cpp)
```

Dit maakt een statische bibliotheek (calculator.a of calculator.lib op Windows) van de bestanden Calculator.cpp en
Parser.cpp.
Een statische bibliotheek betekent dat de code wordt ingebouwd in de einduitvoer, in plaats van als een aparte dll of
so-bestand.

## De hoofdapplicatie maken

```cmake
   add_executable(calculator_exe main.cpp)
```

Dit maakt een uitvoerbaar bestand (calculator_exe) van main.cpp.
Dit is het bestand dat uiteindelijk wordt uitgevoerd door de gebruiker.

## De bibliotheek koppelen aan de executable

```cmake
   target_link_libraries(calculator_exe PRIVATE calculator)
```

Hier wordt de calculator bibliotheek gelinkt aan de executable calculator_exe.
Dit betekent dat de code uit Calculator.cpp en Parser.cpp beschikbaar is in main.cpp.

## Ondersteuning voor tests toevoegen

```cmake
   enable_testing()
add_subdirectory(tests)
```

`enable_testing()` zorgt ervoor dat CMake testondersteuning inschakelt.
`add_subdirectory(tests)` vertelt CMake om ook in de "tests" map te zoeken naar een extra CMakeLists.txt waarin
testinstellingen staan.
Dit betekent dat er in de map tests/ een extra CMakeLists.txt bestand moet zijn waarin tests worden gedefinieerd,
bijvoorbeeld met Google Test of Catch2.

# Hoe compileer je dit project?

In de regel zal je een CMake project kunnen maken in je IDE. Deze zal de CmakeLists.txt oppakken en gebruiken om een
run-configuratie te maken. 

Als je gebruik wilt maken van bijvoorbeeld Cygwin dan is hier een stap-voor-stap handleiding voor `Cygwin` gebruikers:

# Pakketten nodig

Controleer of de juiste Cygwin-pakketten geïnstalleerd zijn. Bij het installeren van Cygwin moet je de juiste pakketten 
selecteren. Open de Cygwin Setup en voeg de volgende pakketten toe als je ze nog niet hebt geïnstalleerd:

Essentiële pakketten:

* gcc-g++ → De C++ compiler
* make → Voor standaard Makefiles
* cmake → Om CMake te kunnen gebruiken
* binutils → Bevat belangrijke tools zoals de linker
* gdb (optioneel) → Debugging tool

* Als je Cygwin al hebt geïnstalleerd, kun je de setup opnieuw uitvoeren en deze pakketten toevoegen.

## Open PowerShell

Start de Cygwin Shell 

## Ga naar de projectmap

```shell
   cd /cygdrive/c/mijn/project/map/
```

## Maak een 'build'-map en ga erin

```shell
mkdir build
cd build
```

## Genereer de build-bestanden met CMake

```shell
cmake ..
```

## Compileer het project

```shell
cmake --build .
```

## Voer het programma uit

```shell
./calculator_exe.exe
```

## (Optioneel) Tests uitvoeren

Als er tests zijn toegevoegd in de tests map, kun je ze uitvoeren met:

```shell
ctest
```


# Referenties
* CMake [https://cmake.org/](https://cmake.org/)
* Cygwin [https://www.cygwin.com/](https://www.cygwin.com/)
