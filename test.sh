#!/bin/bash

# Dynamic Variables
PROGRAM=main
TOTAL=5 # number of tests

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0m'

# Language Settings
COMPILE="make"

EXE="bin/tp0.out"



# Checks if compiled program already exists
$COMPILE

# Loop sobre os diferentes valores de SECONDS
for SECONDS_VAL in 105 120
do
    echo "Testando com SECONDS=$SECONDS_VAL" >> out.txt 
    echo "Testando com SECONDS=$SECONDS_VAL"

    # Definir SECONDS
    sed -i "s/#define SECONDS .*/#define SECONDS $SECONDS_VAL/" ./src/main.cpp
    
    # Compilar e executar o programa
    g++ -o ./bin/tp0.out ./src/main.cpp
    ./bin/tp0.out >> out.txt 

    echo "----------------------------------------"
done


# Displays final results
if [[ $FAILED -eq 0 ]]; then
  echo -e "\n ${GREEN}√${RESET} All Tests successful.\n"
else
  if [[ $FAILED -eq 1 ]]; then
    echo -e "\n ${RED}x${RESET} ${FAILED} Test failed.\n"
  else
    echo -e "\n ${RED}x${RESET} ${FAILED} Tests failed.\n"
  fi
fi
