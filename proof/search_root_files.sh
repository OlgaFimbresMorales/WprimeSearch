#!/bin/bash

# Verificamos que se hayan proporcionado dos argumentos: archivo de entrada y archivo de salida
if [ $# -ne 2 ]; then
    echo "Uso: $0 <ruta_archivo_entrada.txt> <ruta_archivo_salida.txt>"
    exit 1
fi

archivo_entrada=$PWD/"$1"
archivo_salida="$2"

# Verificar si el archivo de entrada existe
if [ ! -f "$archivo_entrada" ]; then
    echo "El archivo de entrada no existe: $archivo_entrada"
    exit 1
fi

# Limpiar archivo de salida si existe
> "$archivo_salida"

# Iterar sobre las líneas del archivo de entrada
while IFS= read -r ruta; do
    # Asegurarnos de que la ruta comience con 'root://'
    if [[ $ruta == /* ]]; then
        # Usar xrdfs para listar el contenido de la ruta
        directorios=$(xrdfs root://cms-xrd-global.cern.ch/"$ruta" ls)
        
        # Comprobar si algún archivo en el directorio es un archivo .root
        for dir in $directorios; do
            if [[ $dir == *.root ]]; then
                # Si encuentra un archivo .root, agregar el directorio al archivo de salida
                dir_path=$(dirname "$ruta/$dir")
                echo "$dir_path" >> "$archivo_salida"
                break
            fi
        done
    fi
done < "$archivo_entrada"

echo "Proceso terminado. Los directorios con archivos .root se han guardado en $archivo_salida."
