import sys
import os

# Agrega el directorio 'proto' al sys.path
sys.path.append(os.path.join(os.path.dirname(__file__), '../protos'))

import grpc
import tiro_pb2
import tiro_pb2_grpc
import math

def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = tiro_pb2_grpc.TiroAlBlancoStub(channel)

        # Obtener la distancia al centro de la diana
        centro_response = stub.DimeCentroDiana(tiro_pb2.CentroRequest())
        print("Distancia al centro de la diana:", centro_response.distancia)

        usuario = "jugador1"
        
        while True:
            # Pedir ángulo y velocidad al usuario
            angulo_grados = float(input("Ingresa el ángulo de disparo en grados: "))
            velocidad = float(input("Ingresa la velocidad de disparo en m/s: "))
            
            # Convertir el ángulo a radianes
            angulo = math.radians(angulo_grados)
            
            # Realizar el disparo
            disparo_response = stub.DisparaCannon(tiro_pb2.DisparoRequest(usuario=usuario, angulo=angulo, velocidad=velocidad))
            print(f"Distancia al centro después del disparo: {disparo_response.distancia_al_centro:.2f} metros")

            # Verificar si el disparo fue cercano al centro
            if abs(disparo_response.distancia_al_centro) <= 1.0:
                print("¡Acertaste al centro de la diana!")
                break
            else:
                print("Inténtalo de nuevo para acercarte al centro de la diana.")

        # Obtener el mejor disparo
        mejor_disparo_response = stub.MejorDisparo(tiro_pb2.MejorDisparoRequest())
        print(f"Mejor disparo realizado por {mejor_disparo_response.usuario} a {mejor_disparo_response.distancia:.2f} metros del centro.")

if __name__ == '__main__':
    run()