// Representa la conexión vía Satélite (Antena -> Satélite)
class SatelliteModule : public ICommunication {
public:
    bool connect() override {
        // Lógica para apuntar antena y handshake con satélite
        return true; 
    }
    void sendData(const std::string& data) override { /* Uplink */ }
    std::string receiveData() override { return "Datos de órbita"; }
};

// Representa conexiones locales
class LocalWirelessModule : public ICommunication {
    bool isBluetooth;
public:
    LocalWirelessModule(bool bluetooth) : isBluetooth(bluetooth) {}
    bool connect() override { /* Pairing o conexión SSID */ return true; }
    void sendData(const std::string& data) override { /* Broadcast */ }
    std::string receiveData() override { return "Sensor data"; }
};
