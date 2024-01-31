#include "common.hpp"

#ifndef DISCORD_HPP
#define DISCORD_HPP

#include <string>
#include <vector>
#include <cpr/cpr.h>

namespace Discord {

    namespace API {

        bool checkBotToken(const std::string& token, const std::string& apiUrl, const std::vector<std::string>& proxies) {
            // Implement the logic for checking a bot token (similar to the previous pseudocode)
            // ...

            return true; // Replace with actual implementation
        }

    } // namespace API

    namespace Bot {

        std::vector<std::string> readTokensFromFile(const std::string& filename) {
            std::vector<std::string> tokens;
            std::ifstream tokenFile(filename);
            if (tokenFile.is_open()) {
                std::string token;
                while (std::getline(tokenFile, token)) {
                    tokens.push_back(token);
                }
                tokenFile.close();
            } else {
                std::cerr << "Error opening token file: " << filename << "\n";
            }
            return tokens;
        }

        std::vector<std::string> readProxiesFromFile(const std::string& filename) {
            std::vector<std::string> proxies;
            std::ifstream proxyFile(filename);
            if (proxyFile.is_open()) {
                std::string proxy;
                while (std::getline(proxyFile, proxy)) {
                    proxies.push_back(proxy);
                }
                proxyFile.close();
            } else {
                std::cerr << "Error opening proxy file: " << filename << "\n";
            }
            return proxies;
        }

        void displayTokenValidity(const std::string& token, bool isValid) {
            std::cout << "Token: " << token << " is " << (isValid ? "valid" : "invalid") << "\n";
        }

    } // namespace Bot

} // namespace Discord
