
# Guía paso a paso — temp_control_vv_demo (Errores intencionales y corrección)

Este repositorio contiene un ejemplo didáctico que incluye errores intencionales para practicar
Verificación y Validación (V&V). Sigue los pasos para reproducir la detección de fallos,
corregir el código y verificar la corrección.

---

## Requisitos (instalación)

En Fedora:
```bash
sudo dnf install -y gcc make cppcheck valgrind gcov
```

En Debian/Ubuntu:
```bash
sudo apt update
sudo apt install -y build-essential cppcheck valgrind lcov
```

---

## 1) Preparar y listar archivos
```bash
unzip temp_control_vv_demo.zip -d ~/temp_control_vv_demo
cd ~/temp_control_vv_demo
ls -R
```

Estructura principal: `src/ tests/ docs/ Makefile`

---

## 2) Análisis estático
```bash
make static
```

Busca advertencias sobre variables no inicializadas en `src/sensor.c`.

---

## 3) Ejecutar tests (espera fallos)
```bash
make test
```

Salida esperada (ejemplo):
```
[PASS] test_sensor: value=nan
[FAIL] controller should be ON at 23.0
```

Explicación: el sensor usa variable no inicializada -> puede producir NaN; el controlador tiene lógica invertida.

---

## 4) Análisis dinámico: Valgrind
```bash
make valgrind_test
```

Verás mensajes de uso de valores no inicializados y fugas de memoria (definitely lost).

---

## 5) Inspección del código defectuoso
Abre `src/sensor.c` y `src/controller.c`. Encontrarás comentarios `BUG` donde están los errores.

---

## 6) Parches recomendados (reemplaza archivos con los siguientes contenidos)

### Corregir `src/sensor.c` (reemplazar por):
```c
#include "sensor.h"
#include <stdlib.h>
#include <time.h>

float read_temperature(void) {
    float base = 25.0f;
    static int seeded = 0;
    if (!seeded) { srand((unsigned)time(NULL)); seeded = 1; }
    float noise = ((float)(rand() % 1001) / 1000.0f - 0.5f);
    return base + noise;
}
```

### Corregir `src/controller.c` (reemplazar por):
```c
#include "controller.h"

int control_heater(float temp, float setpoint) {
    float h = 0.5f;
    if (temp < setpoint - h) {
        return 1; /* Heater ON */
    }
    if (temp > setpoint + h) {
        return 0; /* Heater OFF */
    }
    return -1; /* No change in hysteresis band */
}
```

---

## 7) Aplicar cambios y verificar
Reemplaza los archivos con un editor o con comandos:
```bash
# ejemplo con cat heredoc
cat > src/sensor.c << 'EOF'
#include "sensor.h"
#include <stdlib.h>
#include <time.h>

float read_temperature(void) {
    float base = 25.0f;
    static int seeded = 0;
    if (!seeded) { srand((unsigned)time(NULL)); seeded = 1; }
    float noise = ((float)(rand() % 1001) / 1000.0f - 0.5f);
    return base + noise;
}
EOF

cat > src/controller.c << 'EOF'
#include "controller.h"

int control_heater(float temp, float setpoint) {
    float h = 0.5f;
    if (temp < setpoint - h) {
        return 1;
    }
    if (temp > setpoint + h) {
        return 0;
    }
    return -1;
}
EOF

make clean
make test
```

Salida esperada:
```
[PASS] test_sensor: value=25.123456
[PASS] test_controller
All tests passed.
```

---

## 8) Verificación final con Valgrind y cobertura (opcional)
```bash
make valgrind_test
make coverage
```

Valgrind no debe reportar uso de valores no inicializados ni fugas. `gcov` mostrará líneas ejecutadas.

---

## 9) Registro de cambios
Documenta en `docs/guia_vv_demo.md` lo que hiciste: errores detectados, herramientas y evidencia de corrección.

---

¡Listo! Ahora tienes un flujo reproducible para demostrar detección y corrección de errores con V&V.
