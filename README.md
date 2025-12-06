# **Nemergent – C**

Nemergent es un programa multi-hilo en C que genera números aleatorios y los clasifica en dos listas: positivos y negativos.
Cada hilo genera una cantidad configurable de números y los añade a las listas compartidas utilizando *mutex* para garantizar la seguridad en concurrencia.
Al finalizar la ejecución, ambas listas se ordenan e imprimen por pantalla.

---

## **Compilación**

```bash
make
```

Esto generará el ejecutable:

```
nemergent
```

---

## **Uso**

El programa recibe dos argumentos:

```bash
./nemergent <num_threads> <numbers_per_thread>
```

* **num_threads**: número total de hilos a crear (> 0)
* **numbers_per_thread**: números aleatorios generados por cada hilo (> 0)

Ejemplo:

```bash
./nemergent 5 100
```

Ante parámetros incorrectos, el programa mostrará un mensaje de error y la guía de uso.

---

## **Funcionamiento**

* Generación de números con `rand_r()` → rango: `INT_MIN` a `INT_MAX`.
* Separación en listas de números **positivos** y **negativos**.
* Uso de `pthread_mutex_t` para proteger las listas compartidas.
* Ordenación ascendente final antes de imprimir las listas.
* Sin *memory leaks* y sin *segfaults*.

---

## **Makefile – Comandos disponibles**

El proyecto incluye un Makefile con los siguientes comandos:

### **Compilación**

```bash
make
```

Compila el programa y genera `nemergent`.

---

### **Limpieza**

```bash
make clean
```

Elimina la carpeta `obj/` y archivos `.log`.

```bash
make fclean
```

Hace lo mismo que `clean` y además borra el ejecutable.

```bash
make re
```

Reconstruye todo desde cero (equivalente a `fclean` + `make`).

---

## **Ejecución rápida para pruebas**

```bash
make test
```

Ejecuta el programa con valores por defecto definidos en el Makefile:

```makefile
VALGRIND_THREADS ?= 2
VALGRIND_NUMBERS ?= 42
```

---

## **Herramientas de análisis**

### **Valgrind (memory leaks)**

```bash
make valgrind
```

Ejecuta Valgrind con configuración completa y vuelca el resultado en `valgrind.log`.

---

### **Helgrind (race conditions)**

```bash
make helgrind
```

Ejecuta Valgrind Helgrind para detectar errores de concurrencia y guarda el informe en `helgrind.log`.
