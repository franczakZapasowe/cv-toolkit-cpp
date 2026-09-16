# MyOpenCVTools 

Prosta, autorska biblioteka C++ ułatwiająca i przyspieszająca pracę z przetwarzaniem obrazu przy użyciu OpenCV. Projekt stworzony z myślą o wygodnym wielokrotnym wykorzystaniu gotowych narzędzi w różnych aplikacjach wizyjnych.

## Funkcjonalności

*   **HSV Color Picker (`showColorPicker`)**: Interaktywne narzędzie z suwakami, które zatrzymuje działanie programu, pozwala na żywo wykalibrować maskę koloru w przestrzeni HSV i zwraca gotową strukturę z zakresem wartości (min/max).

## Wymagania

Aby skompilować projekt, potrzebujesz:
*   Kompilatora wspierającego standard **C++20**
*   **CMake** (wersja min. 3.10)
*   **OpenCV** (zainstalowane w systemie, np. wersja 4.x)

## Budowanie projektu (Linux)

Projekt wykorzystuje standardowy proces budowania oparty na CMake. Wpisz w terminalu następujące komendy:

```bash
# 1. Konfiguracja projektu i utworzenie folderu build
cmake -B build

# 2. Kompilacja kodu
cmake --build build
