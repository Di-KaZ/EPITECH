#include <string>
class RegisteredClient {
    public:
        RegisteredClient(const std::string &name, const std::string &ip, int id);
        ~RegisteredClient();
        const std::string &getName() const;
        const std::string &getIp() const;
        int getId() const;
    private:
        std::string &_name;
        std::string &_ip;
        int _id;
};