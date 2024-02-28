![SA](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-A.png)

## Creacion de Script

## Creamos un script llamado saludoscript.sh y un servicio llamado saludo.service:

1. Primero se crea la variables del GITHUB_USER y otra variable API_URL para la toma de datos
   ![SGU](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-GU.gif)

---

2. Se toman los datos y se ingresan a la variable RESPONSE
   ![SGD](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-GD.gif)

---

3. De la variable RESPONSE se sacan los datos para las variables solicitadas
   ![SGV](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-GV.gif)

### NOTA:

Para ejecutar el comando _jq_ se instala el mismo con el siguiente comando:
![SJP](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-JP.gif)

---

4. Se crea el mensaje en una variable y se muestra
   ![SPR](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-PR.gif)

---

5. Por ultimo se crea la carpeta y el archivo log con el nombre _saludos.log_ y la carpeta en _/tmp/date_
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

Comando para la creacion del crontab, este lo ingresamos en la terminal y no importa la ruta donde lo ejecute siempre y cuando se ponga vien la ruta donde este el archivo a ejecutarse

```javascript
(crontab -l ; echo "*/2 * * * * cd /home/henrrybran/Documents/SO1-2024/Actividades-Clase/so1_actividades_201314439/actividad2/ && ./Tarea2.sh") | crontab -
```

---

## ![SCRON](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-CRO.gif)

Mostramos como esta el crontab en la terminal y como se esta ejecutando
![SCRON](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-CRO2.gif)

---

Mostramos como se efectuo el cambio con syslog

```javascript
tail -f /var/log/syslog
```

Mostramos como esta el crontab en la terminal y como se esta ejecutando
![SCRON](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad2/Img/S-CRON3.gif)

---
