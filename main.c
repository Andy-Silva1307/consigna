#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main() {
    int num_zonas;
    char buffer[100];
    do {
        printf("Ingrese el numero de zonas a calcular: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &num_zonas) != 1 || num_zonas <= 0 || num_zonas > 5) {
                printf("El numero ingresado no es correcto.\n");
                num_zonas = 0; 
            }
        }
    } while (num_zonas <= 0);
    ZonaContaminacion *zonas = (ZonaContaminacion *)malloc(num_zonas * sizeof(ZonaContaminacion));
    if (zonas == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }
    printf("Sistema de control y proyeccion de la contaminacion del aire\n");
    obtenerDatosContaminacion(zonas, num_zonas);
    calcularPromedioContaminacion(zonas, num_zonas);
    predecirContaminacion(zonas, num_zonas);
    emitirAlertas(zonas, num_zonas);
    generarRecomendaciones(zonas, num_zonas);
    guardarDatosEnArchivo(zonas, num_zonas);
    leerDatosDeArchivo(zonas, num_zonas);
    free(zonas);
    return 0;
}
