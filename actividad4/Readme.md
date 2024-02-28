![8](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad4/Img/8.png)

## CRACION DE CHAT

1. Creamos los pipes 
   ![1](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad4/Img/1.gif)

```javascript
mkfife usuario1_entrada usuario1_salida usuario2_entrada usuario2_salida
```

---

2. Mostramos los pipes
   ![2](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad4/Img/2.gif)

```javascript
ls -l
```

---

3. Mostramos el contenido de nuestros archivos
   ![3](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad4/Img/3.gif)

#### Archivo usuario1.sh
```javascript
#!/bin/bash

while true; do
    read message
    echo "Mensaje Usuario 1: $message" > usuario1_salida
    if [[ "$message" == "Salir" ]]; then
        break
    fi
done < usuario1_entrada
```

#### Archivo usuario2.sh
```javascript
#!/bin/bash

while true; do
    read message
    echo "Mensaje Usuario 2: $message" > usuario2_salida
    if [[ "$message" == "Salir" ]]; then
        break
    fi
done < usuario2_entrada
```
---

4. Para ejecutar los dos archivos abrimos dos terminales
   ![4](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad4/Img/4.gif)

---

5. Damos permiso de ejecucion a ambos archivos
   ![5](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad4/Img/5.gif)

```javascript
chmod +x usuario1.sh
chmod +x usuario2.sh
```

---

6. Ejecutamos los archivos y probamos si funciona
   ![6](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad4/Img/6.gif)

```javascript
#Para ejecutar el archivo se puede de de varias formas,
bash  usuario1.sh &
bash  usuario2.sh &

#Para mandar mensajes  desde una terminal a la otra

#Para el usuario 1
echo "Mensaje" > usuario2_entrada 
cat usuario1_salida

#Para el usuario 2
echo "Mensaje" > usuario1_entrada 
cat usuario2_salida


```

7. Paramos la ejecucion de los archivos
   ![7](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad4/Img/7.gif)

```javascript
#Para detener la ejecucion de los archivos mandamos el mensaje 
echo "Salir" > usuario2_entrada
echo "Salir" > usuario1_entrada 

#O tambien detenemos la ejecucion con 
kill PID
```