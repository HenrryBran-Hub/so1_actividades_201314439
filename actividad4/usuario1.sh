#!/bin/bash

while true; do
    read message
    echo "Mensaje Usuario 1: $message" > usuario1_salida
    if [[ "$message" == "Salir" ]]; then
        break
    fi
done < usuario1_entrada
