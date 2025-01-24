#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void obtenerDatosContaminacion(ZonaContaminacion zonas[], int num_zonas) {
    for (int i = 0; i < num_zonas; i++) {
        printf("Ingrese el nombre de la zona %d: ", i+1);
        scanf("%s", zonas[i].nombre);
        printf("Ingrese los datos para la zona %s:\n", zonas[i].nombre);
        do {
            printf("CO2 (ppm): ");
            scanf("%f", &zonas[i].co2);
            if (zonas[i].co2 < 0) {
                printf("Valor incorrecto.\n");
            }
        } while (zonas[i].co2 < 0);
        do {
            printf("SO2 (ppm): ");
            scanf("%f", &zonas[i].so2);
            if (zonas[i].so2 < 0) {
                printf("Valor incorrecto.\n");
            }
        } while (zonas[i].so2 < 0);
        do {
            printf("NO2 (ppm): ");
            scanf("%f", &zonas[i].no2);
            if (zonas[i].no2 < 0) {
                printf("Valor incorrecto. \n");
            }
        } while (zonas[i].no2 < 0);
        do {
            printf("PM2.5 (microgramos*metro cubico): ");
            scanf("%f", &zonas[i].pm25);
            if (zonas[i].pm25 < 0) {
                printf("Valor incorrecto.\n");
            }
        } while (zonas[i].pm25 < 0);
            printf("Temperatura (en grados): ");
            scanf("%f", &zonas[i].temperatura);
        do {
            printf("Velocidad del viento (km/h): ");
            scanf("%f", &zonas[i].viento);
            if (zonas[i].viento < 0) {
                printf("Valor incorrecto. \n");
            }
        } while (zonas[i].viento < 0);
        do {
            printf("Humedad (%%): ");
            scanf("%f", &zonas[i].humedad);
            if (zonas[i].humedad < 0) {
                printf("Valor incorrecto.\n");
            }
        } while (zonas[i].humedad < 0);
    }
}
void calcularPromedioContaminacion(ZonaContaminacion zonas[], int num_zonas) {
    printf("\n--- Valores de Contaminacion ---\n");
    for (int i = 0; i < num_zonas; i++) {
        float promedio_co2 = 0, promedio_so2 = 0, promedio_no2 = 0, promedio_pm25 = 0;
        for (int j = 0; j < 30; j++) { 
            promedio_co2 += zonas[i].co2; 
            promedio_so2 += zonas[i].so2;
            promedio_no2 += zonas[i].no2;
            promedio_pm25 += zonas[i].pm25;
        }
        printf("Promedio de CO2 para la zona %s: %.2f ppm\n", zonas[i].nombre, promedio_co2 / 30);
        printf("Promedio de SO2 para la zona %s: %.2f ppm\n", zonas[i].nombre, promedio_so2 / 30);
        printf("Promedio de NO2 para la zona %s: %.2f ppm\n", zonas[i].nombre, promedio_no2 / 30);
        printf("Promedio de PM2.5 para la zona %s: %.2f mcg*m3\n", zonas[i].nombre, promedio_pm25 / 30);
        printf("-----------------------------------\n");
    }
}
void predecirContaminacion(ZonaContaminacion zonas[], int num_zonas) {
    printf("\n--- Proyecciones de Contaminacion ---\n");
    for (int i = 0; i < num_zonas; i++) {
        float prediccion_co2 = zonas[i].co2 * 0.7; 
        float prediccion_so2 = zonas[i].so2 * 0.7;
        float prediccion_no2 = zonas[i].no2 * 0.7;
        float prediccion_pm25 = zonas[i].pm25 * 0.7;
        printf("Prediccion de CO2 para la zona %s: %.2f ppm\n", zonas[i].nombre, prediccion_co2);
        printf("Prediccion de SO2 para la zona %s: %.2f ppm\n", zonas[i].nombre, prediccion_so2);
        printf("Prediccion de NO2 para la zona %s: %.2f ppm\n", zonas[i].nombre, prediccion_no2);
        printf("Prediccion de PM2.5 para la zona %s: %.2f \u00b5g/m3\n", zonas[i].nombre, prediccion_pm25);
        printf("-----------------------------------\n");
    }
}
void emitirAlertas(ZonaContaminacion zonas[], int num_zonas) {
    printf("\n--- Alerta de Contaminacion ---\n");
    for (int i = 0; i < num_zonas; i++) {
        if (zonas[i].co2 > 400 || zonas[i].so2 > 0.05 || 
            zonas[i].no2 > 0.06 || zonas[i].pm25 > 25) {
            printf("!ALERTA! La zona de %s excede los limites de contaminacion\n", zonas[i].nombre);
        }
    }
    printf("-----------------------------------\n");
}
void generarRecomendaciones(ZonaContaminacion zonas[], int num_zonas) {
    printf("\n--- Recomendaciones ---\n");
    for (int i = 0; i < num_zonas; i++) {
        if (zonas[i].co2 > 400 || zonas[i].so2 > 0.05 || 
            zonas[i].no2 > 0.06 || zonas[i].pm25 > 25) {
            printf("Recomendaciones para la zona de %s: Reducir trafico, cerrar industrias, suspender actividades al aire libre.\n", zonas[i].nombre);
        }
    }
    printf("-----------------------------------\n");
}
void guardarDatosEnArchivo(ZonaContaminacion zonas[], int num_zonas) {
    FILE *archivo = fopen("datos_contaminacion.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar los datos\n");
        return;
    }
    for (int i = 0; i < num_zonas; i++) {
        fprintf(archivo, "Zona %s: CO2: %.2f SO2: %.2f NO2: %.2f PM2.5: %.2f Temp: %.2f Viento: %.2f Humedad: %.2f\n",
                zonas[i].nombre, zonas[i].co2, zonas[i].so2, zonas[i].no2, zonas[i].pm25,
                zonas[i].temperatura, zonas[i].viento, zonas[i].humedad);
    }
    fclose(archivo);
}
void leerDatosDeArchivo(ZonaContaminacion zonas[], int num_zonas) {
    FILE *archivo = fopen("datos_contaminacion.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para leer los datos\n");
        return;
    }
    for (int i = 0; i < num_zonas; i++) {
        fscanf(archivo, "Zona %s: CO2: %f SO2: %f NO2: %f PM2.5: %f Temp: %f Viento: %f Humedad: %f\n", 
               zonas[i].nombre, &zonas[i].co2, &zonas[i].so2, &zonas[i].no2, &zonas[i].pm25,
               &zonas[i].temperatura, &zonas[i].viento, &zonas[i].humedad);
    }
    fclose(archivo);
}
