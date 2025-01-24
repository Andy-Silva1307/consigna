#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct {
    char nombre[50];
    float co2;
    float so2;
    float no2;
    float pm25;
    float temperatura;
    float viento;
    float humedad;
} ZonaContaminacion;

void obtenerDatosContaminacion(ZonaContaminacion zonas[], int num_zonas);
void calcularPromedioContaminacion(ZonaContaminacion zonas[], int num_zonas);
void predecirContaminacion(ZonaContaminacion zonas[], int num_zonas);
void emitirAlertas(ZonaContaminacion zonas[], int num_zonas);
void generarRecomendaciones(ZonaContaminacion zonas[], int num_zonas);
void guardarDatosEnArchivo(ZonaContaminacion zonas[], int num_zonas);
void leerDatosDeArchivo(ZonaContaminacion zonas[], int num_zonas);

#endif 
