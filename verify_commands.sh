#!/bin/bash

HSH_PATH="/root/holbertonschool-simple_shell/hsh"  # Reemplaza con la ruta real de tu ejecutable hsh

if [ ! -x "$HSH_PATH" ]; then
    echo "ERROR: El ejecutable hsh no es válido o no tiene permisos de ejecución."
    exit 1
fi

echo "Verificando comandos ejecutables por hsh..."

for cmd in /bin/*; do
    if [ -x "$cmd" ]; then
        echo -n "Ejecutando '$cmd' en hsh... "
        echo "echo $cmd" | "$HSH_PATH" > /dev/null 2>&1
        if [ $? -eq 0 ]; then
            echo "OK"
        else
            echo "Error"
        fi
    fi
done

echo "Verificación completa."

