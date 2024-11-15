import sys
import os

# Agrega el directorio 'proto' al sys.path
sys.path.append(os.path.join(os.path.dirname(__file__), '../protos'))

import grpc
import fecha_pb2
import fecha_pb2_grpc

def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = fecha_pb2_grpc.FechaServiceStub(channel)

        # Llamada al método SiguienteFecha
        fecha = fecha_pb2.Fecha(dia=14, mes=11, anio=2024)  # Año bisiesto
        response = stub.SiguienteFecha(fecha_pb2.FechaRequest(fecha=fecha))
        print("Fecha siguiente:", response.fecha.dia, response.fecha.mes, response.fecha.anio)

        # Llamada al método SumaDiasFecha
        fecha = fecha_pb2.Fecha(dia=14, mes=11, anio=2024)  # Año bisiesto
        dias_para_sumar = 3
        response = stub.SumaDiasFecha(fecha_pb2.SumaDiasRequest(fecha=fecha, dias=dias_para_sumar))
        print(f"Fecha después de sumar {dias_para_sumar} días:", response.fecha.dia, response.fecha.mes, response.fecha.anio)

if __name__ == '__main__':
    run()