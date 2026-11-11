# Sistema de Planilla Hospitalaria

Proyecto de Programación #2 del curso EIF201 Programación I, Universidad Nacional, Sección Regional Central Occidente.

Aplicación de consola en C++ para administrar la planilla de un hospital: departamentos y puestos, empleados (médicos, enfermeros y administrativos), cálculo de salarios con deducciones de ley y procesamiento de pagos. Los datos se guardan en archivos de texto.

## Integrantes

| Nombre | Cédula |
|---|---|
| Marco Jiménez Acosta | 120100776 |

Proyecto individual, autorizado por el profesor.

## Cómo compilar y ejecutar

**Requisitos:** Windows y ZinjaI (compilador g++ con C++14).

1. Descargar el repositorio con **Code → Download ZIP** y **extraer** todo el ZIP.
2. Abrir `Proyecto final.zpr` con ZinjaI.
3. Presionar **F9** para compilar y ejecutar.

También se puede compilar desde la consola, dentro de la carpeta del proyecto y con `g++` disponible:

```
g++ -std=c++14 *.cpp -o planilla.exe
planilla.exe
```

El programa debe ejecutarse desde la carpeta donde están `empleados.txt` y `departamentos.txt`. Si se abre el `.exe` con doble clic fuera de ZinjaI, Windows puede indicar que faltan bibliotecas del compilador.

## Guía de uso

Cada opción se elige escribiendo su número y presionando Enter.

| Menú principal | Opciones |
|---|---|
| **1. Departamentos y puestos** | Agregar departamento, agregar puesto, eliminar puesto, listar departamentos y eliminar departamento |
| **2. Empleados** | Registrar, consultar, modificar, registrar horas extra y bonos del mes, eliminar y listar empleados |
| **3. Planilla y pagos** | Calcular la planilla de un período, ver un comprobante, listar comprobantes, procesar un pago, procesar todos los pagos de un período y ver el resumen de un período |
| **0. Salir** | Cierra el programa |

**Flujo básico:**

1. En **Empleados**, registrar las horas extra y los bonos del mes.
2. En **Planilla y pagos**, calcular la planilla del período.
3. Revisar los comprobantes y procesar los pagos.

**Formato de los datos:**

- El período se escribe como `AAAA-MM`, por ejemplo `2026-11`.
- Los decimales se escriben con punto, por ejemplo `1500000.50`.
- Si un dato no es válido, el programa muestra el error y lo vuelve a pedir.

**Reglas importantes:**

- Cada empleado puede tener un solo comprobante por período.
- No se puede eliminar un empleado que tenga comprobantes.
- No se puede eliminar un departamento que tenga empleados o comprobantes.

## Archivos de datos

| Archivo | Contenido |
|---|---|
| `empleados.txt` | Empleados registrados |
| `departamentos.txt` | Departamentos y sus puestos |
| `planilla.txt` | Comprobantes de pago. El programa lo crea al generar la primera planilla |

Los datos se cargan automáticamente al iniciar y se guardan después de cada cambio. El repositorio incluye empleados y departamentos de ejemplo.

## Diagrama UML

La carpeta `UML` contiene el diagrama de clases y su archivo editable.
