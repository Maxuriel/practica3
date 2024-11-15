import sys
import os

# Agrega el directorio 'proto' al sys.path
sys.path.append(os.path.join(os.path.dirname(__file__), '../protos'))

import grpc
from concurrent import futures
from datetime import date, timedelta
import fecha_pb2
import fecha_pb2_grpc

class FechaServiceServicer(fecha_pb2_grpc.FechaServiceServicer):
    def SiguienteFecha(self, request, context):
        # Extraer la fecha del request
        dia, mes, anio = request.fecha.dia, request.fecha.mes, request.fecha.anio
        # Crear un objeto date y sumar un día
        fecha_actual = date(anio, mes, dia)
        fecha_siguiente = fecha_actual + timedelta(days=1)
        # Devolver la respuesta
        return fecha_pb2.FechaResponse(
            fecha=fecha_pb2.Fecha(dia=fecha_siguiente.day, mes=fecha_siguiente.month, anio=fecha_siguiente.year)
        )

    def SumaDiasFecha(self, request, context):
        # Extraer la fecha y los días del request
        dia, mes, anio = request.fecha.dia, request.fecha.mes, request.fecha.anio
        dias_para_sumar = request.dias
        # Crear un objeto date y sumar los días
        fecha_actual = date(anio, mes, dia)
        fecha_resultante = fecha_actual + timedelta(days=dias_para_sumar)
        # Devolver la respuesta
        return fecha_pb2.FechaResponse(
            fecha=fecha_pb2.Fecha(dia=fecha_resultante.day, mes=fecha_resultante.month, anio=fecha_resultante.year)
        )

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    fecha_pb2_grpc.add_FechaServiceServicer_to_server(FechaServiceServicer(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    print("Servidor de Fecha iniciado en el puerto 50051")
    server.wait_for_termination()

if __name__ == '__main__':
    serve()