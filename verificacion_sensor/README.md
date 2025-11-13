# 🧩 Ejemplo de Verificación y Validación en Sistemas Embebidos

Este ejemplo demuestra cómo aplicar **verificación unitaria en C** usando `gcc` sin frameworks externos.

---

## ⚙️ Requisitos

Instala las herramientas necesarias:

```bash
sudo dnf install gcc make git -y
# o en Ubuntu:
# sudo apt install gcc make git -y
```

Para análisis adicional:
```bash
sudo dnf install valgrind cppcheck -y
```

---

## 📁 Estructura del Proyecto

```
verificacion_sensor/
├── src/
│   ├── sensor_bad.c
│   └── sensor.c
├── test/
│   └── test_harness.c
└── Makefile
```

---

## 🚀 Compilación y Ejecución

### 1️⃣ Compilar versión con error:
```bash
make test_bad
./test_bad
```

Salida esperada:
```
FAIL: test_sensor_init - Expected 0.00, Got 3.12
Tests completed.
```

### 2️⃣ Compilar versión corregida:
```bash
make test_fixed
./test_fixed
```

Salida esperada:
```
PASS: test_sensor_init
Tests completed.
```

---

## 🔍 Verificación adicional

### Análisis estático
```bash
cppcheck src/
```

### Validación de memoria
```bash
valgrind ./test_fixed
```

---

## 🧹 Limpieza
```bash
make clean
```

---

## 🧠 Explicación

- `sensor_bad.c`: error de inicialización (`count` no inicializado)
- `sensor.c`: versión corregida
- `test_harness.c`: prueba unitaria sencilla
- `Makefile`: automatiza compilación y limpieza

---

## 👨‍🔧 Autor
**Rodrigo Venegas Mora**  
Ejemplo académico para Verificación y Validación en Sistemas Embebidos.
