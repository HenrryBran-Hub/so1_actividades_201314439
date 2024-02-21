![10](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad3/Img/10.png)

## Creacion de Script

## Creamos un script llamado saludoscript.sh y un servicio llamado saludo.service:

1. Primero Creamos los archivos  en la carpeta /home/henrrybran/Documents/Servicio/ con el siguiente contenido:

#### adjuntamos script de saludo
```javascript
#!/bin/bash
while true; do
    FECHA=$(date +'%Y%m%d')
    echo "Hola, la fecha actual es: $FECHA"
    sleep 1
done
```

#### adjuntamos script de saludo de servicio
```javascript
[Unit]
Description=Servicio de saludo infinito

[Service]
ExecStart=/home/henrrybran/Documents/Servicio/saludoscript.sh
Restart=always

[Install]
WantedBy=multi-user.target
```

   ![1](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad3/Img/1.gif)

#### NOTA: Habilitar el archivo como ejecutable

   ![5](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad3/Img/5.gif)

#### Ejecutamos el siguiente comando
```javascript
chmod +x /home/henrrybran/Documents/Servicio/saludoscript.sh
```

---

2. Ejecutamos comando para mover

   ![2](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad3/Img/2.gif)

#### Ejecutamos el siguiente comando
```javascript
sudo mv saludo.service /etc/systemd/system/
```

---

3. Habilitamos el servicio

   ![3](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad3/Img/3.gif)

#### Ejecutamos el siguiente comando

```javascript
sudo systemctl enable saludo.service
```
---

4. Iniciamos el servicio

   ![4](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad3/Img/4.gif)

#### Ejecutamos el siguiente comando

```javascript
sudo systemctl start saludo.service
```

---

5. Verificamos estatus del servicio

   ![6](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad3/Img/6.gif)

#### Ejecutamos el siguiente comando

```javascript
sudo systemclt status saludo.service
```
Otra forma de verificar el servicio seria listar los servicios

   ![7](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad3/Img/7.gif)

#### Ejecutamos el siguiente comando

```javascript
systemctl list-units --type=service
```

Otra forma seria mediante los logs de servicios

#### Ejecutamos el siguiente comando

```javascript
journalctl -u saludo.service
```

---

6. Paramos el servicio

   ![8](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad3/Img/8.gif)

#### Ejecutamos el siguiente comando

```javascript
sudo systemclt stop saludo.service
```

---

7. Eliminamos el servicio

   ![9](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad3/Img/9.gif)

#### Ejecutamos el siguiente comando

```javascript
sudo systemctl disable saludo.service
sudo rm /etc/systemd/system/saludo.service
```

---