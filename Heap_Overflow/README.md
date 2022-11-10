# Heap Overflow

Para seguir los pasos que se han dado hay que ir a la carpeta *capturas*. Los pasos dados se encuentran numerados desde el número 1.

**Encontrar heap**: En mi caso el heap se encuentra en la dirección 0x405000

**Encontrar XXXX**: En mi caso la dirección donde se guardaban las cuatro X es 0x4052a0

**Cambio a python3:** Se ha cambiado los scripts en python para que estén escritos en python3. Los cambios eran añadir un 3 donde pone *python* en la primera línea de código
y poner los paréntesis en los prints.

**Calculo de resta:** La resta en nuestro caso sería de la dirección 0x4052f0 que es donde está f_esperando_fuera y 0x4052a0 que es donde están las X.

**OBSERVACIÓN:** A pesar de seguir todos los pasos de manera correcta no se ha conseguido hacer que se ejecute la función f_pasar ya que sigue dando violación del 
segmento. Esto puede deberse a que en mi caso, en ensamblador, aparece la orden "endbr64" y en los apuntes no pero se ha intentado compilar el programa para 
que no aparezca esa orden usando compilando con la opción `-mmanual-endbr` y el resultado ha sido el mismo. 
He supuesto este problema debido a esta discusión en StackOverflow: https://stackoverflow.com/questions/56905811/what-does-the-endbr64-instruction-actually-do

**ACTUALIZACIÓN:** Se ha conseguido hacer el heap overflow pasando el último script a python2 y poniendo la dirección de memoria en little endian. Se observa que se ha conseguido en la captura siguiente.

![](https://github.com/AlvaroRodriguez9/DPS/blob/main/Heap_Overflow/Capturas/11.png)
