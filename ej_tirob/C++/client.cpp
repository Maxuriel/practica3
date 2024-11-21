#include <grpcpp/grpcpp.h>
#include <iostream>
#include <cmath>
#include "tiro.grpc.pb.h"
#include "tiro.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using tiro::TiroAlBlanco;
using tiro::CentroRequest;
using tiro::CentroResponse;
using tiro::DisparoRequest;
using tiro::DisparoResponse;
using tiro::MejorDisparoRequest;
using tiro::MejorDisparoResponse;

class TiroAlBlancoClient {
public:
    TiroAlBlancoClient(std::shared_ptr<Channel> channel)
        : stub_(TiroAlBlanco::NewStub(channel)) {}

    float DimeCentroDiana() {
        CentroRequest request;
        CentroResponse response;
        ClientContext context;

        Status status = stub_->DimeCentroDiana(&context, request, &response);
        if (status.ok()) {
            return response.distancia();
        } else {
            std::cerr << "Error: " << status.error_message() << std::endl;
            return -1.0f;
        }
    }

    float DisparaCannon(const std::string& usuario, float angulo, float velocidad) {
        DisparoRequest request;
        request.set_usuario(usuario);
        request.set_angulo(angulo);
        request.set_velocidad(velocidad);

        DisparoResponse response;
        ClientContext context;

        Status status = stub_->DisparaCannon(&context, request, &response);
        if (status.ok()) {
            return response.distancia_al_centro();
        } else {
            std::cerr << "Error: " << status.error_message() << std::endl;
            return -1.0f;
        }
    }

    void MejorDisparo() {
        MejorDisparoRequest request;
        MejorDisparoResponse response;
        ClientContext context;

        Status status = stub_->MejorDisparo(&context, request, &response);
        if (status.ok()) {
            std::cout << "Mejor disparo realizado por " << response.usuario()
                      << " a " << response.distancia() << " metros del centro."
                      << std::endl;
        } else {
            std::cerr << "Error: " << status.error_message() << std::endl;
        }
    }

private:
    std::unique_ptr<TiroAlBlanco::Stub> stub_;
};

int main() {
    TiroAlBlancoClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

    float centro = client.DimeCentroDiana();
    if (centro >= 0.0f) {
        std::cout << "Distancia al centro de la diana: " << centro << " metros" << std::endl;

        std::string usuario = "jugador1";
        while (true) {
            std::cout << "Ingresa el ángulo de disparo en grados: ";
            float angulo_grados;
            std::cin >> angulo_grados;

            std::cout << "Ingresa la velocidad de disparo en m/s: ";
            float velocidad;
            std::cin >> velocidad;

            float angulo_radianes = angulo_grados * M_PI / 180.0f;
            float distancia_al_centro = client.DisparaCannon(usuario, angulo_radianes, velocidad);

            if (distancia_al_centro >= -1.0f && distancia_al_centro <= 1.0f) {
                std::cout << "¡Acertaste al centro de la diana!" << std::endl;
                break;
            } else {
                std::cout << "Distancia al centro después del disparo: " << distancia_al_centro << " metros" << std::endl;
            }
        }

        client.MejorDisparo();
    }

    return 0;
}
