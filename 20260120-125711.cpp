enum class SatelliteBand { 
    S_BAND, // Para telemetría y comandos (ISS)
    KU_BAND, // Para video de alta definición y datos científicos
    KA_BAND  // Comunicaciones de ultra alta velocidad (Tiangong/Starlink)
};

class OrbitalTransceiver : public IUniversalHardware {
private:
    SatelliteBand activeBand;
public:
    void setBand(SatelliteBand band) { activeBand = band; }

    void transmit(const UniversalPacket& packet) override {
        // Algoritmo de encapsulación para espacio profundo
        std::cout << "Transmitiendo a Estación Espacial en Banda " 
                  << (int)activeBand << ": " << packet.payload << std::endl;
    }
    
    // El resto de funciones obligatorias de tu Interfaz Universal...
    bool initialize() override { return true; }
    UniversalPacket receive() override { return {"ISS", "EARTH", "Status: OK", 1}; }
    std::string getStatus() override { return "Antenna Aligned with ISS"; }
};
