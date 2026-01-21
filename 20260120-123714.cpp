class SystemController {
private:
    SatelliteModule satMod;
    LocalWirelessModule wifiMod{false};
    AICore aiBrain;

public:
    void synchronize() {
        if(wifiMod.connect()) {
            std::string localData = wifiMod.receiveData();
            std::string processed = aiBrain.processSignal(localData);
            
            if(satMod.connect()) {
                satMod.sendData(processed);
            }
        }
    }
};
