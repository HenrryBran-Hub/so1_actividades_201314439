![SA](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-A.png)

## Creacion de Script

Creamos un script llamado Tarea2.sh  y despues ingresamos a el y hacemos lo siguiente:
---

1. Primero se crea la variables del GITHUB_USER y otra variable API_URL para la toma de datos
![SGU](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-GU.gif)
---

2. Se toman los datos y se ingresan a la variable RESPONSE
![SGD](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-GD.gif)
---

3. De la variable RESPONSE se sacan los datos para las variables solicitadas
![SGV](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-GV.gif)
---

### NOTA:
para ejecutar el comando *jq* se instala el mismo con el siguiente comando:
![SJP](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-JP.gif)
---

4. Se crea el mensaje en una variable y se muestra
![SPR](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-PR.gif)
---

5. Por ultimo se crea la carpeta y el archivo log con el nombre *saludos.log* y la carpeta en */tmp/date*
![SLO](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-LO.gif)
---

6. Ejecutamos para probar pero antes tenemos que darle permisos de ejecucion al archivo creado

A. Permisos al archivo(buscamos en la carpeta donde lo creamos y ejecutamos lo siguiente)
![SSU](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-SU.gif)
---

B. Ejecutamos el archivo
![SFUN](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-FUN.gif)
---

7. Comprobamos la cracion de la carpeta y el archivo 
![SLOG](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-LOG.gif)
---

## adjuntamos script 
```javascript
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

```

## Creacion del cronjob

