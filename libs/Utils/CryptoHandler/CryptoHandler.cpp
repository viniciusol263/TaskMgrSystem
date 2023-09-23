#include <memory>
#include <iostream>

#include "CryptoHandler.h"

#include "cryptopp/filters.h"
#include "cryptopp/sha.h"
#include "cryptopp/base64.h"
#include "fmt/format.h"

std::string CryptoHandler::GenerateSHA256(std::string message)
{
    std::string digest;
    std::string digestReturn;

    CryptoPP::SHA256 hash;
    CryptoPP::StringSource obj(message, true, new CryptoPP::HashFilter(hash, new CryptoPP::StringSink(digest)));
    
    for(const auto& elem : digest) digestReturn += fmt::format("{:x}", elem);

    return digestReturn;
}
