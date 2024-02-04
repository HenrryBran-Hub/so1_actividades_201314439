#!/bin/bash

# Declaramos la variable
GITHUB_USER="HenrryBran-Hub"

# Declaramos la direccion con la variable anterior
API_URL="https://api.github.com/users/${GITHUB_USER}"

# Ingresamos el reultado del curl a una variable que castearemos despues
RESPONSE=$(curl -s "$API_URL")

# Extraemos los datos de la variable RESPONSE github_user
github_user=$(echo "$RESPONSE" | jq -r '.login')
# Extraemos los datos de la variable RESPONSE github_id
github_id=$(echo "$RESPONSE" | jq -r '.id')
# Extraemos los datos de la variable RESPONSE github_created_at
github_created_at=$(echo "$RESPONSE" | jq -r '.created_at')

# Imprimimos mensaje 
MSG="Hola $github_user. User Id: $github_id. Cuenta fue creada el: $github_created_at."
echo "$MSG"

# ---------------CREAMOS EL LOG---------------
# Obtenemos fecha
FECHA=$(date +'%Y%m%d')

# Creamos el directorio
PATH_LOG="/tmp/$FECHA/"
mkdir -p "$PATH_LOG"

# Creamos el archivo log
LOG_FILE="$PATH_LOG/saludos.log"

# Escribimos el log
echo "$MSG" >> "$LOG_FILE"
