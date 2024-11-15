import sys
import os

# Agrega el directorio 'proto' al sys.path
sys.path.append(os.path.join(os.path.dirname(__file__), '../protos'))

import grpc
from concurrent import futures
import math
import tiro_pb2
import tiro_pb2_grpc

class TiroAlBlancoServicer(tiro_pb2_grpc.TiroAlBlancoServicer):
    def __init__(self):
        self.centro_diana = 100.0  # Ejemplo: el centro de la diana está a 100 metros
        self.mejor_disparo = None
        self.mejor_usuario = ""

    def DimeCentroDiana(self, request, context):
        return tiro_pb2.CentroResponse(distancia=self.centro_diana)

    def DisparaCannon(self, request, context):
        # Calcular la distancia usando el ángulo y la velocidad
        g = 9.81  # gravedad
        distancia = (request.velocidad ** 2) * math.sin(2 * request.angulo) / g
        distancia_al_centro = self.centro_diana - distancia

        # Actualizar el mejor disparo si es el más cercano
        if self.mejor_disparo is None or abs(distancia_al_centro) < abs(self.mejor_disparo):
            self.mejor_disparo = distancia_al_centro
            self.mejor_usuario = request.usuario

        return tiro_pb2.DisparoResponse(distancia_al_centro=distancia_al_centro)

    def MejorDisparo(self, request, context):
        return tiro_pb2.MejorDisparoResponse(usuario=self.mejor_usuario, distancia=self.mejor_disparo)

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    tiro_pb2_grpc.add_TiroAlBlancoServicer_to_server(TiroAlBlancoServicer(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    print("Servidor de Tiro al Blanco iniciado en el puerto 50051")
    server.wait_for_termination()

if __name__ == '__main__':
    serve()
