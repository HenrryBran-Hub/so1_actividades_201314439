#!/bin/bash

while true; do
    read message
    echo "Mensaje Usuario 2: $message" > usuario2_salida
    if [[ "$message" == "Salir" ]]; then
        break
    fi
done < usuario2_entrada
