---
title: "Metodologías de Verificación y Validación en Sistemas Embebidos"
author: "Rodrigo Venegas Mora"
date: "Noviembre 2025"
theme: "Madrid"
colortheme: "beaver"
---

# Metodologías de Verificación y Validación
### Rodrigo Venegas Mora 



---

## 1. Introducción

- Los sistemas embebidos integran hardware y software dedicados.  
- Ámbitos: automoción, robótica, industria, biomédico.  
- **Verificación:** comprobar que el sistema fue construido correctamente.  
- **Validación:** confirmar que cumple su propósito.  

> La V&V garantiza confiabilidad, seguridad y cumplimiento de normas internacionales.


---

## 2. Importancia en Ingeniería Electrónica

- Los ingenieros electrónicos diseñan hardware, firmware y sistemas mixtos.
- Un fallo puede provocar pérdidas económicas o riesgos de seguridad.
- V&V ayuda a minimizar errores y cumplir estándares como **IEC 61508**.

![bg right:50%](https://upload.wikimedia.org/wikipedia/commons/a/a5/Electronic_circuit_board.jpg)

---

## 3. Niveles de Aplicación V&V

| Nivel | Ejemplo de Verificación | Ejemplo de Validación |
|--------|------------------------|-----------------------|
| Hardware | Simulación SPICE | Prototipo físico |
| Firmware | Pruebas unitarias | HIL / emulador |
| Sistema | Integración HW/SW | Pruebas funcionales |

➡️ La trazabilidad entre requisitos y pruebas es crítica.

---

## 4. Modelo V de Desarrollo

![bg 80%](https://upload.wikimedia.org/wikipedia/commons/4/4e/V-model.svg)

> Cada fase de desarrollo tiene su prueba de verificación y validación asociada.

---

## 5. Metodologías Modernas

- **SiL / HIL:** simulaciones en tiempo real.
- **CI/CD:** automatización de pruebas.
- **TDD/BDD:** código impulsado por pruebas.
- **Digital Twins:** gemelos digitales para validación continua.

> *Tendencia 2023–2025: integración de V&V con IA y DevOps.*

---

## 6. Técnicas de Verificación

- **Análisis estático:** SonarQube, Coverity.
- **Simulación:** LTSpice, Proteus, HDL.
- **Pruebas unitarias:** Unity, Google Test.
- **Comunicación:** python-can, Wireshark.
- **HIL:** Simulink Real-Time, dSPACE.

![bg right:45%](https://upload.wikimedia.org/wikipedia/commons/5/59/Logic_analyzer.jpg)

---

## 7. Técnicas de Validación

- **Pruebas funcionales:** cumplimiento de requisitos.
- **Desempeño y robustez:** latencia, energía, fallos.
- **Ambientales:** temperatura, vibración, EMI/EMC.
- **Cumplimiento normativo:** ISO 26262, IEC 61508.

![bg right:50%](https://upload.wikimedia.org/wikipedia/commons/6/66/Vibration_test_equipment.jpg)

---
## 8. Automatización y CI/CD

| Etapa | Herramientas |
|--------|-----------------------------|
| Análisis estático | SonarQube, Coverity |
| Pruebas unitarias | Unity, CppUTest |
| Simulación y HIL | Simulink, dSPACE |
| Comunicación | python-can, Wireshark |
| Integración continua | Jenkins, GitLab CI |

![bg right:50%](https://upload.wikimedia.org/wikipedia/commons/b/bd/Jenkins_logo.svg)

---

## 9. Integración Continua en Firmware

- Compilación, análisis, pruebas y despliegue automáticos.
- Permite detectar errores antes de la integración final.
- Mejora la eficiencia y repetibilidad del desarrollo.

> Un pipeline CI/CD bien configurado puede reducir fallos hasta en un 40%.

---

## 10. Digital Twins en Validación

- Replica digital de un sistema físico.
- Sincroniza datos en tiempo real.
- Facilita mantenimiento predictivo y validación continua.

![bg right:55%](https://upload.wikimedia.org/wikipedia/commons/3/30/Digital_twin_concept.png)

---
## 11. 💡 Clasificación de herramientas de Verificación y Validación

| 🧩 **Categoría** | 🛠️ **Herramienta** | 💻 **Tipo / Licencia** | 💬 **Uso principal** |
|------------------|------------------|------------------|----------------|
| **Análisis estático** | 🟩 **Cppcheck** | Libre (GPLv3) | Detección de errores en C/C++ |
| | 🟩 **SonarQube (Community)** | Libre / 🟦 Pago (Enterprise) | Métricas de calidad y CI/CD |
| | 🟥 **Coverity** | Comercial (Synopsys) | Cumplimiento MISRA, análisis profundo |
| | 🟥 **Klocwork** | Comercial | Seguridad y código crítico |
| **Pruebas unitarias** | 🟩 **Unity** | Libre (MIT) | TDD para C embebido |
| | 🟩 **CppUTest** | Libre (BSD) | Unit testing y mocks |
| | 🟩 **Google Test** | Libre (BSD) | Framework robusto C++ |
| **Simulación / HIL** | 🟩 **LTSpice, KiCad, Qucs-S** | Libre / Gratis | Simulación eléctrica y esquemática |
| | 🟥 **Proteus, MATLAB/Simulink, dSPACE** | Comercial | Simulación avanzada y HIL |
| **Comunicación / Monitoreo** | 🟩 **python-can, Wireshark** | Libre (MIT / GPL) | Pruebas CAN, análisis de protocolos |
| | 🟦 **Saleae Logic** | Software libre, hardware pago | Captura y decodificación lógica |
| **Integración continua (CI/CD)** | 🟩 **Jenkins** | Libre (MIT) | CI/CD en entornos embebidos |
| | 🟩 **GitLab CI/CD** | Libre (Community) / 🟦 Pago | Pipelines automatizados |
| | 🟩 **GitHub Actions** | Libre (limitado) / 🟦 Pago | CI/CD en GitHub |
| **Gestión de requisitos / trazabilidad** | 🟩 **ReqView, OpenProject, Tuleap** | Libre (GPL) | Gestión y trazabilidad |
| | 🟥 **Polarion ALM, DOORS NG, Jama** | Comercial | Ingeniería de sistemas complejos |

---

## 🔎 Resumen general

| 🔰 Tipo | Ejemplos|
|---------|-----------|
| 🟩 **Software libre / gratuito** | Cppcheck, Unity, Wireshark, Jenkins |
| 🟦 **Freemium / mixto** | SonarQube, GitLab CI/CD, GitHub Actions |
| 🟥 **Comercial / pago** | Coverity, MATLAB, Polarion, DOORS NG |

> 💬 *La mayoría de herramientas de análisis, prueba y CI/CD cuentan con versiones open source adecuadas para proyectos académicos o prototipos industriales.*

---

## 🧠 Recomendación para ingeniería electrónica

- 🔹 **Prototipos o proyectos académicos:** usa herramientas libres → *Cppcheck, Unity, Wireshark, Jenkins.*  
- 🔹 **Entornos industriales o críticos:** se recomienda *Coverity, MATLAB/Simulink, Polarion*.  
- 🔹 **Integración ideal:** análisis estático (Cppcheck) + CI/CD (GitLab) + simulación (LTSpice).



---

## 12. Métricas de Calidad

- Cobertura de código y requisitos.
- Densidad de defectos.
- MTBF (tiempo medio entre fallas).
- Trazabilidad entre pruebas y requisitos.

📈 Permiten evaluar objetivamente la madurez del sistema.

---



## 13. Tendencias Actuales

- **Embedded DevOps:** integración total entre desarrollo, validación y operación.
- **Power HIL:** pruebas en sistemas de potencia.
- **IA aplicada a V&V:** detección automática de anomalías.
- **Automatización total del ciclo de pruebas.**

---



## 14. Conclusiones

- V&V son esenciales para sistemas embebidos confiables.
- Garantizan seguridad, desempeño y conformidad.
- Tendencias: Digital Twins, CI/CD, verificación formal.

---