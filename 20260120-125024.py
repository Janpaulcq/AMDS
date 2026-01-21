class ICommunication {
public:
    virtual ~ICommunication() {}
    virtual bool connect() = 0;
    virtual void sendData(const std:string& data) = 0;
    virtual std::string receiveData() = 0;
};
