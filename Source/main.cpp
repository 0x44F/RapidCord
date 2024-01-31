#include "discord.hpp"
#include "common.hpp"
// Function to check a single bot token
bool checkBotToken(const std::string& token, const std::string& apiUrl, const std::vector<std::string>& proxies) {
    cpr::Parameters parameters{{"token", token}};

    // Use a random proxy if provided
    if (!proxies.empty()) {
        cpr::Proxies proxy{{"http", proxies[std::rand() % proxies.size()]}};
        auto response = cpr::Get(cpr::Url{apiUrl}, cpr::Parameters{parameters}, cpr::Proxies{proxy});
    } else {
        auto response = cpr::Get(cpr::Url{apiUrl}, cpr::Parameters{parameters});
    }

    return response.status_code == 200;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <token_file> [proxy_file]\n";
        return 1;
    }

    std::ifstream tokenFile(argv[1]);
    if (!tokenFile.is_open()) {
        std::cerr << "Error opening token file: " << argv[1] << "\n";
        return 1;
    }

    std::vector<std::string> tokens;
    std::string token;
    while (std::getline(tokenFile, token)) {
        tokens.push_back(token);
    }
    tokenFile.close();

    std::vector<std::string> proxies;
    if (argc == 3) {
        std::ifstream proxyFile(argv[2]);
        if (proxyFile.is_open()) {
            std::string proxy;
            while (std::getline(proxyFile, proxy)) {
                proxies.push_back(proxy);
            }
            proxyFile.close();
        } else {
            std::cerr << "Error opening proxy file: " << argv[2] << "\n";
        }
    }

    std::string apiUrl = "https://discord.com/api/v9/users/@me";

    // Check each bot token
    for (const auto& token : tokens) {
        bool isValid = checkBotToken(token, apiUrl, proxies);
        std::cout << "Token: " << token << " is " << (isValid ? "valid" : "invalid") << "\n";
    }

    return 0;
}
