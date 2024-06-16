#!/bin/bash
# Script para compilar e executar o projeto de ordenação

echo "Compilando o projeto..."
clang++ -std=c++11 -o sorting_project/compiled/main sorting_project/main.cpp sorting_project/merge_sort.cpp sorting_project/quick_sort.cpp sorting_project/shell_sort.cpp sorting_project/counting_sort.cpp sorting_project/bucket_sort.cpp sorting_project/radix_sort.cpp sorting_project/bubble_sort.cpp sorting_project/insertion_sort.cpp sorting_project/selection_sort.cpp

echo "Executando o programa..."
./sorting_project/compiled/main > log.txt 2>&1